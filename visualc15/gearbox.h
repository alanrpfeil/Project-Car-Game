#ifndef gearbox_h
#define gearbox_h

class gearbox {
	
	typedef enum { balanced, rally, topspeed } gearing;
	
	float accelBonus;
	gearing selected_gearing;
	

public:
	
	typedef enum { first, second, third, fourth, fifth, sixth } gears;
	gears current_gear;
	
	gearbox() : selected_gearing(balanced), current_gear(first), accelBonus(0) {}

	gearbox(gearing selected_gearing) {
		this->selected_gearing = selected_gearing;
		setupGearbox(selected_gearing);
	}

	void setupGearbox(int num) {
		switch (num) {
		case (1):
			accelBonus = 0;
			selected_gearing = balanced;
			break;
		case (2):
			accelBonus = .10;
			selected_gearing = rally;
			break;
		case (3):
			accelBonus = -.07;
			selected_gearing = topspeed;
			break;
		}
	}

	void shift() {
		switch (current_gear) {
		case sixth:
			break;
		case fifth:
			current_gear = sixth;
			break;
		case fourth:
			current_gear = fifth;
			break;
		case third:
			current_gear = fourth;
			break;
		case second:
			current_gear = third;
			break;
		case first:
			current_gear = second;
			break;
		}
	}

	float getBonusAccel() const{
		return accelBonus;
	}
	
	int getCurrentGear() {
		switch (current_gear) {
		case sixth:
			return 6;
			break;
		case fifth:
			return 5;
			break;
		case fourth:
			return 4;
			break;
		case third:
			return 3;
			break;
		case second:
			return 2;
			break;
		case first:
			return 1;
			break;
		}
	}
	
	~gearbox() {

	}

};
#endif