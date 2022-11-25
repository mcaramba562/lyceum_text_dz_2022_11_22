#include <fstream>
#include <string>
#include <map>
#include <clocale> 

using namespace std;

int main() { 
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    setlocale(LC_ALL, "rus");
    string s = "СТ";
    fout << s[0] << " " << s[1];
    /* 
    string s;
    getline(fin, s);
    s += "  ";
    fout << s << endl;
    map <string, int> m;
    for (int i = 0; i < s.size() - 1; ++i) {
        string s1 = "";
        s1 += s[i] + s[i + 1];
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
    fout << m["СТ"];
    */
    return 0;
}
