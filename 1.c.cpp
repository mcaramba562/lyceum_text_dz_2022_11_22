#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    string s_zvonkie = "б, в, г, д, ж, з";
    string s_gluhie = "к, п, с, т, ф, х, ц, ш";
    map <char, int> m_zvonkie;
    map <char, int> m_gluhie;
    for (int i = 0; i < s.size(); i++){
        if (s_zvonkie.find(tolower(s[i])) != -1) {
            m_zvonkie[tolower(s[i])]++;
        }
        if (s_gluhie.find(tolower(s[i])) != -1) {
            m_gluhie[tolower(s[i])]++;
        }
    }
    cout << "ГЛУХИЕ" << endl;
    for (auto i : m_zvonkie) {
        cout << i.first << " " << i.second << endl;
    }
    cout << "ЗВОНКИЕ" << endl;
    for (auto i : m_gluhie) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
