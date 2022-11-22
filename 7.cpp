#include <iostream>
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

string make_good(string s) {
    int l = 0, r = s.length() - 1;
    string russk_m = "йцукенгшщзхъфывапролджэячсмитьбю";
    string russk_b = "йцукенгшщзхъфывапролджэячсмитьбю";
    for (int i = 0; i < s.length(); i++) {
        if (russk_b.find(s[i]) != string::npos) {
            s[i] = russk_m[russk_b.find(s[i])];
        }
        else {
            s[i] = tolower(s[i]);
        }
    }
    string bykv = "qwertyuiopasdfghjkzxcvbnmQWERTYUIOOPASDFGHJKLZXCVBNMйцукенгшщзхъфывапролджэячсмитьбюю";
    while (bykv.find(s[l]) == string::npos) {
        //cout << s[l] << " " << l << "\n";
        l++;
    }
    while (bykv.find(s[r]) == string::npos) {
        //cout << s[r] << " " << r << "\n";
        r--;
    }
    //cout << s << " " << l << " " << r << " " << s.substr(l, r - l + 1) << "\n";
    //return s;
    return s.substr(l, r - l + 1);
}

int is_def(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '-') {
            return i;
        }
    }
    return -1;
}

void solve() {
    string s;
    vector<string> a;
    while (cin >> s) {
        s = make_good(s);
        //cout << s << "\n";
        int o = is_def(s);
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
    string gl = "еаояиюыуэ";
    string sogl = "йцкнгшщзхъфвпрлджчсмтьб";

    int ans_gl = 0, ans_sogl = 0;
    for (int i = 0; i < a.size(); i++) {
        int f = 0, s = 0;
        for (int j = 0; j < a[i].size(); j++) {
            if (gl.find(a[i][j]) != string::npos) {
                cout << a[i][j] << " " << i << " " << j << "\n";
                f++;
            }
            else if (sogl.find(a[i][j]) != string::npos) {
                s++;
            }
            if (f == 3) {
                f = 0;
                ans_gl++;
            }
            if (s == 3) {
                s = 0;
                ans_sogl++;
            }
        }
    }
    cout << ans_gl << " " << ans_sogl;
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
    while (t--) {
        solve();
    }
    return 0;
}
