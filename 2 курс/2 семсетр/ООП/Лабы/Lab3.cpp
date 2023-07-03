#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compareStrings(const string& s1, const string& s2) {
    bool s1_russian = (s1[0] >= 'А' && s1[0] <= 'Я' || s1[0] >= 'а' && s1[0] <= 'я');
    bool s2_russian = (s2[0] >= 'А' && s2[0] <= 'Я' || s2[0] >= 'а' && s2[0] <= 'я');
    if (s1_russian && !s2_russian) {
        return true;
    }
    else if (!s1_russian && s2_russian) {
        return false;
    }
    else {
        return s1 < s2;
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    vector<string> sources;
    ifstream file("literature.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            sources.push_back(line);
        }
        file.close();
    }
    else {
        cerr << "Unable to open file\n";
        return 1;
    }
    sort(sources.begin(), sources.end(), compareStrings);
    for (const auto& s : sources) {
        cout << s << endl;
    }
    return 0;
}
