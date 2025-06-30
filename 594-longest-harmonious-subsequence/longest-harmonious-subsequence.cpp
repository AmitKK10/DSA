class Solution {
public:
    int findLHS(vector<int>& nums) {
          unordered_map<int, int> freqMap;

        // Step 1: Count frequency of each number
        for (int num : nums) {
            freqMap[num]++;
        }

        int maxLength = 0;

        // Step 2: Check for each number if num + 1 exists
        for (auto it : freqMap) {
            int num = it.first;
            if (freqMap.find(num + 1) != freqMap.end()) {
                int length = freqMap[num] + freqMap[num + 1];
                maxLength = max(maxLength, length);
            }
        }

        return maxLength;
    }
};