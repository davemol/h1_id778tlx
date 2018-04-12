//LIBRERIE
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <h1_id778tlx/User_info.h>
#include <signal.h>

//gestisce la terminazione con CTRL-C
void quit(int sig)
{
  (void)sig;
  ros::shutdown();
  exit(0);
}

int main(int argc, char **argv)
{
  signal(SIGINT,quit);

  ros::init(argc, argv, "t_user_info");

  ros::NodeHandle n;

  //il nodo pubblicherà il messaggio, con struttura predefinita (msg/homework1.msg), sul topic user_info
  ros::Publisher chatter_pub = n.advertise<h1_id778tlx::User_info>("user_info", 1000);

  // 1 secondo = 1Hz
  ros::Rate loop_rate(1);

  while (ros::ok())
  {
    //struttura del messaggio
    h1_id778tlx::User_info msg;

    std::stringstream ss1;
    ss1 << "Davide";	 
    msg.nome = ss1.str();

    msg.eta = 21;
    
    std::stringstream ss2;
    ss2 << "Laurea in Informatica";
    msg.corso_di_laurea = ss2.str();

    //ROS_INFO("Publish:\n nome = [%s] \n eta = [%i] \n corso di laurea = [%s]", msg.nome.c_str(),msg.eta,msg.corso_di_laurea.c_str());
    
    //pubblico il messaggio
    chatter_pub.publish(msg);

    ros::spinOnce();

    //attendo 1 secondo
    loop_rate.sleep();
  }

  return 0;
}
