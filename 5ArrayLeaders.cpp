#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        int maxFromRight = arr[n - 1];
        result.push_back(maxFromRight);  
        
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= maxFromRight) {
                maxFromRight = arr[i];
                result.push_back(arr[i]);
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    string input;
    getline(cin, input);  
    vector<int> arr;
    string num = "";

    for (char c : input) {
        if (isdigit(c) || c == '-') {
            num += c;
        } else {
            if (!num.empty()) {
                arr.push_back(stoi(num));
                num.clear();
            }
        }
    }
    if (!num.empty()) arr.push_back(stoi(num)); // last number

    Solution obj;
    vector<int> ans = obj.leaders(arr);

    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
