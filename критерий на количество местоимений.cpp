#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string d = "я, ты, он, она, оно, мы, вы, они, себя, мой, твой, ваш, наш, свой, его, её, их, сам";
    string f = "he, she, it, they, we, you";
    string s1, s2;
    s1 = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    s2 = ",.;!?\"'()";
    map <string, int> m;
    int n;
    cin >> n;
    for (int j = 0; j < n; ++j){
        string s;
        cin >> s;
        cout << s << " ";
        for (int i = 0; i < s.size(); i++){
            s[i] = tolower(s[i]);
        }
        if (s2.find(s[s.size() - 1] == -1)){
            s = s.substr(0, s.size() - 1);
        }
        m[s]++;
    }
    cout << endl;
    for (auto i : m) {
        if (d.find(i.first) != string::npos){
            cout << i.first << " " << i.second << endl;
         }
    }
    return 0;
}
