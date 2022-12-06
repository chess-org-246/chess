#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <iostream>

class Observer;//class forwarding


class Subject {
  std::vector<Observer*> observers;//vector of observers to keep track of which to notify
 public:
  void attach(Observer *o); //attach observers
  void detach(Observer *o); //detach observers
  void notifyObservers(); //notify all the observers 
  virtual char getState(int row, int col, int playerNum) const = 0;
  virtual ~Subject() = default;
};

#endif
