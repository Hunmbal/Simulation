#include<iostream>
#include<fstream>
#include<string>
#include<bitset>
#include"Utils.h"
#include"ALU.h"


void assemble(string loc, unsigned char* memory) {
	formatFile(loc);
		ifstream myfile(loc);
		string text;
		unsigned char linenum = 0;
		while (!myfile.eof()) {
			getline(myfile, text);
			if (left(text) == "RA") {
				if (right(text) == "RA+RB") {
					memory[linenum] = 0x00;
				}
				else if (right(text) == "RA-RB") {
					memory[linenum] = 0x04;
				}
				else {
					memory[linenum] = rightInt(text);
				}
			}
			else if (left(text) == "RB") {
				if (right(text) == "RA+RB") {
					memory[linenum] = 0x10;
				}
				else if (right(text) == "RA-RB") {
					memory[linenum] = 0x14;
				}
				else {
					memory[linenum] = 0x10 + rightInt(text);
				}
			}
			else if (left(text) == "RO") {
				memory[linenum] = 0x20;
			}
			else if (left(text) == "jumpif") {
				memory[linenum] = 0x70 + rightInt(text);
			}
			else if (left(text) == "jumpto") {
				memory[linenum] = 0xB0 + rightInt(text);
			}
			linenum++;
		}
		memory[linenum] = 0xFF;

}


unsigned char fetch(unsigned char address, unsigned char *memory) {

	return memory[address];
	
}


bitset<8> decode(unsigned char x) {
	bitset<8> y(x);
	return y;
}


void execute(bitset<8> data, unsigned char *RA, unsigned char* RB, unsigned char* RO, unsigned char* address) {
	unsigned char *currentReg = NULL;
	unsigned char carry;

	//check D0, D1
	if (data[5]==0) {
		if (data[4]==0) {currentReg = &(*RA);}
		else {currentReg = &(*RB);}
		//sreg
		if (data[3] == 1 && currentReg != NULL) {
			*currentReg = getnum(data);
		}
		else {
			//cannot return -ve numbers
			if (data[2] == 0) {
				*currentReg = ALU((*RA), (*RB), 0, &carry);  //+ve
			}
			else {
				*currentReg = ALU((*RA), (*RB), 1, &carry);  //-ve
			}

		}
	}
	else {
		if (data[4]==0) {currentReg = &(*RO);}
	}


	//checking JC
	if (data[7]==1) {
		//jumpto
	}
}


