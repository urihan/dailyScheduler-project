#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
using namespace std;
#include "dailySchedule.hpp"


timeSlot::timeSlot(){

  for(int i; i<8;i++){
    boolArray[i].event = " ";
    boolArray[i].occupied = false;
    boolArray[i].startHours = 0;
    boolArray[i].endHours=0;
    boolArray[i].ampm=" ";
  }

}

  void timeSlot::storeInfo(timeInfo slot)
  {
    cout << "Here is your schedule for today!" << endl;

    for(int i=0; i<8; i++)
    {
      cout<< "At "<< boolArray[i].startHours << ", you have: " << boolArray[i].event << endl;
    }

  }



//
// bool timeSlot::scheduleArray(timeInfo slot)
// {
//   bool empty = true;
//   for(int i; i<8; i++)
//   {
//     boolArray[i]=empty;
//     if(!empty)
//     {
//       cout <<"you have a schedule" << endl;
//       empty = false;
//       boolArray[i]=empty;
//       string key = gettingKey(slot);
//     }
//   }
//   return empty;
// }
//




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

  timeSlot t;
  int i=0;
  // timeInfo slot;

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


  while (input != "4")
  {

    cout << " ------------- Main Menu ------------- " <<endl;
    cout << "1. Enter Info " <<endl;
    cout << "2. View Schedule " <<endl;
    cout << "3. Get Recommendations " <<endl;
    cout << "4. Quit" <<endl;

    getline(cin, input);
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
      if (stoi(startTime1) != 8 || stoi(startTime1) != 9 ||stoi(startTime1) != 10 ||stoi(startTime1) != 11 ||stoi(startTime1) != 12 ||stoi(startTime1) != 1 ||stoi(startTime1) != 2 ||stoi(startTime1) != 3 ||stoi(startTime1) != 4)
      {
        cout <<"Invalid input! Please enter the hour as a whole number (8,9,10).\n";
      }
      user_scheduler <<"Start Time(hours): " <<startTime1 <<endl;

      cout <<"What time (hours) does your appointment end? " <<endl;
      getline(cin, endTime1);
      if (stoi(startTime1) != 8 || stoi(startTime1) != 9 ||stoi(startTime1) != 10 ||stoi(startTime1) != 11 ||stoi(startTime1) != 12 ||stoi(startTime1) != 1 ||stoi(startTime1) != 2 ||stoi(startTime1) != 3 ||stoi(startTime1) != 4)
      {
        cout <<"Invalid input! Please enter the hour as a whole number (8,9,10).\n";
      }

      user_scheduler <<"End Time(hours): " <<endTime1 <<endl;

      user_scheduler <<"AM/PM " <<ampm <<endl;

      cout <<"What do you have scheduled at " <<startTime1 <<ampm <<" ?" <<endl;
      getline(cin, appointment);

      user_scheduler <<"Appointment: " <<appointment <<endl;

        if (stoi(startTime1) == 8)
          {
            i = 0;
          }
          if (stoi(startTime1) == 9)
          {
            i = 1;
          }
          if (stoi(startTime1) == 10)
          {
            i = 2;
          }
          if (stoi(startTime1) == 11)
          {
            i = 3;
          }if (stoi(startTime1) == 12)
          {
            i = 4;
          }
          if (stoi(startTime1) == 1)
          {
            i = 5;
          }
          if (stoi(startTime1) == 2)
          {
            i = 6;
          }
          if (stoi(startTime1) == 3)
          {
            i = 7;
          }
          if (stoi(startTime1) == 4)
          {
            i = 8;
          }

        t.boolArray[i].startHours = stoi(startTime1);
        t.boolArray[i].endHours = stoi(endTime1);
        t.boolArray[i].event = appointment;
        t.boolArray[i].ampm = ampm;
        t.storeInfo(t.boolArray[i]);

    }

    if (input == "2")
    {
      cout <<"Welcome, " <<name <<"." <<endl;
      cout <<" ------------- Schedule ------------- " <<endl;
      t.storeInfo(t.boolArray[i]);

    }

    //SEG FAULTS HERE -----------
    // if (input == "3")
    // {
    //   cout <<"Your freetime: " <<endl;
    //   t.freeTime(t.list);
    // }


}

}
