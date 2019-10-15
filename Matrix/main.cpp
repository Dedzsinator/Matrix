#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int Modulus(int i1, int i2) {
	int i3 = (i1 / i2);
	return i1 - (i3 * i2);
}

char GetChar(int generate, char alphabet, int inRange) {
	return (alphabet + Modulus(generate, inRange));
}

int main() {

	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 2);

	char characters[80];
	int j = 7;
	int k = 2;
	int l = 5;
	int m = 1;
	while (true) {
		int i = 0;
		while (i < 80) {
			if(characters[i] != ' ') {
				characters[i] = GetChar(j + i * i, 33, 30);
				if (((i * i + k) % 71) == 0) {

				}
				else {
					SetConsoleTextAttribute(hConsole, 2);
				}
			}

			cout << characters[i];
			++i;
			SetConsoleTextAttribute(hConsole, 2);
			Sleep(0.99);
		}

		j = (j + 31);
		k = (k + 17);
		l = (l + 47);
		m = (m + 67);
		characters[Modulus(j, 80)] = '-';
		characters[Modulus(k, 80)] = ' ';
		characters[Modulus(l, 80)] = '-';
		characters[Modulus(m, 80)] = ' ';
	}

	return 0;
}