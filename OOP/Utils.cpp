#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<bitset>
using namespace std;

void formatFile(string loc) {
	ifstream myfile(loc);
	string text;
	string arr[100];
	unsigned char len = 0;
	while (!myfile.eof()) {	
		getline(myfile, text);
		if (!text.empty()) {
			remove(text.begin(), text.end(), ' ');
			arr[len++] = text;
		}
	}
	myfile.close();
	ofstream file(loc);
	for (unsigned char i = 0; i < len; i++) {
		if (i!=len-1) {
			file << arr[i] << endl;
		}
		else {
			file << arr[i];
		}
		
	}
	file.close();
}


unsigned char getnum(bitset<8> y) {
	unsigned char x = 0;
	if (y[2] == 1) { x = x + 4; }
	if (y[1] == 1) { x = x + 2; }
	if (y[0] == 1) { x = x + 1; }
	return x;
}

string right(string x) {
	string right;
	unsigned char pos = 0;
	pos = x.find('=');
	right = x.substr(pos + 1);
	return right;
}

unsigned char rightInt(string x) {
	x = right(x);
	if (x[0] <= '7' && x[0] >= '0') {
		return (0x08 + x[0] - 48);
	}
	else {
		return 0;
	}
}

string left(string x) {
	unsigned char index = x.find('=');
	string left = x.substr(0, index);
	return left;
}




void printBinary(unsigned char y) {
	bitset<8> x(y);
	cout << x << endl;
}

void printValue(unsigned char y) {
	bitset<8> x(y);
	cout << (getnum(x)+0x30)-48 << endl;
}

void printRAValue(unsigned char y) {
	bitset<8> x(y);
	cout << "RA=" << (getnum(x) + 0x30) - 48 << endl;
}

void printRBValue(unsigned char y) {
	bitset<8> x(y);
	cout << "RB=" << (getnum(x) + 0x30) - 48 << endl;
}
