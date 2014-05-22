//Haha TTpro

class Random
{
private:
	int seed;
	int reseed();
	const int multiplier = 4748;
	const int add_on = 9987;

public:
	//contructor
	Random();

	///Post: The seed is replaced by a pseudorandom successor.
	double random_real();

	//A random integer between low and high (inclusive) is returned.
	int random_integer(int low, int high);



};