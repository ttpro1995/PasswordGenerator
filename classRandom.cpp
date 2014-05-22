//Haha TTpro

#include <iostream>
#include <time.h>
#include"classRandom.h"

Random::Random()
{
	seed = time(NULL) % INT_MAX ;
	reseed();
	reseed();
	reseed();
	reseed();
	reseed();
}

int Random::reseed()
{
	seed = (seed * multiplier + add_on) % (time(NULL));
	return seed;
}

double Random::random_real()
{
	double max = INT_MAX +1.0;
	double temp = reseed();
	if (temp < 0) temp = temp + max;
	return temp / max;
}

int Random::random_integer(int low, int high)
{
	if (low > high) return random_integer(high, low);
	else return ((int)((high - low + 1) *random_real())) + low;
}

