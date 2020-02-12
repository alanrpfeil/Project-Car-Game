#ifndef intro_h
#define intro_h
#include "../TexRect.h"
#include "../visualc15/engine.h"
#include "../visualc15/gearbox.h"
#include "../visualc15/car.h"
#include "App.h"

class introduction {

	TexRect* engines;
	TexRect* gearboxes;
	TexRect* chassis;
	TexRect* engine0;
	TexRect* engine1;
	TexRect* engine2;
	TexRect* gearbox0;
	TexRect* gearbox1;
	TexRect* gearbox2;
	TexRect* chassis0;
	TexRect* chassis1;
	TexRect* chassis2;

	engine* selectedEngine;
	gearbox* selectedGearbox;
	char* vehicle;

	bool engineCheck;
	bool gearboxCheck;
	bool vehicleCheck;
	bool carGot;

	bool introDone;


	TexRect* backg;

public:
	car* selectedCar;

	introduction() {
		engines = new TexRect("../engines.png", -0.20, 0.95, 0.40, 0.05);
		gearboxes = new TexRect("../gearboxes.png", -0.20, 0.28, 0.40, 0.05);
		chassis = new TexRect("../chassis.png", -0.20, -0.38, 0.40, 0.05);
		engine0 = new TexRect("../standardengine.png", -0.95, 0.90, 0.60, 0.60);
		engine1 = new TexRect("../sportengine.png", -0.30, 0.90, 0.60, 0.60);
		engine2 = new TexRect("../racingengine.png", 0.35, 0.90, 0.60, 0.60);
		gearbox0 = new TexRect("../stockgearing.png", -0.95, 0.22, 0.60, 0.60);
		gearbox1 = new TexRect("../rallygearing.png", -0.30, 0.22, 0.60, 0.60);
		gearbox2 = new TexRect("../racegearing.png", 0.35, 0.22, 0.60, 0.60);
		chassis0 = new TexRect("../E30.png", -0.80, -0.43, 0.351, 0.60);
		chassis1 = new TexRect("../shelby.png", -0.1755, -0.43, 0.351, 0.60);
		chassis2 = new TexRect("../lambo.png", 0.45, -0.43, 0.351, 0.60);

		selectedCar = new car();
		selectedEngine = new engine();
		selectedGearbox = new gearbox();
		vehicle = "";

		engineCheck = false;
		gearboxCheck = false;
		vehicleCheck = false;
		carGot = false;

		introDone = false;

		backg = new TexRect("../road.png", -1, 1, 2, 2);
	}

	void display() const {
		backg->draw(-0.1);

		engines->draw(0.0);
		gearboxes->draw(0.0);
		chassis->draw(0.0);
		engine0->draw(0.0);
		engine1->draw(0.0);
		engine2->draw(0.0);
		gearbox0->draw(0.0);
		gearbox1->draw(0.0);
		gearbox2->draw(0.0);
		chassis0->draw(0.0);
		chassis1->draw(0.0);
		chassis2->draw(0.0);

		
	}

	void setup(float mx, float my) {
		static car* tempCar;

		// Engine selection
		if (engine0->contains(mx, my) && engineCheck == false) {
			selectedEngine->setupEngine(1);
			engineCheck = true;
		}
		else if (engine1->contains(mx, my) && engineCheck == false) {
			selectedEngine->setupEngine(2);
			engineCheck = true;
		}
		else if (engine2->contains(mx, my) && engineCheck == false) {
			selectedEngine->setupEngine(3);
			engineCheck = true;
		}

		// Gearbox selection
		else if (gearbox0->contains(mx, my) && gearboxCheck == false) {
			selectedGearbox->setupGearbox(1);
			gearboxCheck = true;
		}
		else if (gearbox1->contains(mx, my) && gearboxCheck == false) {
			selectedGearbox->setupGearbox(2);
			gearboxCheck = true;
		}
		else if (gearbox2->contains(mx, my) && gearboxCheck == false) {
			selectedGearbox->setupGearbox(3);
			gearboxCheck = true;
		}

		// Chassis selections
		else if (chassis0->contains(mx, my) && vehicleCheck == false) {
			vehicle = "../E30.png";
			vehicleCheck = true;
		}
		else if (chassis1->contains(mx, my) && vehicleCheck == false) {
			vehicle = "../shelby.png";
			vehicleCheck = true;
		}
		else if (chassis2->contains(mx, my) && vehicleCheck == false) {
			vehicle = "../lambo.png";
			vehicleCheck = true;
		}

		// makes selectedCar being able to be returned in another function
		if (engineCheck == true && gearboxCheck == true && vehicleCheck == true && introDone == false) {
			tempCar = new car(vehicle, *selectedEngine, *selectedGearbox);
			selectedCar = tempCar;
		}

	}

	void continueToGame() {
		if (engineCheck == true && gearboxCheck == true && vehicleCheck == true) {
			introDone = true;
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
	}

	//------------------------------Getters------------------------------

	car* getCar() {																					// only called when mouse is down!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if (introDone == true && carGot == false) {
			carGot = true;
			return selectedCar;
		}
	}

	bool getIntroDone() const {
		return introDone;
	}

	~introduction() {
		delete engines;
		delete gearboxes;
		delete chassis;
		delete engine0;
		delete engine1;
		delete engine2;
		delete gearbox0;
		delete gearbox1;
		delete gearbox2;
		delete chassis0;
		delete chassis1;
		delete chassis2;

		delete selectedEngine;
		delete selectedGearbox;
		delete vehicle;


		delete backg;
	}

};

#endif
