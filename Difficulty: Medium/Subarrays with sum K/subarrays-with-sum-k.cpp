class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
         map<int, int> prefixSums; // To store how many times each prefix sum appears
        int currentSum = 0;
        int totalSubarrays = 0;

        prefixSums[0] = 1; // Base case: A subarray that starts from index 0

        for (int i = 0; i < arr.size(); i++) {
            currentSum += arr[i]; // Add the current number to running sum

            // Check if there is a previous prefix sum that makes currentSum - k
            int requiredSum = currentSum - k;

            if (prefixSums.find(requiredSum) != prefixSums.end()) {
                totalSubarrays += prefixSums[requiredSum];
            }

            // Store or update the current prefix sum in the map
            prefixSums[currentSum]++;
        }

        return totalSubarrays;
        
    }
};