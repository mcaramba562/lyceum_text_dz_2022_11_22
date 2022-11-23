#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <cmath>
#include <stack>
#include <list>
#include <cstring>
#include <Windows.h>

#define fast_io std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1791791791;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define ld long double

const int INF = 1000000000;
const ll INFll = 1000000000000000000ll;


string make_good_9(string s) {
    int l = 0, r = s.length() - 1;
    string russk_m = "йцукенгшщзхъфывапролджэячсмитьбю";
    string russk_b = "ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ";
    for (int i = 0; i < s.length(); i++) {
        if (russk_b.find(s[i]) != string::npos) {
            s[i] = russk_m[russk_b.find(s[i])];
        }
        else {
            s[i] = tolower(s[i]);
        }
    }
    
    string bykv = "qwertyuiopasdfghjkzxcvbnmQWERTYUIOOPASDFGHJKLZXCVBNMйцукенгшщзхъфывапролджэячсмитьбюЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ";
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
        //fout << cur.first << ": " << cur.second << "\n";
        //k++;
        ans.push_back({ cur.first, cur.second });
    }
    sort(ans.begin(), ans.end(), cmp_9);
    return ans;
}

signed main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast_io;
    ll t = 1;
    //cin >> t;
    vector<string> vvod;
    string s;
    while (cin >> s)vvod.push_back(s);
    while (t--) {
        vector<pair<string, int> > ans = solve_9(vvod);
        int k = 0;
        for (auto cur : ans) {
            cout << cur.first << " " << cur.second << "\n";
            k++;
            if (k == 15) {
                break;
            }
        }
    }
    return 0;
}
