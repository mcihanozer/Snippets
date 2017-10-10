// MCO

#ifndef Subject_hpp
#define Subject_hpp

#include "OHB_Event.hpp"
#include "Observer.hpp"

#include <vector>

// Base class for subjects
class Subject
{
public:
    Subject();
    ~Subject();
    
    void attach(Observer* pObserver);
    void detach(Observer* pObs);
    void notify(OHB_Event pEvent);
    
private:
    
    std::vector<Observer*> mObserverList;
    
    // TODO Handle the id better
    int mId;
};

#endif /* Subject_hpp */
