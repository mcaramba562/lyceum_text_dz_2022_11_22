#pragma once
#include <string>
#include <vector>

#include "task_6.h"

vector<pair<string, int> > solve_6(vector<string> vvod) {
	bool first = 0, second = 0;
    string text = "";
    for (string cur : vvod) {
        text += cur + " ";
    }
    string vowels = "¸åûàîýÿèþ";
    /*
    vowels.push_back(-1);
    vowels.push_back(-2);
    vowels.push_back(-3);
    vowels.push_back(-5);
    vowels.push_back(-13);
    vowels.push_back(-18);
    vowels.push_back(-24);
    vowels.push_back(-27);
    vowels.push_back(-32);
    vowels.push_back(-72);
    */
    int words[4] = { 0, 0, 0, 0 };
    for (size_t prev_pos = -1, pos = text.find(' ');
        pos != string::npos;
        prev_pos = pos, pos = text.find(' ', pos + 1)) {
        if (pos - prev_pos - 1 > 1) {
            first = vowels.find(text[prev_pos + 1]) != string::npos;
            second = vowels.find(text[prev_pos + 2]) != string::npos;
            words[first + 2 * second]++;
        }
    }
    vector<pair<string, int> > ans(4);
    for (int i = 0; i < 4; i++) {
        ans[i].second = words[i];
    }
    return ans;
}