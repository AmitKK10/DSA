class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
       int n = nums.size();

        int maxL = nums[0];  // Largest number seen so far
        long long res = 0;   // Stores the max triplet value
        long long bestDiff = 0;  // Best (maxL - nums[j]) seen so far

        for (int i = 1; i < n; i++)
        {
            // Compute the triplet value
            res = max(res, bestDiff * nums[i]);

            // Update best difference seen so far
            bestDiff = max(bestDiff, (long long)(maxL - nums[i]));

            // Update maxL to track the largest element seen
            maxL = max(maxL, nums[i]);
        }

        return res; 
    }
};