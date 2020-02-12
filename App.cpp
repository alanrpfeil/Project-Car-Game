#include <iostream>
#include "App.h"
#include <vector>
#include <iostream>
#include "../visualc15/intro.h"

using namespace std;

float explosionX;
float explosionY;
bool animateOnce = false;
bool anotherused = false;

bool gameoverState = false;
bool gamewonState = false;
int gameStatus = 0;		// 1:over, 2:won

App::App(int argc, char** argv) : GlutApp(argc, argv) {

	explosion = new AnimatedRect("../explode_1.png", 4, 4, 100, -0.5, 0.5, 0.5, 0.5);

	selectedCar = new car();
	intro = new introduction();
	background = new TexRect("../5lane.png", -1, 1, 2, 2);

	accelcounter = 0.00;
	accelcountamount = 0.0001;

	for (int i = 0; i < 3; i++) {
		barrels.push_back(new Obstacle("../pixel-barrel.png"));
	}
	finish = new finishLine();

	gameover = new Game_Over("../gameover.jpg", 0, 0);
	gamewon = new Game_Won("../gamewon.jpg", 0, 0);
	
	used = false;
	used2 = false;
}



void App::draw() {

	if (!(intro->getIntroDone())) {
		intro->display();
		intro->setup(mx, my);
		selectedCar = intro->selectedCar;
		intro->continueToGame();
	}

	
	if (intro->getIntroDone() && !(selectedCar->getEndState())) {
		if (barrels[0]->getrpm() < 7000) {
			accelcounter += accelcountamount;
		}
		//cout << "accelcount" << accelcounter << endl;
		barrels[0]->setAcceleration(accelcounter);
		barrels[1]->setAcceleration(accelcounter);
		barrels[2]->setAcceleration(accelcounter);
		finish->setAcceleration(accelcounter);

		background->draw(-0.5);

		barrels[0]->draw(-0.1);
		barrels[1]->draw(-0.1);
		barrels[2]->draw(-0.1);
		finish->draw(-0.1);

		selectedCar->draw(0.0);

		//explosion->draw(0.15);
		
	}

	if (selectedCar->getEndState() == true && gameoverState == false && gameStatus == 1) {
		gameover->finishTheGame();
		gameoverState = true;
	}
	if (gameoverState == true && used2 == true) {
		float points;
		points = (selectedCar->getEngineBonus() + ((elapsedTime / 10) * 100));
		gameover->displayStats(elapsedTime, points);
		gameover->drawStats();
	}

	if (selectedCar->getEndState() == true && gamewonState == false && gameStatus == 2) {
		gamewon->finishTheGame();
		gamewonState = true;
	}
	if (gamewonState == true && used2 == true) {
		float points;
		points = (500 + selectedCar->getEngineBonus() + (100 / elapsedTime * 1000));
		cout << points << endl;
		gamewon->displayStats(elapsedTime, points);
		gamewon->drawStats();
		gamewon->drawBiker();
	}
	
}

void App::idle() {

	if (intro->getIntroDone() == true && used == false) {
		startTime = clock();
		used = true;
	}

	if (intro->getIntroDone() == true && selectedCar->getEndState() == true && used2 == false) {
		endTime = clock();
		elapsedTime = endTime - startTime;
		elapsedTime = (elapsedTime / (int)CLOCKS_PER_SEC);
		used2 = true;
	}

	if (intro->getIntroDone()) {

		barrels[0]->startMovement();
		barrels[1]->startMovement();
		barrels[2]->startMovement();

		barrels[0]->changeImage();
		barrels[1]->changeImage();
		barrels[2]->changeImage();

		if (barrels[0]->lastCycle()) {
			barrels[0]->setAnimating(false);
			barrels[1]->setAnimating(false);
			barrels[2]->setAnimating(false);
			finish->moveFinish();
		}

		if (selectedCar->getEndState() == false) {
			for (int i = 0; i < 3; i++) {
				if (barrels[i]->getHit(selectedCar->getX(), selectedCar->getY())) {
					if (selectedCar->getFilename() == "../lambo.png") {
						selectedCar->setImage("../lambobroke.png");
						selectedCar->setAnimating(false);
						barrels[0]->setAnimating(false);
						barrels[1]->setAnimating(false);
						barrels[2]->setAnimating(false);
						//explosionX = barrels[i]->getX();
						//explosionY = barrels[i]->getY();
						//explosion->setX(explosionX);
						//explosion->setY(explosionY);
						selectedCar->setEndState(true);
						gameStatus = 1;
						break;
					}
					else if (selectedCar->getFilename() == "../shelby.png") {
						selectedCar->setImage("../shelbybroke.png");
						selectedCar->setAnimating(false);
						barrels[0]->setAnimating(false);
						barrels[1]->setAnimating(false);
						barrels[2]->setAnimating(false);
						//explosionX = barrels[i]->getX();
						//explosionY = barrels[i]->getY();
						//explosion->setX(explosionX);
						//explosion->setY(explosionY);
						selectedCar->setEndState(true);
						gameStatus = 1;
						break;
					}
					else if (selectedCar->getFilename() == "../E30.png") {
						selectedCar->setImage("../E30broke.png");
						selectedCar->setAnimating(false);
						barrels[0]->setAnimating(false);
						barrels[1]->setAnimating(false);
						barrels[2]->setAnimating(false);
						//explosionX = barrels[i]->getX();
						//explosionY = barrels[i]->getY();
						//explosion->setX(explosionX);
						//explosion->setY(explosionY);
						selectedCar->setEndState(true);
						gameStatus = 1;
						break;
					}
				}
			}
		}

		
		if (finish->getHit(selectedCar->getX(), selectedCar->getY()) && gameStatus != 2) {
			selectedCar->setEndState(true);
			gameStatus = 2;
		}
		

	}
	

}

void App::keyDown(unsigned char key, float x, float y){
    if (key == 27){
        exit(0);
    }

	if (key == ' ') {
		switch (selectedCar->getGear()) {
		case 6:
			break;
		case 5:
			barrels[0]->setrpmincr(5);
			barrels[1]->setrpmincr(5);
			barrels[2]->setrpmincr(5);
			selectedCar->shift();
			barrels[0]->setrpm(5350);
			barrels[1]->setrpm(5350);
			barrels[2]->setrpm(5350);
			finish->setrpmincr(5);
			finish->setrpm(5350);
			accelcountamount = 0.000006125;
			break;
		case 4:
			barrels[0]->setrpmincr(8);
			barrels[1]->setrpmincr(8);
			barrels[2]->setrpmincr(8);
			selectedCar->shift();
			barrels[0]->setrpm(5300);
			barrels[1]->setrpm(5300);
			barrels[2]->setrpm(5300);
			finish->setrpmincr(8);
			finish->setrpm(5300);
			accelcountamount = 0.00001125;
			break;
		case 3:
			barrels[0]->setrpmincr(14);
			barrels[1]->setrpmincr(14);
			barrels[2]->setrpmincr(14);
			barrels[0]->setrpm(5200);
			barrels[1]->setrpm(5200);
			barrels[2]->setrpm(5200);
			selectedCar->shift();
			finish->setrpmincr(14);
			finish->setrpm(5200);
			accelcountamount = 0.0000325;
			break;
		case 2:
			selectedCar->shift();
			barrels[0]->setrpmincr(25);
			barrels[1]->setrpmincr(25);
			barrels[2]->setrpmincr(25);
			barrels[0]->setrpm(5000);
			barrels[1]->setrpm(5000);
			barrels[2]->setrpm(5000);
			finish->setrpmincr(25);
			finish->setrpm(5000);
			accelcountamount = 0.000055;
			break;
		case 1:
			selectedCar->shift();
			barrels[0]->setrpm(4500);
			barrels[1]->setrpm(4500);
			barrels[2]->setrpm(4500);
			barrels[0]->setrpmincr(35);
			barrels[1]->setrpmincr(35);
			barrels[2]->setrpmincr(35);
			finish->setrpmincr(35);
			finish->setrpm(4500);
			accelcountamount = 0.00008;
			break;
		}
		
		//explosion->playOnce();
	}

	if (key == 'a') {
		selectedCar->turnLeft();
	}

	if (key == 'd') {
		selectedCar->turnRight();
	}
    
}

void App::leftMouseDown(float x, float y) {
	mx = x;
	my = y;
}


App::~App(){
    std::cout << "Exiting..." << std::endl;

	delete selectedCar;
	delete intro;
	delete background;

	
	for (int i = 0; i < 3; i++) {
		delete barrels[i];
	}

	delete finish;
	delete gameover;
	delete gamewon;
	
	
}
