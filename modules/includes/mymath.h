#ifndef MYMATH_H_INCLUDED
#define MYMATH_H_INCLUDED

int gcd(int a, int b);
int lcm(int a, int b);
char *_10tor(int a, int r, char *buff);

int myRandom();
void initMyRandom(int start);

int indexOfInt(int a, int *arr, int sz);
void displayArrayInt(int *arr, int sz);
int maxInt(int *arr, int sz);
int minInt(int *arr, int sz);

#endif // MYMATH_H_INCLUDED
