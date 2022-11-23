#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <iostream>

#include "Entropia.h"

using namespace std;

double solve_entropia(vector<string> vvod) {
	map<char, map<char, int> > kol_s;
	map<char, int> kol_b;
	int count_b = 0;
	int count_soch = 0;
	string rus = "éöóêåíãøùçõúôûâàïğîëäæıÿ÷ñìèòüáşÉÖÓÊÅÍÃØÙÇÕÚÔÛÂÀÏĞÎËÄÆİß×ÑÌÈÒÜÁŞ";
	for (int i = 0; i < vvod.size(); i++) {
		for (int j = 0; j < vvod[i].size() - 1; j++) {
			if (rus.find(vvod[i][j]) != string::npos 
				&& rus.find(vvod[i][j + 1] != string::npos)) {
				//kol_s[vvod[i].substr(j, 2)]++;
				kol_s[vvod[i][j]][vvod[i][j + 1]]++;
				kol_b[vvod[i][j]]++;
				count_soch++;
				count_b++;
			}
			count_b++;
		}
	}
	double entropia = 0;
	for (auto cur1 : kol_s) {
		double p_i = kol_b[cur1.first] * 1.;
		p_i /= count_b * 1.;
		for (auto cur2 : cur1.second) {
			double p_j = kol_b[cur2.first] * 1.;
			p_j /= count_b * 1.;
			double p_i_and_j = kol_s[cur1.first][cur2.first] * 1.;
			p_i_and_j /= 36.0 * 36.0;
			double p_j_after_i = p_i_and_j / p_j;
			entropia -= p_i * p_j_after_i * log2(p_j_after_i);
		}
	}
	return entropia;
}