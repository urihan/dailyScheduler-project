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

struct User{
  string username;
  list <timeInfo> allEvents;
};

class timeSlot
{
private:

public:
  timeSlot();
  timeInfo slot;
  void storeInfo(timeInfo* list);
  int freeTime(timeInfo* list);
  void conflicts();
  void recommendation();

};
