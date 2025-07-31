class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int Maxsum=INT_MIN;
        int currentSum =0;
        for(int num : arr)
        {
            currentSum += num;
            Maxsum= max(currentSum,Maxsum);
            
            if(currentSum<0)
            {
                currentSum = 0;
            }
        }
        
        return Maxsum;
    }
};