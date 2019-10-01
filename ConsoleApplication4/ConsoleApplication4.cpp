#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string MAIN_STRING = "? ? 2 ? ? ?\n? ? 4 ? ? ?\n? ? 6 ? ? ?\n& & 8 & & &\n& & 10 & & &\n& & 12 & & &";
string PATH = "C:\\Users\\Vasya\\source\\repos\\ConsoleApplication4\\ConsoleApplication4\\Text.txt";

void fill_file() {
	ofstream out;
	out.open(PATH);
	if (out.is_open())
	{
		out << MAIN_STRING;
	}
	out.close();
}

void print_file_data() {
	ifstream in(PATH);
	string line;
	if (in.is_open())
	{
		while (getline(in, line))
		{
			cout << line << endl;
		}
	}
	in.close();
}

void print_line_from_file() {
	cout << "input number of line (max - 5)" << endl;
	int number = 0;
	cin >> number;
	if (number < 0 || number > 5) {
		cout << "wrong number (min - 0, max - 5)\n";
	}
	else {
		ifstream in(PATH);
		string line;
		if (in.is_open())
		{
			while (getline(in, line))
			{
				if (number == 0) {
					cout << line << endl;
					break;
				}
				number--;
			}
		}
		in.close();
	}
}

int main()
{
	fill_file();
	cout << "File was created";
	int req = 0;
	while (true) {
		cout << "you can do:\n(1) - input number of line to whatch it\n(2) - whatch all file\n(3) - exit\n";
		cin >> req;
		if (req == 1) {
			print_line_from_file();
		}
		else if (req == 2) {
			print_file_data();
		}
		else if (req == 3) {
			exit(0);
		}
		else {
			cout << "wrong operation\n";
		}
	}
}