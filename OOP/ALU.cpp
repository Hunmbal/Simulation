unsigned char ALU(unsigned char a, unsigned char b, bool op, unsigned char* carry) {

	if (op == 0) {
		a = a + b;
		if (a > 7) {
			a = 0;
		}
		return a;
	}
	else {
		if (a > b) {
			a = a - b;
			return a;
		}
		a = b - a;
		return a;
	}

}