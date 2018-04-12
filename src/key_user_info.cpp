//LIBRERIE
#include <ros/ros.h>
#include <signal.h>
#include <termios.h>
#include <stdio.h>
#include "std_msgs/String.h"
#include <sstream>

//file descriptor (0 = input/tastiera)
int fd = 0;

//strutture utilizzate per l'output su terminale da tastiera 
struct termios cooked, raw;

//gestisce la terminazione con CTRL-C
void quit(int sig)
{
  (void)sig;
  tcsetattr(fd, TCSANOW, &cooked);
  ros::shutdown();
  exit(0);
}


int main(int argc, char** argv)
{
  //inizializzo il nodo
  ros::init(argc, argv, "key_user_info");
  
  ros::NodeHandle n;
  
  //il nodo pubblicherà gli input da tastiera nel topic car_choice
  ros::Publisher pub = n.advertise<std_msgs::String>("car_choice", 1);

  signal(SIGINT,quit);

  char c;

  // imposta  la console in modalità raw                                                               
  tcgetattr(fd, &cooked);
  memcpy(&raw, &cooked, sizeof(struct termios));
  raw.c_lflag &=~ (ICANON | ECHO);
                    
  raw.c_cc[VEOL] = 1;
  raw.c_cc[VEOF] = 2;
  tcsetattr(fd, TCSANOW, &raw);

  puts("Reading from keyboard\n");
  puts("---------------------------\n");
  puts("(a= all, e= eta,n= nome,c= corso di laurea): \n");

  std_msgs::String msg;

  while(ros::ok()){

    //leggo da tastiera
    if(read(fd, &c, 1) < 0)
    {
      perror("read():");
      exit(-1);
    }
    //controllo che il carattere letto sia tra quelli richiesti
    if(c == 'a' || c == 'e' || c == 'n' || c == 'c')
    {
      std::stringstream ss;
      ss << c;
      msg.data = ss.str();
      //pubblico il carattere sul topic
      pub.publish(msg);
    }
  }  
  return(0);
}
