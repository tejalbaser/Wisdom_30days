#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // sorted string as key
            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& it : mp) {
            result.push_back(it.second);
        }
        return result;
    }
};

int main() {
    vector<string> strs;
    string input;
    
    cout << "Enter strings:\n";
    getline(cin, input);

    // Trim spaces
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    if (input[0] == '[') {
        // Array format: ["eat","tea","tan"]
        string temp;
        for (int i = 0; i < input.size(); i++) {
            if (isalpha(input[i])) {
                temp.push_back(input[i]);
            } else {
                if (!temp.empty()) {
                    strs.push_back(temp);
                    temp.clear();
                }
            }
        }
    } else {
        // Space-separated format
        stringstream ss(input);
        string word;
        while (ss >> word) {
            strs.push_back(word);
        }
    }

    Solution sol;
    vector<vector<string>> ans = sol.groupAnagrams(strs);

    cout << "Output: [";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << "\"" << ans[i][j] << "\"";
            if (j < ans[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < ans.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}

/*
Enter strings:
["eat","tea","tan","ate","nat","bat"]

Output: [["bat"], ["tan", "nat"], ["eat", "tea", "ate"]]
*/
