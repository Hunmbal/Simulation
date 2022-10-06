#include "Cycle.h"	
#include"Utils.h"



void main() {

	unsigned char RA = NULL;
	unsigned char RB = NULL;
	unsigned char RO = NULL;
	unsigned char memory[100];

	unsigned char PC = 0;
	unsigned char address = 0;

	assemble("Text.asm", memory);


	do {

		execute(decode(fetch(address, memory)), &RA, &RB, &RO, &address);
		if (RA != NULL) printRAValue(RA);
		if (RB != NULL) printRBValue(RB);

		if (PC == address) {
			PC++;
			address = PC;
		}
		else {
			address++;
			PC = address;
		}
		
		



	} while (memory[address] != 0xFF);


}


