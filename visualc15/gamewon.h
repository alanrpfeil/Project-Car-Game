#ifndef gamewon_h
#define gamewon_h

#include "../visualc15/gameover.h"

class Game_Won : public Game_Over {
	char* image;
	TexRect* biker;

public:

	Game_Won() : Game_Over() {}

	Game_Won(char* filename, int totalTime, int points) : Game_Over(filename, totalTime, points) {}

	void displayStats(float elapsedtime, int points) {
		if (points > 1000) {
			image = "../bikerkyrilov.png";
		}
		else {
			image = "../bikerman.png";
		}
		biker = new TexRect(image, -0.4, 0.85, 0.6, 0.5);

		totalTime = elapsedtime;
		finalScore = points;
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

	void drawBiker() {
		biker->draw(0.2);
	}

	~Game_Won() {
		delete biker;	
	}
};

#endif
