#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        long n = *max_element(arr.begin(), arr.end());
        long expec_sum = n * (n + 1) / 2;
        long act_sum = accumulate(arr.begin(), arr.end(), 0L);

        long m = expec_sum - act_sum;
        if (m == 0) {
            return n + 1;
        }
        return m;
    }
};

int main() {
    string input;
    getline(cin, input);
    input.erase(remove(input.begin(), input.end(), '['), input.end());
    input.erase(remove(input.begin(), input.end(), ']'), input.end());
    vector<int> arr;
    stringstream ss(input);
    string num;
    while (getline(ss, num, ',')) {
        if (!num.empty()) {
            arr.push_back(stoi(num));
        }
    }

    Solution sol;
    cout << sol.missingNum(arr) << endl;

    return 0;
}

/*
Input:
[1,2,4,5]
Output:
3
*/
