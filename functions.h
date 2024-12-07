#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>

using namespace std;

extern double coef[11];

double func(short x);
short genetic(short x0, short x1, short* population, double* f, int n);
