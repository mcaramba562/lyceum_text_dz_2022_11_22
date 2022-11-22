#include <fstream>
#include <iostream>

using namespace std;

int main() {
    string text;
    for (int file = 1; file <= 4; file++) {
        ifstream fin("text" + to_string(file) + "-original.txt");
        ofstream fout("text" + to_string(file) + ".txt");
        while(!fin.eof()) {
            getline(fin, text);
            for (char ch: text) {
                if (ch == -88 || ch == -72) {
                    fout << (char) -72;
                } else if (ch >= -64 && ch <= -33) {
                    fout << (char)(ch + 32);
                } else if (ch >= -33 && ch <= -1 || ch == ' ') {
                    fout << (char) ch;
                }
            }
        }
    }
    return 0;
}
