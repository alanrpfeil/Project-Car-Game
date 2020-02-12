#ifndef finishLine_h
#define finishLine_h
#include "Obstacle.h"

class finishLine : public Obstacle {

public:
	finishLine(const char* map_filename = "../finish_line.png", float x = -1.0, float y = 1.35, float w = 2.0, float h = 0.35) : Obstacle(map_filename, x, y, w, h) {}

	void startMovement() {
		animating = true;
	}

	void moveFinish() {
		startMovement();
	}



};

#endif