#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sort012(vector<int>& arr) {
        int low = 0, mid = 0, high = arr.size() - 1;
        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[low++], arr[mid++]);
            }
            else if (arr[mid] == 1) {
                mid++;
            }
            else { // arr[mid] == 2
                swap(arr[mid], arr[high--]);
            }
        }
    }
};

int main() {
    string input;
    getline(cin, input); // read full input line

    // Remove unwanted characters [ ] ,
    for (char &c : input) {
        if (c == '[' || c == ']' || c == ',') {
            c = ' ';
        }
    }

    stringstream ss(input);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }

    Solution ob;
    ob.sort012(arr);

    // Output in required format
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

/*
Input:
[0, 1, 2, 1, 0, 2, 1, 0]

Output:
[0, 0, 0, 1, 1, 1, 2, 2]
*/
