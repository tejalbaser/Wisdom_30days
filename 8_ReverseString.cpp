#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

static inline void trim(string &s) {
    size_t i = 0, j = s.size();
    while (i < j && isspace(static_cast<unsigned char>(s[i]))) ++i;
    while (j > i && isspace(static_cast<unsigned char>(s[j - 1]))) --j;
    s = s.substr(i, j - i);
}

static inline void stripWrappingQuotes(string &s) {
    if (s.size() >= 2) {
        char a = s.front(), b = s.back();
        if ((a == '"' && b == '"') || (a == '\'' && b == '\'')) {
            s = s.substr(1, s.size() - 2);
        }
    }
}

string reverseWords(string s) {
    trim(s);
    stripWrappingQuotes(s); 
    trim(s);              
    istringstream iss(s);
    vector<string> words;
    string w;
    while (iss >> w) words.push_back(w); 
    reverse(words.begin(), words.end());

    ostringstream oss;
    for (size_t i = 0; i < words.size(); ++i) {
        if (i) oss << ' ';
        oss << words[i];
    }
    return oss.str();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);           
    cout << "\"" << reverseWords(s) << "\"" << '\n';
    return 0;
}

/*
Input:"the sky is blue"
Output:"blue is sky the"
*/
