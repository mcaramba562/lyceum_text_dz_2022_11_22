#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string s;
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,i,sum;
    while (!fin.eof())
    {
    getline(fin,  s);

    for (i=0;i<s.length();i++)
    {
        if (s[i]=='.')
            a++;
        if (s[i]==',')
            b++;
        if (s[i]=='Ч')
            c++;
        if (s[i]==':')
            d++;
        if (s[i]==';')
            e++;
        if (s[i]=='!')
            f++;
        if (s[i]=='?')
            g++;
    }}
    sum=a+b+c+d+e+f+g;
    fout<<'.'<<" "<<a<<endl<<','<<" "<<b<<endl<<'Ч'<<" "<<c<<endl<<':'<<" "<<d<<endl<<';'<<" "<<e<<endl<<'!'<<" "<<f<<endl<<'?'<<" "<<g<<endl<<"всего"<<" "<<sum;
    return 0;
}
