#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include<bitset>
#include <string>
using namespace std;



void formatFile(string loc);


unsigned char getnum(bitset<8> y);

string right(string x);

unsigned char rightInt(string x);

string left(string x);




void printBinary(unsigned char y);

void printValue(unsigned char y);

void printRAValue(unsigned char y);

void printRBValue(unsigned char y);

#endif
