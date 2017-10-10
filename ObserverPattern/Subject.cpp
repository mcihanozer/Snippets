// MCO

#include "Subject.hpp"

Subject::Subject()
{
    mId = 0;
}

Subject:: ~Subject()
{
    for(int oi = 0; oi < mObserverList.size(); oi++)
    {
        mObserverList.erase( mObserverList.begin() + oi );
    }
    
    mObserverList.clear();
}

void Subject::attach(Observer *pObserver)
{
    mObserverList.push_back(pObserver);
    pObserver->init(this, mId++);
}

void Subject::detach(Observer* pObs)
{
    for(std::vector<Observer*>::iterator it = mObserverList.begin(); it != mObserverList.end(); it++)
    {
        if(pObs->mId == (*it)->mId)
        {
            mObserverList.erase(it);
            break;
        }
    }
}

void Subject::notify(OHB_Event pEvent)
{
    for(int oi = 0; oi < mObserverList.size(); oi++)
    {
        mObserverList[oi]->handleNotification(pEvent);
    }
}
