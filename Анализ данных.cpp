// rasst.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	double a1, a2, a3, a4;
	double sr;
	fin >> a1 >> a2 >> a3 >> a4;
	sr = (a1 + a2 + a3 + a4) / 4;

	double b1, b2, b3, b4;
	b1 = abs(a1 - sr);
	b2 = abs(a2 - sr);
	b3 = abs(a3 - sr);
	b4 = abs(a4 - sr);
	if (b1 > b2 && b1 > b3 && b1 > b4)
	{
		fout << 1 << " ";

	}
	else
	{
		if (b2 > b1 && b2 > b3 && b2 > b4)
		{
			fout << 2 << " ";
		}
		else
		{
			if (b3 > b2 && b3 > b1 && b3 > b4)
			{
				fout << 3 << " ";
			}
			else
			{
				fout << 4 << " ";
			}
		}
	}
	fout << b1 * b1 << " " << b2 * b2 << " " << b3 * b3 << " " << b4 * b4;

}
