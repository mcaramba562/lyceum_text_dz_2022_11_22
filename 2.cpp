#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;
///1-ый текст -- 5.83588
///2-ой текст -- 5.86545
///3-ий текст -- 6.01581
///4-ый текст -- 4.99298

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n  = 30, g = 0,k = 0,f = 0;/// n -- количетсво строк
    double r = 0;
    string st,s;
    s = "йцукенгшщзхъэждлорпавыфячсмитьбюЙЦУКЕНГШЩЗХЪЭЖДЛОРПАВЫФЯЧСМИТЬБЮЁё";
    ifstream fin("input.txt");
    ofstream fout ("output.txt");
    /// считает среднюю длину слов, только строка должна начинаться на букву

    for (int i = 1; i<= n; i++){

        getline(fin, st);
        g  = st.length();

        for  (int  i = 0; i < g; i ++){ /// считает количество букв
            if (s.find(st[i]) != -1){
                k ++;
            }
            if ((st[i] == ' ')(st[i] == ',')(st[i] == '.')  (st[i] == ':')  (st[i] == '?')  (st[i] == '!')  (st[i] == '"') || (st[i] == '@')){
                if(s.find(st[i-1]) != -1){ /// считает количество слов
                   f ++;

                }
            }

        }

     }
     r = k;
      r = r / f;
    fout <<  " среднее значение = "  << r << endl;

    return 0;
}
