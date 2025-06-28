class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
    
    int n = nums.size();
        
        // Step 1: Create pairs of (value, original_index)
        // This helps us track where each element came from
        vector<pair<int, int>> valueIndexPairs;
        for (int i = 0; i < n; i++) {
            valueIndexPairs.push_back({nums[i], i});
        }
        
        // Step 2: Sort by value in descending order
        // We want the largest values first
        sort(valueIndexPairs.begin(), valueIndexPairs.end(), greater<pair<int, int>>());
        
        // Step 3: Extract indices of the k largest elements
        vector<int> selectedIndices;
        for (int i = 0; i < k; i++) {
            selectedIndices.push_back(valueIndexPairs[i].second);
        }
        
        // Step 4: Sort the selected indices to maintain original order
        // This is crucial to preserve the subsequence property
        sort(selectedIndices.begin(), selectedIndices.end());
        
        // Step 5: Build the result using the sorted indices
        vector<int> result;
        for (int index : selectedIndices) {
            result.push_back(nums[index]);
        }
        
        return result;

    }
};