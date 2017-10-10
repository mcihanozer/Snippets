// MCO

#ifndef Observer_hpp
#define Observer_hpp

#include "OHB_Event.hpp"

class Subject;

// Base class for Observers
class Observer
{
public:
    
    virtual void init(Subject* pSubject, const int pId);
    virtual void handleNotification(OHB_Event pEvent) = 0;
    
    int mId;
    
protected:
    
    Subject* mSubject;
};

#endif /* Observer_hpp */
