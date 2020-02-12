#ifndef randomGen_h
#define randomGen_h
#include <random>

static int getRandom() {
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 5);	// generates a number 1-5

	return dist6(rng);
}

#endif
