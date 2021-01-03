#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

ifstream ifs;
ofstream ofs;
string alphabet = "абвгдежзийклмнопрстуфхцчшщыьэюя";
string str;
const int modul = 31;
const int num = 5;
int OTbigrams1[2*num]; //для запису номерів літер найчастіших біграм ВТ
int OTbigrams2[num];
int CTbigrams1[2*num]; //для запису номерів літер найчастіших біграм ШТ
int CTbigrams2[num];
double no_cross_bigram_frequency[modul][modul];
int a = 1;
int b = 0;

void CT_freq_bigrams(string s, int num)
{
	double count;
	//cout << s.length();

	for (int i = 0; i < 2 * num; i++)
	{
		CTbigrams1[i] = 0;
	}

	for (int i = 0; i < num; i++)
	{
		CTbigrams2[i] = 0;
	}

	for (int i = 0; i < modul; i++)
	{
		count = 0;

		for (int j = 0; j < modul; j++)
		{
			count = 0;

			for (int k = 0; k < s.length() - 1; k += 2)
			{
				if (s[k] == alphabet[i] && s[k + 1] == alphabet[j])
				{
					count++;
					//cout << s[k] << " " << s[k + 1] << "\n";
				}
			}
			
			if ((int)s.length() % 2 == 0) no_cross_bigram_frequency[i][j] = 2 * count / s.length();
			if ((int)s.length() % 2 == 1) no_cross_bigram_frequency[i][j] = 2 * count / (s.length() - 1);

			ofs << "\t" << setprecision(6) << no_cross_bigram_frequency[i][j];

			count = 0;

			for (int l = 0; l < 2 * num; l += 2)
			{
				if (no_cross_bigram_frequency[i][j] > no_cross_bigram_frequency[CTbigrams1[l]][CTbigrams1[l + 1]])
					count++;
			}

			for (int l = 0; l < 2 * num; l += 2)
			{
				if (count > l / 2)
				{
					if (l >= 2)
					{
						CTbigrams1[2 * num - l] = CTbigrams1[2 * num - 2 - l];
						CTbigrams1[2 * num + 1 - l] = CTbigrams1[2 * num - 1 - l];
					}

					CTbigrams1[2 * num - 2 - l] = i;
					CTbigrams1[2 * num - 1 - l] = j;
				}
			}

		}
		ofs << "\n";

		for (int l = 0; l < 2 * num; l++)
		{
			ofs << "\t" << CTbigrams1[l];
		}
		ofs << "\n";

		for (int l = 0; l < num; l++)
		{
			CTbigrams2[l] = modul * CTbigrams1[2 * l] + CTbigrams1[2 * l + 1];
			ofs << "\t\t" << CTbigrams2[l];
		}
	}
}

int evklid(int a, int n)
{
	int r[modul];
	int q[modul];
	int v[modul];


}

int main()
{
	setlocale(LC_ALL, "rus");

	char c[30000];

	ifs.open("19.txt");
	ofs.open("out.txt");

	while (!ifs.eof())
	{
		ifs.getline(c, 300);
		str += c;
	}

	//ofs << str;
	CT_freq_bigrams(str, 5);

	OTbigrams1[0] = 17;
	OTbigrams1[1] = 18;
	OTbigrams1[2] = 13;
	OTbigrams1[3] = 14;
	OTbigrams1[4] = 18;
	OTbigrams1[5] = 14;
	OTbigrams1[6] = 13;
	OTbigrams1[7] = 0;
	OTbigrams1[8] = 5;
	OTbigrams1[9] = 13;

	for (int l = 0; l < num; l++)
	{
		OTbigrams2[l] = modul * OTbigrams1[2 * l] + OTbigrams1[2 * l + 1];
		cout << " " << OTbigrams2[l];
	}

	ifs.close();
	ofs.close();
}