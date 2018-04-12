//LIBRERIE
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <h1_id778tlx/User_info.h>
#include <sstream>
#include <signal.h>

using namespace std;
string choice;

//gestisce la terminazione con CTRL-C
void quit(int sig)
{
  (void)sig;
  ros::shutdown();
  exit(0);
}

//INPUT = messaggio pubblicato sul topic user_info
//OUTPUT = stampa a video il messaggio opportunamente filtrato
void captureUserInfo(const h1_id778tlx::User_info::ConstPtr& msg)
{

  if(choice == "a") {
   ROS_INFO("\n Nome = [%s] \n Eta = [%i] \n Corso di laurea = [%s]\n", msg->nome.c_str(),msg->eta,msg->corso_di_laurea.c_str());
  } else if( choice == "e") {
   ROS_INFO("\n Eta = [%i]\n",msg->eta);
  } else if( choice == "n") {
   ROS_INFO("\n Nome = [%s]\n", msg->nome.c_str());
  } else if( choice == "c"){
   ROS_INFO("\n Corso di laurea = [%s]\n",msg->corso_di_laurea.c_str());
  }
}

//INPUT = messaggio pubblicato sul topic car_choice
//setta la variabile globale choice
void captureKeyboard(const std_msgs::String::ConstPtr& msg){

  choice = msg->data.c_str();
}

int main(int argc, char **argv)
{

  signal(SIGINT,quit);

  ros::init(argc, argv, "l_user_info");

  ros::NodeHandle n;

  //sottoscrivo il nodo al topic user_info
  ros::Subscriber sub = n.subscribe("user_info", 1000, captureUserInfo);
  //sottoscrivo il nodo al topic car_choice
  ros::Subscriber sub2 = n.subscribe("car_choice", 1000, captureKeyboard);

  ros::spin();

  return 0;
}

