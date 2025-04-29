class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_val = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        int count_max = 0;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (nums[right] == max_val) {
                count_max++;
            }
            while (count_max >= k) {
                ans += (n - right);
                if (nums[left] == max_val) {
                    count_max--;
                }
                left++;
            }
        }
        
        return ans;
    }
};