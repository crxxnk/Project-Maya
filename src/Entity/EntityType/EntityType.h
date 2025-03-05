#pragma once
#include <cstdint>

namespace ET {
	enum EntityType : uint32_t
	{
		PLAYER = 0x00010000, // Player ID starts at 0x00010000
		ENEMY = 0x20000000, // Enemies start at 0x20000000
		NPC = 0x30000000  // NPCs start at 0x30000000
	};
}