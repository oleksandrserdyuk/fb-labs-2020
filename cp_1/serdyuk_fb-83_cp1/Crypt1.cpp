#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	ifstream f;
	f.open("text.txt");
	char c[500];
	string s;
	double count = 0.000000;

	while (!f.eof())
	{
		f.getline(c, 500);
		s += c;
		s += " ";
	}

	int sz = s.length();
	s.resize(sz - 1);
	sz = s.length();

	//char alphabet[32] = { "а", "б", "в", "г", "д", "е", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ы", "ь", "э", "ю", "я", " " };
	string alphabet = "абвгдежзийклмнопрстуфхцчшщыьэюя ";
	double frequency[32];
	double enthropy[32];

	for (int i = 0; i < 32; i++)
	{
		count = 0;

		for (int j = 0; j < sz; j++)
		{
			if (s[j] == alphabet[i])
			{
				count++;
			}
		}
		frequency[i] = count / sz;
		cout << setprecision(6) << frequency[i] << " ";
	}
}