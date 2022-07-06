#if RANDOMMATHSTUFFS_H
#define RANDOMMATHSTUFFS_H
#include <random>
#include <iostream>


float Lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}

int Abs(int a) {
	return a * (-1);
}

int MaxFromArr(int arr[], int size)
{
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

float PI()
{
	return 3.14159265358979f;
}

int NumXNum(int num)
{
	return num * num;
}

int Pow(int powNum, int toPower)
{
	return toPower * powNum;
}

int HypotLength(int aSqrt, int bSqrt)
{
	return aSqrt + bSqrt;
}

float Euler()
{
	return 2.71828f;
}

float Exp(int num)
{
	return num * Euler();
}

int Sign(float f)
{
	if (f >= 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int rand(int min, int max)
{
	std::random_device rnd;
	std::mt19937 gen(rnd());
	std::uniform_int_distribution<> dist(min, max);
	return dist(gen);
}

int Wrap(float x, float min, float max)
{
	//rand num between the two?
	return rand(min, max);
}

bool IsWithInAllExclusive(int a, int b, int val)
{
	if ((val > a) && (val < b))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool RandBool()
{
	int randNum = rand(-1, 2);
	if (randNum == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

 float Sin(float opposite, float hypotenuse) {
	return opposite / hypotenuse;
}

 float Cos(float adjacent, float hypotenuse) {
	return adjacent / hypotenuse;
}

 float Tan(float sin, float cos) {
	return sin / cos;
}

 float Ffloor(float f) {
	int i = f;
	return i;
}

#endif
