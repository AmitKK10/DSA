class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
       sort(nums.begin(), nums.end());
        const int n = nums.size();
        long long res = 0;
        int l = n-1, r = n-1;
        for (int i = 0; i < n-1; ++i) {
            int loTh = lower - nums[i], hiTh = upper - nums[i];
            while (l > i && nums[l] > hiTh) --l;
            while (r > i && nums[r] >= loTh) --r;
            if (l > i) res += l - max(r, i);
        }
        return res;  
    }
};