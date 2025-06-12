class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int dif=0;
        for(int i=0;i<n;i++)
        { int next = (i+1)%n;
            int new_dif = abs(nums[i]-nums[next]);
            dif = max(dif,new_dif);
        }

      return dif;
    }
};