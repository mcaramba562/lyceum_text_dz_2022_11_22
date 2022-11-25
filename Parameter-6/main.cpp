#include <fstream>

using namespace std;

long long words[4] = {0, 0, 0, 0};

string vowels = "";

int main() {
    vowels.push_back(-1);
    vowels.push_back(-2);
    vowels.push_back(-3);
    vowels.push_back(-5);
    vowels.push_back(-13);
    vowels.push_back(-18);
    vowels.push_back(-24);
    vowels.push_back(-27);
    vowels.push_back(-32);
    vowels.push_back(-72);

    string text;
    bool first, second;
    for (int file = 1; file <= 4; file++) {
        ifstream fin("text" + to_string(file) + ".txt");
        ofstream fout("text" + to_string(file) + "-results.txt");
        getline(fin, text);
        for (size_t prev_pos = -1, pos = text.find(' ');
             pos != string::npos; prev_pos = pos, pos = text.find(' ', pos + 1)) {
            if (pos - prev_pos - 1 > 1) {
                first = vowels.find(text[prev_pos + 1]) != string::npos;
                second = vowels.find(text[prev_pos + 2]) != string::npos;
                words[first + 2 * second]++;
            }
        }
        fout << words[0] << " " << words[1] << " " << words[2] << " " << words[3];
    }
    return 0;
}
