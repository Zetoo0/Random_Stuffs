#ifndef MATHSTUFFS_H
#define MATHSTUFFS_H

#include <random>


int rand(int min, int max)
{
	std::random_device rnd;
	std::mt19937 gen(rnd());
	std::uniform_int_distribution<> dist(min, max);
	return dist(gen);
}
#endif