#include "Observer.hpp"

void Observer::init(Subject *pSubject, const int pId)
{
    mSubject = pSubject;
    mId = pId;
}
