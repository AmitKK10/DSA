class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxdiff=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {   
                int diff=0;
                if(nums[j]>nums[i])
                {
                    diff= nums[j]-nums[i];
                    maxdiff = max(diff,maxdiff);
                     
                }
                
            }
          
        }

             return maxdiff;
    }
};