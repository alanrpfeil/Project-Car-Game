#ifndef engine_h
#define engine_h

class engine {

	typedef enum { stock, sport, racing } engines;
	engines selected_engine;
	int topSpeed;
	float baseAccel;
	int topRPM;
	unsigned int engineBonus;

public:

	engine() : topSpeed(0), baseAccel(0), topRPM(0){}

	engine(engines selectedEngine) {
		selected_engine = selectedEngine;
		setupEngine(selectedEngine);
	}

	void setupEngine(int num) {		//all setters in one because all individual engines will have consistent values; no individual setters.
		switch (num) {
		case 1:
			selected_engine = stock;
			topSpeed = 3.0;
			baseAccel = 16;
			topRPM = 6000;
			engineBonus = 0;
			break;
		case 2:
			selected_engine = sport;
			topSpeed = 3.5;
			baseAccel = 13;
			topRPM = 7000;
			engineBonus = 250;
			break;
		case 3:
			selected_engine = racing;
			topSpeed = 4.0;
			baseAccel = 10;
			topRPM = 7500;
			engineBonus = 500;
			break;
		}
	}

	float getBaseAccel() const{
		return baseAccel;
	}

	int getTopSpeed() const{
		return topSpeed;
	}

	int getTopRPM() const {
		return topRPM;
	}

	unsigned int getBonus() const {
		if (selected_engine == stock) {
			return 0;
		} else if (selected_engine == sport) {
			return 250;
		} else {
			return 500;
		}
	}

	~engine() {

	}

};

#endif