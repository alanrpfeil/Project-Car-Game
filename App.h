#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"
#include "../visualc15/Obstacle.h"
#include "../visualc15/finishLine.h"
#include "../visualc15/intro.h"
#include "../visualc15/gameover.h"
#include "../visualc15/gamewon.h"
#include <vector>
#include <ctime>
#include <cstdlib>


class App: public GlutApp {
	float mx;
	float my;

	AnimatedRect* explosion;

	car* selectedCar;
	introduction* intro;

	TexRect* background;

	std::vector<Obstacle*> barrels;
	finishLine* finish;

	Game_Over* gameover;
	Game_Won* gamewon;

	clock_t startTime;
	clock_t endTime;
	float elapsedTime;
	bool used;
	bool used2;
	float accelcounter;
	float accelcountamount;

public:
    App(int argc, char** argv);
    
    void draw();

	void idle();
    
    void keyDown(unsigned char key, float x, float y);
	void leftMouseDown(float x, float y);
    
    ~App();
    
};

#endif
