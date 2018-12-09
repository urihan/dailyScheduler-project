#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
using namespace std;


struct timeInfo{
  int startHours;
  int startMins;
  int endHours;
  int endMins;
  string event;
  string ampm;
};


class timeSlot
{
private:

public:
  timeSlot();

  //instance
  timeInfo slot;
  int maxsize;
  bool boolArray[];

  //functions
  void storeInfo(timeInfo slot);
  bool scheduleArray(timeInfo slot);
  int freeTime(timeInfo* slot);
  void conflicts();
  void recommendation();

};

struct User{
  string username;
  list <timeSlot> allEvents;
};
