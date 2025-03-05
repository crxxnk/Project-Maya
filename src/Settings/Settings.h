#pragma once
#include <cstdint>

struct Settings {
	bool FULLSCREEN = false;
	bool VSYNC = false;
	uint16_t MAX_FPS = 60;

	// Scene Settings
	uint16_t MAX_SCENE_OBJECTS = 5000;
	uint16_t MAX_LIGHTS = 300;

	// Physics Settings
	bool ENABLE_PHYSICS = true;
	float FIXED_TIMESTEP = 0.016f;
	float GRAVITY = -9.81f;
	float DRAG = 0.1f;                  // Drag value for physics simulation (for objects)
	float BOUNCE = 0.5f;                // Bounciness of objects during collisions (0 to 1)
	float FRICTION = 0.8f;              // Friction for physical objects (0 to 1)
	bool USE_2D_PHYSICS = false;		// Whether to use 2D or 3D physics

	// Graphics Settings
	bool ENABLE_MSAA = true;
	uint8_t MSAA_SAMPLES = 4;
	bool ANTI_ALIASING = true;          // Enable anti-aliasing for smoother edges
	uint16_t MAX_TEXTURE_SIZE = 4096;   // Maximum texture size (helps control memory usage)
	bool ENABLE_SHADOWS = true;         // Enable shadow rendering
	bool ENABLE_BLOOM = false;          // Enable bloom effect (bright light glowing)
	bool ENABLE_POST_PROCESSING = true; // Post-processing effects like blur, sepia
	bool USE_HDR = true;                // High Dynamic Range rendering for better light contrast
	bool ENABLE_FOG = false;            // Enable fog for atmosphere
	float NEAR_CLIP_PLANE = 0.1f;       // Near clipping plane for camera
	float FAR_CLIP_PLANE = 1000.0f;		// Far clipping plane for camera


	// Audio Settings
	bool ENABLE_AUDIO = true;           // Whether audio is enabled
	float MASTER_VOLUME = 1.0f;         // Master volume (0 to 1)
	float MUSIC_VOLUME = 0.7f;          // Volume for background music
	float SOUND_EFFECTS_VOLUME = 0.8f;  // Volume for sound effects
	bool ENABLE_3D_AUDIO = true;        // Enable 3D audio for positional sound
	bool ENABLE_REVERB = true;          // Enable reverb effects for environments
	bool ENABLE_DISTORTION = false;     // Enable distortion effects for sounds
	bool ENABLE_FOOTSTEPS = true;       // Footstep sounds for movement

	// Input Settings
	bool ENABLE_KEYBOARD_INPUT = true;  // Enable keyboard input
	bool ENABLE_MOUSE_INPUT = true;     // Enable mouse input
	bool ENABLE_GAMEPAD_INPUT = true;   // Enable gamepad input

	// Debugging Settings
	bool ENABLE_DEBUG_LOGGING = true;      // Enable debug logging for development
	bool SHOW_FPS_COUNTER = true;          // Show FPS counter in the corner
	bool ENABLE_COLLISION_DEBUG = false;   // Debug collision boundaries visually
};