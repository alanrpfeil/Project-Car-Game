#ifndef Obstacle_h
#define Obstacle_h
#include "TexRect.h"
#include "../visualc15/randomGen.h"
#include "../visualc15/objectDimensions.h"
#include "../visualc15/car.h"

using namespace std;

class Obstacle : public TexRect, protected Timer {
protected:
	int lane;	
	bool spawning;
	unsigned int rpm;
	float acceleration;
	int rpmincr;

	int cycle;
	bool cycleOver;
	int obstacleType; // 4 different types: 1 regular, 2 desert, 3 jungle, 4 ice

	bool animating;

public:

	Obstacle() : TexRect("", 0, 0, 0, 0) {
		changeLane();
		cycle = 0;
		rpm = 0;
		rpmincr = 0;
		obstacleType = 0;
	}

	Obstacle(const char* map_filename, float x = LeftmostThree, float y = 1.35, float w = objWidth, float h = 0.35) : TexRect(map_filename, x, y, w, h) {
		changeLane();
		obstacleType = 1;
		cycle = 0;
		cycleOver = false;
		rpm = 0;
		rpmincr = 90;

		animating = false;
		setRate(16);
		start();
	};

	void setAnimating(bool anim) {
		animating = anim;
	}

	int getCycle() const {
		return cycle;
	}

	bool lastCycle() const {
		return cycleOver;
	}

	void setAcceleration(float accel) {
		acceleration = accel;
	}

	void setrpm(unsigned int RPM) {
		rpm = RPM;
	}

	void setrpmincr(int rpminc) {
		rpmincr = rpminc;
	}

	//----------------------------------------------------------Functions-----------------------------------------------------------------
	virtual void startMovement() {
		if (spawning == true) {
			animating = true;
			Spawn();
		}
	}

	void changeLane() {		// decides what lane the obstacle is in
		lane = getRandom();
		spawning = true;
	}

	

	void Spawn() {
		if (lane == 1) {
			setX(LeftmostOne);
			setY(1.35);
		}
		else if (lane == 2) {
			setX(LeftmostTwo);
			setY(1.35);
		}
		else if (lane == 3) {
			setX(LeftmostThree);
			setY(1.35);
		}
		else if (lane == 4) {
			setX(LeftmostFour);
			setY(1.35);
		}
		else if (lane == 5) {
			setX(LeftmostFive);
			setY(1.35);
		}
		cycle += 1;
		checkCycle();
		spawning = false;
	}

	void Despawn() {
		changeLane();
	}


	void action() {
		if (animating) {
			rpm += rpmincr;
			
				y -= (0.01 + acceleration);
			
			redrawScene();
			if (y <= -1.0) {
				Despawn();
			}
		}
	}

	void checkCycle() {
		if (cycle == 50) {
			cycleOver = true;
		}
	}

	void setImage(char* filename) {
		texture_id = SOIL_load_OGL_texture
		(
			filename,
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	}

	void changeImage() {
		if (cycle == 11) {
			if (obstacleType != 2) {
				setImage("../pixel-cactus.png");
				obstacleType = 2;
			}
		}
		else if (cycle == 21) {
			if (obstacleType != 3) {
				setImage("../pixel-snowman.png");
				obstacleType = 3;
			}
		}
		else if (cycle == 31) {
			if (obstacleType != 4) {
				setImage("../pixel-jungle_barrel.png");
				obstacleType = 4;
			}
		}
		else if (cycle == 41) {
			if (obstacleType != 1) {
				setImage("../pixel-barrel.png");
				obstacleType = 1;
			}
		}		
	}

	unsigned int getrpm() const{
		return rpm;
	}

	bool getHit(float positionX, float positionY) {
		if (contains(positionX + 0.15, positionY)) {
			return true;
		}
		else if (contains(positionX, positionY - 0.4)) {
			return true;
		}
		else if (contains(positionX + 0.30, positionY - 0.4)) {
			return true;
		}
		return false;
	}

};

#endif