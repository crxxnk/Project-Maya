#include "EntityManager.h"

uint32_t EntityManager::getNewID(EntityType type)
{
    if (!available.empty()) {
        uint32_t ID = available.front();
        available.pop();
        std::cout << "Reusing ID: " << std::hex << ID << "\n";
        return ID;
    }

    // Generate new ID by OR-ing the type with the counter
    uint16_t& counter = counters[type];
    uint32_t newID = type | counter++;
    std::cout << "Generated New ID: " << std::hex << newID << "\n";
    return newID;
}

void EntityManager::freeID(uint32_t ID)
{
    available.push(ID);
}