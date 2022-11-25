#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    string s1 = "ф, ч, х, ц, щ, ш, ж";
    map <char, int> m;
    for (int i = 0; i < s.size(); i++){
        if (s1.find(tolower(s[i])) != -1) {
            m[s[i]]++;
        }
    }
    for (auto i : m) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
