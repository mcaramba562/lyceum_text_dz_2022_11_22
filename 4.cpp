#include <fstream>
#include <string>
#include <map>
#include <windows.h>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string s;
    string s3 = "аб";
    fout << s3 << endl;
    map <string, int> m;
    while (getline(fin, s)) {
    for (int i = 0; i < s.size(); ++i) {
        string s1 = "";
        s1 += toupper(s[i]) + toupper(s[i + 1]);
        fout << s1;
        if (s1 == "СТ"){
            m["СТ"]++;
        }
        if (s1 == "НО"){
            m["НО"]++;
        }
        if (s1 == "ЕН"){
            m["ЕН"]++;
        }
        if (s1 == "ТО"){
            m["ТО"]++;
        }
        if (s1 == "НА"){
            m["НА"]++;
        }
        if (s1 == "ОВ"){
            m["НИ"]++;
        }
        if (s1 == "РА"){
            m["РА"]++;
        }
        if (s1 == "ВО"){
            m["ВО"]++;
        }
        if (s1 == "КО"){
            m["КО"]++;
        }
        string s2 = "";
        s2 += s[i] + s[i + 1] + s[i + 2];
        if (s2 == "СТО"){
            m["СТО"]++;
        }
        if (s2 == "ЕНО"){
            m["ЕНО"]++;
        }
        if (s2== "НОВ"){
            m["НОВ"]++;
        }
        if (s2 == "ТОВ"){
            m["ТОВ"]++;
        }
        if (s2 == "ОВО"){
            m["ОВО"]++;
        }
        if (s2 == "ОВА"){
            m["ОВА"]++;
        }
    }
    }
    for (auto i : m) {
        fout << i.first << " " << i.second << endl;
    }

    return 0;
}
