#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"
#include "../visualc15/Obstacle.h"
#include "../visualc15/intro.h"
#include <vector>


class App: public GlutApp {
	float mx;
	float my;

	car* selectedCar;
	introduction* intro;

	std::vector<Obstacle*> barrels;
	
    
public:
    App(int argc, char** argv);
    
    void draw();

	void idle();
    
    void keyDown(unsigned char key, float x, float y);
	void leftMouseDown(float x, float y);
    
    ~App();
    
};

#endif
