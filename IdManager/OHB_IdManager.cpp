//
//  OHB_IdManager.cpp
//
//  Created by Cihan Ozer on 26/02/2018.
//

#include "OHB_IdManager.hpp"

OHB_IdManager::OHB_IdManager()
{
    mId = 0;
}

OHB_IdManager& OHB_IdManager::getInstance()
{
    static OHB_IdManager instance;
    return instance;
}

OHB_IdManager::~OHB_IdManager()
{
    clear();
}

void OHB_IdManager::clear()
{
    std::queue<int> empty;
    std::swap( mAvailableIds, empty );
}

int OHB_IdManager::getNextId()
{
    int nextId = mId;
    if( !mAvailableIds.empty() )
    {
        nextId = mAvailableIds.front();
        mAvailableIds.pop();
    }
    else
    {
        mId++;
    }
    return nextId;
}

void OHB_IdManager::giveIdBack(const int pUsedId)
{
    mAvailableIds.push(pUsedId);
}
