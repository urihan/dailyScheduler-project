#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
using namespace std;
#include "dailySchedule.hpp"


timeSlot::timeSlot(){

  for(int i; i<boolArray[maxsize];i++){
    boolArray[i]=true;
  }

}

void timeSlot::storeInfo(timeInfo slot)
{
  cout << "Here is your schedule for today!" << endl;
  cout<< "At "<< slot.startHours << ":" << slot.startMins << slot.ampm << ", you have: " << slot.event << endl;
}

string gettingKey(timeInfo slot){
  // function that fills in the array with the correct time interval
  //getting the inputs

  int stHrs = slot.startHours;
  string sstHrs = to_string(stHrs);

  int stMins = slot.startMins;
  string sstMins = to_string(stMins);

  int endHrs = slot.endHours;
  string sendHrs = to_string(endHrs);

  int endMins = slot.endMins;
  string sendMins = to_string(endMins);
  // int ampmvalue = ampmcalculation(slot);

  string key = sstHrs+sstMins+sendHrs+sendMins;
  return key;
  // this key value gives the total hour and
  // mins converted to strings
}


int gettingValue(timeInfo slot){
  string key = gettingKey(slot);
  int maxsize;
  bool boolArray[maxsize];

  int i=0;
  if(key=="08000830")
    return boolArray[i];
  else if(key=="08300900")
    return boolArray[i+1];
  else if(key=="09000930")
    return boolArray[i+2];
  else if(key=="090301000")
    return boolArray[i+3];
  else if(key=="10001030")
    return boolArray[i+4];
  else if(key=="10301100")
    return boolArray[i+5];
  else if(key=="11001130")
    return boolArray[i+6];

    else
    {
      return 1;
    }

  }

  // int value = stoi(key);
  // return value;


void timeSlot::hashfunction(timeInfo slot, string fkey, int fvalue){
  fkey = gettingKey(slot);
  fvalue = gettingValue(slot);
  cout << fkey << ":" << fvalue << endl;

}


bool timeSlot::scheduleArray(timeInfo slot)
{
  bool empty = true;
  for(int i; i<boolArray[maxsize]; i++)
  {
    boolArray[i]=empty;
    if(!empty)
    {
      cout <<"you have a schedule" << endl;
      empty = false;
      boolArray[i]=empty;
      string key = gettingKey(slot);
    }
  }
  return empty;
}




// int ampmCalculation(timeInfo slot){
//   //need to continue::
//   //pm calculation:
//   pm = (slot.startHours+11)-12;
//
//   if(pm==0)
//   {
//     return pm;
//   }
//   return pm;
//
// }



// void timeSlot::mainMenu(){}

int main()
{

  ofstream user_scheduler("user_scheduler.txt");

  //timeSlot t;
  // t.storeInfo(8,30,"am","Physics");
  // t.storeInfo(10,30,"am","Chemistry");
  string input;
  string name;
  string startTime1;
  string startTime2;
  string endTime1;
  string endTime2;
  string appointment;
  string ampm;

  cout << "Welcome to your daily scheduler! " <<endl; //put in line 1 name of person
  cout <<"Enter your name: " <<endl;
  getline(cin, name);
  user_scheduler <<"Name: " <<name <<endl;
  cout << " ------------- Main Menu ------------- " <<endl;
  cout << "1. Enter Info " <<endl;
  cout << "2. View Schedule " <<endl;
  cout << "3. Get Recommendations " <<endl;
  cout << "4. Quit" <<endl;


  while (input != "4")
  {
    getline(cin, input); //maybe use getline instead?
    if (input != "1" && input != "2" && input != "3" && input != "4")
    {
      cout <<"Invalid Input! Please enter 1, 2, 3, or 4 to quit. \n Thank you!" <<endl;
    }
    if (input == "1")
    {
      cout <<"Welcome, " <<name <<"." <<endl;
      cout <<"Please enter your schedule: " <<endl;
      cout <<"What time (hours) is your appointment? " <<endl;
      getline(cin, startTime1);
      user_scheduler <<"Start Time(hours): " <<startTime1 <<endl;

      cout <<"What time (minutes) is your appointment? " <<endl;
      getline(cin, startTime2);

      user_scheduler <<"Start Time(minutes): " <<startTime2 <<endl;

      cout <<"What time (hours) does your appointment end? " <<endl;
      getline(cin, endTime1);

      user_scheduler <<"End Time(hours): " <<endTime1 <<endl;

      cout <<"What time minutes) does your appointment end? " <<endl;
      getline(cin, endTime2);

      user_scheduler <<"End Time(minutes): " <<endTime2 <<endl;

      cout <<"Is it in the morning or afternoon? (Enter am/pm) " <<endl;
      getline(cin, ampm);

      user_scheduler <<"AM/PM " <<ampm <<endl;

      cout <<"What do you have scheduled at " <<startTime1 <<":" <<startTime2 <<ampm <<" ?" <<endl;
      getline(cin, appointment);

      user_scheduler <<"Appointment: " <<appointment <<endl;

    //   t.list->startHours = stoi(startTime1);
    //   t.list->startMins = stoi(startTime2);
    //   t.list->endHours = stoi(endTime1);
    //   t.list->endMins = stoi(endTime2);
    //   t.list->event = appointment;
    //   t.list->ampm = ampm;
    //
    //   t.storeInfo(t.list);
    //   t.enqueue(t.list);
    //
    // }
    // if (input == "2")
    // {
    //   cout <<"Welcome, " <<name <<"." <<endl;
    //   cout <<" ------------- Schedule ------------- " <<endl;
    //   t.storeInfo(t.list);
      //t.storeInfo(8,30,"am","Physics");
      //t.storeInfo(10,30,"am","Chemistry");
    }//SEG FAULTS HERE -----------
    // if (input == "3")
    // {
    //   cout <<"Your freetime: " <<endl;
    //   t.freeTime(t.list);
    // }
  }

}









// int main()
// {
//
//
//   User user1;
//   string name;
//   list<timeSlot> events;
//   name=user1.username;
//   events=user1.allEvents;
//
//   timeSlot t;
//   timeInfo slot;
//
//   string input;
//   string startTime1;
//   string startTime2;
//   string endTime1;
//   string endTime2;
//   string appointment;
//   string ampm;
//
//   cout << "Welcome to your daily scheduler! " <<endl; //put in line 1 name of person
//   cout <<"Enter your name: " <<endl;
//   getline(cin, name);
//   cout << " ------------- Main Menu ------------- " <<endl;
//   cout << "1. Enter Info " <<endl;
//   cout << "2. View Schedule " <<endl;
//   cout << "3. Get Recommendations " <<endl;
//   cout << "4. Quit" <<endl;
//
//      //maybe use getline instead?
//
//   while(input != "4")
//   {
//     getline(cin, input);
//     if (input != "1" && input != "2" && input != "3" && input != "4")
//     {
//       cout <<"Invalid Input! Please enter 1, 2, 3, or 4 to quit. \n Thank you!" <<endl;
//     }
//
//     if (input == "1")
//     {
//       cout <<"Welcome, " <<name <<"." <<endl;
//       cout <<"Please enter your schedule: " <<endl;
//       cout <<"What time (hours) is your appointment? " <<endl;
//       getline(cin, startTime1);
//       cout <<"What time (minutes) is your appointment? " <<endl;
//       getline(cin, startTime2);
//       cout <<"What time (hours) does your appointment end? " <<endl;
//       getline(cin, endTime1);
//       cout <<"What time minutes) does your appointment end? " <<endl;
//       getline(cin, endTime2);
//       cout <<"Is it in the morning or afternoon? (Enter am/pm) " <<endl;
//       getline(cin, ampm);
//       cout <<"What do you have scheduled at " <<startTime1 <<":" <<startTime2 <<ampm <<" ?" <<endl;
//       getline(cin, appointment);
//       // cout<<"yuri"<<endl;
//
//       t.slot.startHours = stoi(startTime1);
//       t.slot.startMins = stoi(startTime2);
//       t.slot.endHours = stoi(endTime1);
//       t.slot.endMins = stoi(endTime2);
//       t.slot.event = appointment;
//       t.slot.ampm = ampm;
//
//
//       // t.storeInfo(t.slot);
//
//       cout <<"Is that all for today? (y/n)" << endl;
//       break;
//       // need to return to the menu
//     }
//
//     else if (input == "2")
//     {
//       cout <<"Welcome, " <<name <<"." <<endl;
//       cout <<" ------------- Schedule ------------- " <<endl;
//       t.storeInfo(t.slot);
//     }
//
//     // t.scheduleArray(slot);
//   }
//
//
//
//   //
//   // bool empty;
//   // // t.storeInfo(slot);
//   // t.scheduleArray(empty);
//
//
// }
