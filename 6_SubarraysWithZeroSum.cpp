#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findSubarraysWithZeroSum(vector<int> &arr) {
    unordered_map<long long, vector<int>> prefixMap;
    vector<pair<int, int>> result;
    long long prefixSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];
        if (prefixSum == 0) {
            result.push_back({0, i});
        }
        if (prefixMap.find(prefixSum) != prefixMap.end()) {
            for (int startIdx : prefixMap[prefixSum]) {
                result.push_back({startIdx + 1, i});
            }
        }
        prefixMap[prefixSum].push_back(i);
    }
    return result;
}

int main() {
    vector<int> arr;
    string line;
    cout << "Enter input: ";
    getline(cin, line);
    string clean = "";
    for (char c : line) {
        if (c != '[' && c != ']' && c != ',') {
            clean += c;
        }
    }

    stringstream ss(clean);
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    vector<pair<int, int>> result = findSubarraysWithZeroSum(arr);

    if (result.empty()) {
        cout << "Output: []" << endl;
    } else {
        cout << "Output: [";
        for (int i = 0; i < result.size(); i++) {
            cout << "(" << result[i].first << ", " << result[i].second << ")";
            if (i != result.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}

/*
Enter input: [4, -1, -3, 1, 2, -1]
Output: [(0, 2),(2, 4)]

*/
