#ifndef gameover_h
#define gameover_h

#include "../TexRect.h"
#include "../visualc15/engine.h"
#include "../visualc15/gearbox.h"
#include "../visualc15/car.h"

using namespace std;

class Game_Over {

	

public:
	float totalTime;
	int minutes, tenseconds, seconds, thousands, hundreds, tens, ones;

	TexRect* backg;
	TexRect* mins;
	TexRect* tensec;
	TexRect* sec;

	TexRect* Tpts;
	TexRect* hpts;
	TexRect* tpts;
	TexRect* spts;
	int finalScore;

	Game_Over(){
		totalTime = 0, minutes = 0, tenseconds = 0, seconds = 0, thousands = 0, hundreds = 0, tens = 0, ones = 0, finalScore = 0;
	}

	Game_Over(char* fileName, int totaltime, int points) {
		backg = new TexRect(fileName, -1, 1, 2, 2);
		finalScore = points;
		totalTime = totaltime;
	}

	void finishTheGame() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	virtual void displayStats(float elapsedTime, int score) {
		
		totalTime = elapsedTime;
		finalScore = score;
		//getting time
		minutes = (totalTime / 60);
		
		tenseconds = ((totalTime - (minutes * 60)) / 10);
		
		seconds = (((totalTime - (minutes * 60)) - (tenseconds * 10)));

		//getting score
		thousands = (finalScore / 1000);

		hundreds = ((finalScore - (thousands * 1000)) / 100);

		tens = (((finalScore - (thousands * 1000)) - (hundreds * 100)) / 10);
		
		ones = (((finalScore - (thousands * 1000)) - (hundreds * 100)) - (tens * 10));
		
		setupStats();
	}

	void setupStats() {
	
		char* num;
	
		/*-------------------------1:00---------------------------*/

		switch (minutes) {
		case 0:
			num = "../zero.png";
			break;
		case 1:
			num = "../one.png";
			break;
		case 2:
			num = "../two.png";
			break;
		case 3:
			num = "../three.png";
			break;
		case 4:
			num = "../four.png";
			break;
		case 5:
			num = "../five.png";
			break;
		case 6:
			num = "../six.png";
			break;
		case 7:
			num = "../seven.png";
			break;
		case 8:
			num = "../eight.png";
			break;
		case 9:
			num = "../nine.png";
			break;
		}
		
		mins = new TexRect(num, 0.55, -0.6, 0.1, 0.1);	//crashes here
		
		/*-------------------------0:10---------------------------*/

		switch (tenseconds) {
		case 0:
			num = "../zero.png";
			break;
		case 1:
			num = "../one.png";
			break;
		case 2:
			num = "../two.png";
			break;
		case 3:
			num = "../three.png";
			break;
		case 4:
			num = "../four.png";
			break;
		case 5:
			num = "../five.png";
			break;
		case 6:
			num = "../six.png";
			break;
		case 7:
			num = "../seven.png";
			break;
		case 8:
			num = "../eight.png";
			break;
		case 9:
			num = "../nine.png";
			break;
		}
		tensec = new TexRect(num, 0.77, -0.6, 0.1, 0.1);

		/*--------------------------0:01--------------------------*/

		switch (seconds) {
		case 0:
			num = "../zero.png";
			break;
		case 1:
			num = "../one.png";
			break;
		case 2:
			num = "../two.png";
			break;
		case 3:
			num = "../three.png";
			break;
		case 4:
			num = "../four.png";
			break;
		case 5:
			num = "../five.png";
			break;
		case 6:
			num = "../six.png";
			break;
		case 7:
			num = "../seven.png";
			break;
		case 8:
			num = "../eight.png";
			break;
		case 9:
			num = "../nine.png";
			break;
		}
	sec	= new TexRect(num, 0.87, -0.6, 0.1, 0.1);

	/*-------------------------1000--------------------------*/

	switch (thousands) {
	case 0:
		num = "../zero.png";
		break;
	case 1:
		num = "../one.png";
		break;
	case 2:
		num = "../two.png";
		break;
	case 3:
		num = "../three.png";
		break;
	case 4:
		num = "../four.png";
		break;
	case 5:
		num = "../five.png";
		break;
	case 6:
		num = "../six.png";
		break;
	case 7:
		num = "../seven.png";
		break;
	case 8:
		num = "../eight.png";
		break;
	case 9:
		num = "../nine.png";
		break;
	}
	Tpts = new TexRect(num, 0.40, -0.85, 0.1, 0.1);

	/*----------------------0100-------------------------*/

	switch (hundreds) {
	case 0:
		num = "../zero.png";
		break;
	case 1:
		num = "../one.png";
		break;
	case 2:
		num = "../two.png";
		break;
	case 3:
		num = "../three.png";
		break;
	case 4:
		num = "../four.png";
		break;
	case 5:
		num = "../five.png";
		break;
	case 6:
		num = "../six.png";
		break;
	case 7:
		num = "../seven.png";
		break;
	case 8:
		num = "../eight.png";
		break;
	case 9:
		num = "../nine.png";
		break;
	}
	hpts = new TexRect(num, 0.53, -0.85, 0.1, 0.1);

	/*------------------------0010--------------------------*/

	switch (tens) {
	case 0:
		num = "../zero.png";
		break;
	case 1:
		num = "../one.png";
		break;
	case 2:
		num = "../two.png";
		break;
	case 3:
		num = "../three.png";
		break;
	case 4:
		num = "../four.png";
		break;
	case 5:
		num = "../five.png";
		break;
	case 6:
		num = "../six.png";
		break;
	case 7:
		num = "../seven.png";
		break;
	case 8:
		num = "../eight.png";
		break;
	case 9:
		num = "../nine.png";
		break;
	}
	tpts = new TexRect(num, 0.66, -0.85, 0.1, 0.1);
	
	/*-----------------------0001--------------------------*/

	switch (ones) {
	case 0:
		num = "../zero.png";
		break;
	case 1:
		num = "../one.png";
		break;
	case 2:
		num = "../two.png";
		break;
	case 3:
		num = "../three.png";
		break;
	case 4:
		num = "../four.png";
		break;
	case 5:
		num = "../five.png";
		break;
	case 6:
		num = "../six.png";
		break;
	case 7:
		num = "../seven.png";
		break;
	case 8:
		num = "../eight.png";
		break;
	case 9:
		num = "../nine.png";
		break;
	}
	spts = new TexRect(num, 0.79, -0.85, 0.1, 0.1);
	
	}

	void drawStats() const{

		backg->draw(0.10);

		mins->draw(0.15);
		tensec->draw(0.15);
		sec->draw(0.15);

		Tpts->draw(0.15);
		hpts->draw(0.15);
		tpts->draw(0.15);
		spts->draw(0.15);

	}

	float checkTime() const {
		return totalTime;
	}

	int checkScore() const {
		return finalScore;
	}

	~Game_Over() {
		delete backg;
		delete mins;
		delete tensec;
		delete sec;

		delete Tpts;
		delete hpts;
		delete tpts;
		delete spts;
	}

};


#endif
