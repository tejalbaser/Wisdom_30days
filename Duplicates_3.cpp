#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        unordered_set<int> seen;
        unordered_set<int> dup;  
        vector<int> result;

        for (int x : arr) {
            if (seen.count(x)) {
                dup.insert(x);
            } else {
                seen.insert(x);
            }
        }

        for (int x : dup) result.push_back(x);
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<int> a;
    string input;
    getline(cin, input);   

    input.erase(remove(input.begin(), input.end(), '['), input.end());
    input.erase(remove(input.begin(), input.end(), ']'), input.end());

    replace(input.begin(), input.end(), ',', ' ');
    stringstream ss(input);
    int num;
    while (ss >> num) a.push_back(num);

    Solution obj;
    vector<int> result = obj.findDuplicates(a);
    cout << "[";

    for (int i = 0; i < result.size(); i++) {
        if (i > 0) cout << ",";
        cout << result[i];
    }
    cout << "]" << endl;
    return 0;
}

/*
Input:
[2,3,1,2,3]
Output:
[2,3]
*/
