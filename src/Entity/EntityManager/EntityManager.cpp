#include "EntityManager.h"

uint32_t EntityManager::getNewID(ET::EntityType type)
{
    if (!available.empty()) {
        uint32_t ID = available.front();
        available.pop();
        //std::cout << "Reusing ID: " << std::hex << ID << "\n";
        return ID;
    }

    // Generate new ID by OR-ing the type with the counter
    uint32_t& counter = counters[type];
    std::cout << "Type: " << std::hex << static_cast<uint32_t>(type) << ", Counter: " << counter << std::endl;
    uint32_t newID = static_cast<uint32_t>(type) | (counter++);
    std::cout << "Generated New ID: " << std::hex << newID << "\n";
    return newID;
}

void EntityManager::freeID(uint32_t ID)
{
    available.push(ID);
}