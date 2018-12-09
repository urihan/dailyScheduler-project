#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
using namespace std;


struct timeInfo{
  int startHours;
  int endHours;
  string event;
  string ampm;
  bool occupied;
  // string startam;
  // string startam;
  // string endam;
  // string endpm;
};
 
class timeSlot
{
private:

public:
  timeSlot();
  // ~timeSlot();

  //instance
  timeInfo slot;
  string fkey;
  int fvalue;
  timeInfo boolArray[8];
  timeInfo eventArray[8];

  //functions
  void storeInfo(timeInfo slot);
  bool scheduleArray(timeInfo slot);


  int freeTime(timeInfo* slot);
  void getRecommendations(int);

};

struct User{
  string username;
  list <timeSlot> allEvents;
};
