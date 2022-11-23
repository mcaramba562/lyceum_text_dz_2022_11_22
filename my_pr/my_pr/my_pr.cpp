// my_pr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
#include <fstream>
#include <Windows.h>

#include "task_9.h"
#include "task_8.h"
#include "task_7.h"
#include "task_3.h"
//#include "Entropia.h"

using namespace std;

void solve() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<string> vvod;
	string s;
	while (fin >> s) {
		vvod.push_back(s);
	}
	vector<pair<string, int> > ans_9 = solve_9(vvod);
	for (int i = 0; i < ans_9.size() && i < 10; i++) {
		fout << ans_9[i].first << ": " << ans_9[i].second << "\n";
	}

	int kol_xlov_podr_2_gl_2_sogl = solve_8(vvod);
	fout << "\n";
	
	fout << "Кодичаство слов заканчивающиеся на 2 гл и начин на 2 согл: ";
	fout << kol_xlov_podr_2_gl_2_sogl << "\n";
	
	pair<int, int> t_7 = solve_7(vvod);
	int kol_3_gl_podr = t_7.first;
	int kol_3_sogl_podr = t_7.second;
	fout << "количество слов с 3 гласнми подряд: " << kol_3_gl_podr << "\n";
	fout << "количество слов с 3 согласнми подряд: " << kol_3_sogl_podr << "\n";
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}