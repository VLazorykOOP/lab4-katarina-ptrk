#include "busschedule.h"

BusSchedule::BusSchedule(int initialCapacity) {
  journeys = new Journey[initialCapacity];
  size = 0;
  capacity = initialCapacity;
  errorCode = 0;
}

BusSchedule::~BusSchedule() {}

void BusSchedule::add(unsigned int number, std::string time) {
  if (size == capacity) {
    resize(capacity * 2);
  }
  journeys[size].number = number;
  journeys[size].time = time;
  size++;
}

std::string BusSchedule::operator[](unsigned int number) {
  for (int i = 0; i < size; i++) {
    if (journeys[i].number == number) {
      return journeys[i].time;
    }
  }
  errorCode = 1;
  return "-";
}

unsigned int BusSchedule::operator[](std::string time) {
  for (int i = 0; i < size; i++) {
    if (journeys[i].time == time) {
      return journeys[i].number;
    }
  }
  errorCode = 1;
  return 0;
}

int BusSchedule::getErrorCode() const { return errorCode; }

void BusSchedule::resetErrorCode() { errorCode = 0; }

std::ostream &operator<<(std::ostream &os, const BusSchedule &schedule) {
  for (int i = 0; i < schedule.size; i++) {
    os << "Bus #" << schedule.journeys[i].number << " departs at "
       << schedule.journeys[i].time << std::endl;
  }
  return os;
}
std::istream &operator>>(std::istream &is, BusSchedule &schedule) {
  unsigned int number;
  std::string time;
  while (is >> number >> time) {
    schedule.add(number, time);
  }
  return is;
}
