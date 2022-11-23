#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    string s;
    getline(fin, s);

    string vowels_b = "ЁУЕЫАОЭЯИЮ";
    string vowels = "ёуеыаоэяию";
    string consonants = "йцкнгшщзхъфвпрлджчсмтьб";
    string consonants_b = "ЙЦКНГШЩЗХЪФВПРЛДЖЧСМТЬБ";

    s = ' ' + s + ' ';

    int v_with_v_in_right = 0, v_with_v_in_left = 0, v_with_c_in_left = 0, v_with_c_in_right = 0;
    int c_with_v_in_right = 0, c_with_v_in_left = 0, c_with_c_in_left = 0, c_with_c_in_right = 0;
    //int v_b_in_right = 0, v_b_in_left = 0, c_b_in_left = 0, c_b_in_right = 0;
    for(int i = 1;i < s.size()-1; i++)
    {
       if(vowels.find(s[i]) != -1 || vowels_b.find(s[i]) != -1)
       {
           if(vowels.find(s[i-1]) != -1 || vowels_b.find(s[i-1]) != -1)
            v_with_v_in_left ++;
           if(vowels.find(s[i+1]) != -1 || vowels_b.find(s[i+1]) != -1)
            v_with_v_in_right ++;
           if(consonants.find(s[i-1]) != -1 || consonants_b.find(s[i-1]) != -1)
            v_with_c_in_left ++;
           if(consonants.find(s[i+1]) != -1 || consonants_b.find(s[i+1]) != -1)
            v_with_c_in_right ++;
       }
       if(consonants.find(s[i]) != -1 || consonants_b.find(s[i]) != -1)
       {
           if(vowels.find(s[i-1]) != -1 || vowels_b.find(s[i-1]) != -1)
            c_with_v_in_left ++;
           if(vowels.find(s[i+1]) != -1 || vowels_b.find(s[i+1]) != -1)
            c_with_v_in_right ++;
           if(consonants.find(s[i-1]) != -1 || consonants_b.find(s[i-1]) != -1)
            c_with_c_in_left ++;
           if(consonants.find(s[i+1]) != -1 || consonants_b.find(s[i+1]) != -1)
            c_with_c_in_right ++;
       }
    }

    fout << "Согласных перед согласной : " << c_with_c_in_left << endl;
    fout << "Гласных перед согласной : " << c_with_v_in_left << endl;
    fout << "Согласных после согласной : " << c_with_c_in_right << endl;
    fout << "Гласных после согласной : " << c_with_v_in_right << endl;

    fout << "Согласных перед гласной : " << v_with_c_in_left << endl;
    fout << "Гласных перед гласной : " << v_with_v_in_left << endl;
    fout << "Согласных после гласной : " << v_with_c_in_right << endl;
    fout << "Гласных после гласной : " << v_with_v_in_right << endl;

    return 0;
}
