#ifndef _OBSERVER_H_
#define _OBSERVER_H_
class Subject;

//observer class
class Observer {
 public:
  virtual void notify() = 0; //notify the observer to change
  virtual ~Observer() = default;
};
#endif
