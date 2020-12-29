#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <Windows.h>
using namespace std;

int oper1 = 0, oper2 = 0;
string sum(5000, 'а');
string temp_sum;
int period;
int ki;
int sum_index = 0;
int Count = 0;
double fi;
string alphabet = "абвгдежзийклмнопрстуфхцчшщъыьэюя";

string encipher(string s, string k)
{
	period = k.length();

	for (int i = 0; i < s.length(); i++)
	{
		ki = i % period;
		for (int j = 0; j < 32; j++)
		{
			if (s[i] == alphabet[j])
				oper1 = j;
			if (k[ki] == alphabet[j])
				oper2 = j;
		}

		sum_index = (oper1 + oper2) % 32;
		sum[i] = alphabet[sum_index];
	}
	return sum.substr(0, s.length());
}

double indexCount(string s)
{
	fi = 0.000000;

	for (int i = 0; i < 32; i++)
	{
		Count = 0;

		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == alphabet[i])
			{
				Count++;
			}
		}
		fi += Count * (Count - 1);
	}
	//cout << fi << " " << s.length() << " " << (s.length() * (s.length() - 1)) << endl;
	return fi / (s.length() * (s.length() - 1));
}

int main()
{
	setlocale(LC_ALL, "rus");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	ifstream ifs;
	ofstream ofs, ofs2, ofs3, ofs4, ofs5, ofs15;
	char c[25000];
	string key1, key2, key3, key4, key5;
	string inp1;

	ifs.open("keys.txt");

	ifs.getline(c, 50);
	key1 = c;
	ifs.getline(c, 50);
	key2 = c;
	ifs.getline(c, 50);
	key3 = c;
	ifs.getline(c, 50);
	key4 = c;
	ifs.getline(c, 50);
	key5 = c;

	ifs.close();
	ifs.open("input1.txt");
	ofs2.open("out2r.txt");
	ofs3.open("out3r.txt");
	ofs4.open("out4r.txt");
	ofs5.open("out5r.txt");
	ofs15.open("out15r.txt");

	ifs.getline(c, 5000);
	inp1 = c;

	cout << indexCount(inp1) << endl;

	temp_sum = encipher(inp1, key1);
	ofs2 << temp_sum << "\n";
	ofs2 << indexCount(temp_sum) << "\n";

	temp_sum = encipher(inp1, key2);
	ofs3 << temp_sum << "\n";
	ofs3 << indexCount(temp_sum) << "\n";

	temp_sum = encipher(inp1, key3);
	ofs4 << temp_sum << "\n";
	ofs4 << indexCount(temp_sum) << "\n";

	temp_sum = encipher(inp1, key4);
	ofs5 << temp_sum << "\n";
	ofs5 << indexCount(temp_sum) << "\n";

	temp_sum = encipher(inp1, key5);
	ofs15 << temp_sum << "\n";
	ofs15 << indexCount(temp_sum) << "\n";

	ofs2.close();
	ofs3.close();
	ofs4.close();
	ofs5.close();
	ofs15.close();


	//ofs << key1 << "\n" << key2 << "\n" << key3 << "\n" << key4 << "\n" << key5 << "\n";
	//if (key5[2] == key5[4]) cout << 1;
	//else cout << 0;
	//if (key5[0] == alphabet[6]) cout << 1;
	//else cout << 0;
	//cout << alphabet[6];
	//ofs << "\n" << key5[0] << "\n" << inp1;
	//cout << key4[2] << key4[3] << key4.substr(0, 3);


	ofs.close();
}