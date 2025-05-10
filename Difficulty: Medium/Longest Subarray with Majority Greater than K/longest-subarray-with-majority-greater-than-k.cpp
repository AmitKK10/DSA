//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
  
   int n = arr.size();
    vector<int> transformed(n);

    // Step 1: Transform array
    for (int i = 0; i < n; ++i) {
        transformed[i] = (arr[i] > k) ? 1 : -1;
    }

    unordered_map<int, int> first_occurrence;
    int prefixSum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; ++i) {
        prefixSum += transformed[i];

        // If prefixSum is positive, the whole subarray [0...i] is valid
        if (prefixSum > 0) {
            maxLength = i + 1;
        }

        // If prefixSum seen before, check for subarray length
        if (first_occurrence.find(prefixSum - 1) != first_occurrence.end()) {
            maxLength = max(maxLength, i - first_occurrence[prefixSum - 1]);
        }

        // Store the first occurrence of this prefixSum
        if (first_occurrence.find(prefixSum) == first_occurrence.end()) {
            first_occurrence[prefixSum] = i;
        }
    }

    return maxLength;
    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends