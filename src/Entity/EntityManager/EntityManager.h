#pragma once
#include "../EntityType/EntityType.h"
#include <queue>
#include <iostream>
#include <unordered_map>

class EntityManager
{
private:
    std::queue<uint32_t> available;
    std::unordered_map<EntityType, uint16_t> counters;

public:
    uint32_t getNewID(EntityType type);
    static EntityManager& getInstance() {
        static EntityManager instance;
        return instance;
    }

    void freeID(uint32_t ID);
};