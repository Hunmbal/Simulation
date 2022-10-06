#ifndef CYCLE_H_INCLUDED
#define CYCLE_H_INCLUDED
#include<bitset>
#include <string>
using namespace std;


void assemble(string loc, unsigned char* cache);

unsigned char fetch(unsigned char address, unsigned char* memory);

bitset<8> decode(unsigned char x);

void execute(bitset<8> data, unsigned char* RA, unsigned char* RB, unsigned char* RO, unsigned char* address);

#endif
