#ifndef BUSSCHEDULE_H
#define BUSSCHEDULE_H

#include <cstring>
#include <iostream>

class BusSchedule {
public:
  struct Journey {
    unsigned int number;
    std::string time;
  };

private:
  Journey *journeys;
  int size;
  int capacity;
  int errorCode;

  void resize(int newCapacity) {
    Journey *newJourneys = new Journey[newCapacity];
    for (int i = 0; i < size; i++) {
      newJourneys[i] = journeys[i];
    }
    delete[] journeys;
    journeys = newJourneys;
    capacity = newCapacity;
  }

public:
  BusSchedule(int initialCapacity = 10);
  ~BusSchedule();
  void add(unsigned int number, std::string time);
  std::string operator[](unsigned int number);
  unsigned int operator[](std::string time);
  int getErrorCode() const;
  void resetErrorCode();
  friend std::ostream &operator<<(std::ostream &os,
                                  const BusSchedule &schedule);
  friend std::istream &operator>>(std::istream &is, BusSchedule &schedule);
};

#endif // BUSSCHEDULE_H
