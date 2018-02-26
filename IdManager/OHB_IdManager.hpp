//
//  OHB_IdManager.hpp
//
//  Created by Cihan Ozer on 26/02/2018.
//

#ifndef OHB_IdManager_hpp
#define OHB_IdManager_hpp

#define IdManager OHB_IdManager::getInstance()

// Helper class for managing given IDs
class OHB_IdManager
{
public:
    
    static OHB_IdManager& getInstance();
    void clear();
    
    int getNextId();
    void giveIdBack(const int pUsedId);
    
private:
    
    OHB_IdManager();
    ~OHB_IdManager();
    
    int mId;
    std::queue<int> mAvailableIds;
};

#endif /* OHB_IdManager_hpp */
