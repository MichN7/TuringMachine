#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <regex>



typedef std::map<int, char> Cinta;
Cinta cinta;
int cabezal = 1;
int extremo = 1;

void print() {
	for (int i = 0; i < cinta.size(); i++)
	{
		if (cabezal == i) {
			std::cout << '.';
		}
		std::cout << cinta[i];
	}
	std::cout << std::endl;
}

void tape() {
	cinta[0] = ' ';
	cinta[1] = '@';
	print();
}

bool inInLanguage(char c) {
	int n = c;
	if (n >= 48 && n <= 57 || n >= 65 && n <= 90 || n >= 97 && n <= 122) {
	
		return true;
	}
	return false;

}



void right(int n = 1) {
	cabezal += n;
	print();
}

void left(int n= 1) {
	cabezal -= n;
	print();
}

void sigma(char s) {
	cinta[cabezal] = s;
	print();
}

void left_to(char s) {
	int j = cabezal;
	while (cinta[j] != s && j >= 0) {
		left();
		j--;
	}
}

void right_to(char s) {
	int j = cabezal;
	while (cinta[j] != s && j<=extremo) {
		right();
		j++;
	}
	cinta[j + 1];
}


void push(char v) {
	if (inInLanguage(v)) {
		cinta[extremo + 1] = ' ';
		right_to(' ');
		sigma(v);
		left_to('@');
		extremo++;
	}
	else {
		std::cout << " ";
	}
}

void pop() {
	right_to(' ');
	left();
	char val = cinta[cabezal];
	extremo--;
	sigma(' ');
	left_to('@');
	left();
	sigma(val);
	sigma(' ');
	right();
}

void finish() {
	while (extremo != cabezal) {
		pop();
	}
}

void read() {
	char input = ' ';
	do {
	std::cin >> input;
	input = toupper(input);
		switch (input)
		{
		case 'I': {
			char value = ' ';
			std::cin >> value;
			push(value);
			break;
		}
		case 'O': {
			pop();
			break;
		}
		case 'X': {
			finish();
			break;
		}
		}
	} while (input != 'E');
}



int main()
{
	tape();
	read();
	system("PAUSE");
	return 0;
}
