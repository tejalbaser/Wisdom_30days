#include <bits/stdc++.h>
using namespace std;

// Function to count substrings with at most k distinct characters
int atMostKDistinct(string &s, int k) {
    int n = s.size();
    int left = 0, count = 0;
    unordered_map<char, int> freq;

    for (int right = 0; right < n; right++) {
        freq[s[right]]++;

        // shrink window if distinct chars exceed k
        while ((int)freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                freq.erase(s[left]);
            }
            left++;
        }

        // add count of substrings ending at right
        count += (right - left + 1);
    }

    return count;
}

// Function to count substrings with exactly k distinct characters
int exactlyKDistinct(string &s, int k) {
    if (k == 0) return 0;
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int main() {
    string s;
    int k;
    
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;

    cout << exactlyKDistinct(s, k) << endl;

    return 0;
}

Enter string: pqpqs
Enter k: 2
7
