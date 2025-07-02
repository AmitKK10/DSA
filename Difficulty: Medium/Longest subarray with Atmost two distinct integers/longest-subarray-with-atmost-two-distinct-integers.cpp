class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
       int n = arr.size();
        int start = 0, maxLen = 0;
        unordered_map<int, int> freq;

        for (int end = 0; end < n; ++end) {
            freq[arr[end]]++;

            // If more than 2 distinct elements, shrink the window
            while (freq.size() > 2) {
                freq[arr[start]]--;
                if (freq[arr[start]] == 0) {
                    freq.erase(arr[start]);
                }
                start++;
            }

            // Update maximum length of valid window
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};