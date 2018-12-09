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
      storeInfo(slot);
    }
  }
  cout << empty << endl;
  return empty;
}

string gettingKey(timeInfo slot){
  // function that fills in the array with the correct time interval
  //getting the inputs

  // for (int i; i<boolArray[maxsize];i++)
  // {
  //
  // }

  int stHrs = slot.startHours;
  string sstHrs = to_string(stHrs);

  int stMins = slot.startMins;
  string sstMins = to_string(stMins);

  int endHrs = slot.endHours;
  string sendHrs = to_string(endHrs);

  int endMins = slot.endMins;
  string sendMins = to_string(endMins);

  // int ampmvalue = ampmcalculation(slot);
  //

  string key = sstHrs+sstMins+sendHrs+sendMins;
  return key;

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


int gettingValue(timeInfo slot){
  string key = gettingKey(slot);
  int value = stoi(key);
  return value;
}

void timeSlot::hashfunction(timeInfo slot, string fkey, int fvalue){
  fkey = gettingKey(slot);
  fvalue = gettingValue(slot);
  cout << fkey << ":" << fvalue << endl;

}



// void timeSlot::mainMenu(){}


int main()
{


  User user1;
  string name;
  list<timeSlot> events;
  name=user1.username;
  events=user1.allEvents;

  timeSlot t;
  timeInfo slot;

  string input;
  string startTime1;
  string startTime2;
  string endTime1;
  string endTime2;
  string appointment;
  string ampm;

  cout << "Welcome to your daily scheduler! " <<endl; //put in line 1 name of person
  cout <<"Enter your name: " <<endl;
  getline(cin, name);
  cout << " ------------- Main Menu ------------- " <<endl;
  cout << "1. Enter Info " <<endl;
  cout << "2. View Schedule " <<endl;
  cout << "3. Get Recommendations " <<endl;
  cout << "4. Quit" <<endl;

    getline(cin, input); //maybe use getline instead?

  while(input != "4")
  {
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
      cout <<"What time (minutes) is your appointment? " <<endl;
      getline(cin, startTime2);
      cout <<"What time (hours) does your appointment end? " <<endl;
      getline(cin, endTime1);
      cout <<"What time minutes) does your appointment end? " <<endl;
      getline(cin, endTime2);
      cout <<"Is it in the morning or afternoon? (Enter am/pm) " <<endl;
      getline(cin, ampm);
      cout <<"What do you have scheduled at " <<startTime1 <<":" <<startTime2 <<ampm <<" ?" <<endl;
      getline(cin, appointment);
      // cout<<"yuri"<<endl;

      t.slot.startHours = stoi(startTime1);
      t.slot.startMins = stoi(startTime2);
      t.slot.endHours = stoi(endTime1);
      t.slot.endMins = stoi(endTime2);
      t.slot.event = appointment;
      t.slot.ampm = ampm;


      // t.storeInfo(t.slot);

      cout <<"Is that all for today? (y/n)" << endl;
      break;
      // need to return to the menu
    }

    else if (input == "2")
    {
      cout <<"Welcome, " <<name <<"." <<endl;
      cout <<" ------------- Schedule ------------- " <<endl;
      t.storeInfo(t.slot);
    }

    // t.scheduleArray(slot);
  }



  //
  // bool empty;
  // // t.storeInfo(slot);
  // t.scheduleArray(empty);


}
