#pragma once
#include <string>
class Animator {
protected:
	int framestep;
	float framerate, duration, phase, delay;
	std::string mode, updatemode;
};