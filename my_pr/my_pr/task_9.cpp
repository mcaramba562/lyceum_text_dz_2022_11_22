#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "task_9.h"

using namespace std;
string make_good_9(string s) {
    int l = 0, r = s.length() - 1;
    string russk_m = "éöóêåíãøùçõúôûâàïğîëäæıÿ÷ñìèòüáş";
    string russk_b = "ÉÖÓÊÅÍÃØÙÇÕÚÔÛÂÀÏĞÎËÄÆİß×ÑÌÈÒÜÁŞ";
    for (int i = 0; i < s.length(); i++) {
        if (russk_b.find(s[i]) != string::npos) {
            s[i] = russk_m[russk_b.find(s[i])];
        }
        else {
            s[i] = tolower(s[i]);
        }
    }

    string bykv = "qwertyuiopasdfghjkzxcvbnmQWERTYUIOOPASDFGHJKLZXCVBNMéöóêåíãøùçõúôûâàïğîëäæıÿ÷ñìèòüáşÉÖÓÊÅÍÃØÙÇÕÚÔÛÂÀÏĞÎËÄÆİß×ÑÌÈÒÜÁŞ";
    while (bykv.find(s[l]) == string::npos && l + 1 < s.length()) {
        l++;
    }
    while (bykv.find(s[r]) == string::npos && r - 1 >= 0) {
        r--;
    }

    return s.substr(l, r - l + 1);
}

int is_def_9(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') {
            return i;
        }
    }
    return -1;
}

bool cmp_9(pair<string, int> x, pair<string, int> y) {
    return x.second > y.second;
}

vector<pair<string, int> > solve_9(vector<string> vvod) {
    map<string, int> m;
    string s;
    for (int i = 0; i < vvod.size(); i++) {
        s = vvod[i];
        s = make_good_9(s);
        //cout << s << "\n";
        int o = is_def_9(s);
        if (o == -1) {
            m[s]++;
        }
        else {
            string cur_1 = s.substr(0, o + 1);
            string cur_2 = s.substr(o + 1, s.length() - o);
            m[cur_1]++;
            m[cur_2]++;
        }
    }
    int k = 0;
    vector<pair<string, int> > ans;
    for (auto cur : m) {
        ans.push_back({ cur.first, cur.second });
    }
    sort(ans.begin(), ans.end(), cmp_9);
    return ans;
}

vector<pair<string, int> > Answer_9(vector<string> vvod) {
    vector<pair<string, int> > ans = solve_9(vvod);
    return ans;
}