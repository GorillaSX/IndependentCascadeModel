//a declare of a function used to declare random number
#ifndef _RANDOM_H
#define _RANDOM_H
#include <cstdlib>
#include <iostream>
using namespace std;
template<typename T>
T random(T min, T max)
{
	return (min + static_cast<T>((max - min) * ((rand() % 1001) /(double) 1000))); //closed interval between min and max
}
#endif //_RANDOM_H
