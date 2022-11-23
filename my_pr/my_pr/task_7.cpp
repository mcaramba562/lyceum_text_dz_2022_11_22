#include <string>
#include <vector>
#include <iostream>

#include "task_7.h"

using namespace std;

string make_good_7(string s) {
    int l = 0, r = s.length() - 1;
    string russk_m = "יצףךוםדרשחץתפûגאןנמכהז‎ÿקסלטעüב‏";
    string russk_b = "יצףךוםדרשחץתפûגאןנמכהז‎ÿקסלטעüב‏";
    for (int i = 0; i < s.length(); i++) {
        if (russk_b.find(s[i]) != string::npos) {
            s[i] = russk_m[russk_b.find(s[i])];
        }
        else {
            s[i] = tolower(s[i]);
        }
    }
    string bykv = "qwertyuiopasdfghjkzxcvbnmQWERTYUIOOPASDFGHJKLZXCVBNMיצףךוםדרשחץתפûגאןנמכהז‎ÿקסלטעüב‏‏";
    while (bykv.find(s[l]) == string::npos && l + 1 < s.length()) {
        l++;
    }
    while (bykv.find(s[r]) == string::npos && r - 1 >= 0) {
        r--;
    }
    //cout << s << " " << l << " " << r << " " << s.substr(l, r - l + 1) << "\n";
    //return s;
    return s.substr(l, r - l + 1);
}

int is_def_7(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') {
            return i;
        }
    }
    return -1;
}

pair<int, int> solve_7(vector<string> vvod) {
    string s;
    vector<string> a;
    for (int i = 0; i < vvod.size(); i++) {
        s = vvod[i];
        s = make_good_7(s);
        //cout << s << "\n";
        int o = is_def_7(s);
        if (o == -1) {
            a.push_back(s);
        }
        else {
            string cur_1 = s.substr(0, o + 1);
            string cur_2 = s.substr(o + 1, s.length() - o);
            a.push_back(cur_1);
            a.push_back(cur_2);
        }
    }
    string gl = "ואמÿט‏ûף‎";
    string sogl = "יצךםדרשחץתפגןנכהזקסלעüב";

    int ans_gl = 0, ans_sogl = 0;
    for (int i = 0; i < a.size(); i++) {
        int f = 0, s = 0;
        for (int j = 0; j < a[i].size(); j++) {
            if (gl.find(a[i][j]) != string::npos) {
                //cout << a[i] << " " << j << "\n";
                f++;
                s = 0;
            }
            else if (sogl.find(a[i][j]) != string::npos) {
                s++;
                f = 0;
            }
            else {
                f = 0;
                s = 0;
            }

            if (f == 3) {
                f = 0;
                //cout << a[i] << " " << j - 2 << " " << j << "\n";
                ans_gl++;
            }
            if (s == 3) {
                s = 0;
                //cout << a[i] << " " << j - 2 << " " << j << "\n";
                ans_sogl++;
            }
        }
    }
    //cout << ans_gl << " " << ans_sogl;
    return { ans_gl, ans_sogl };
}