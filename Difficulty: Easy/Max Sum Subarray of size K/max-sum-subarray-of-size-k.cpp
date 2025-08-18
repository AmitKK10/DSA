class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
         int n = arr.size();
        if (n < k) return -1; 
        int sum=0;
       for(int i=0;i<k;i++)
       {
           sum+=arr[i];
       }
       
       int maxsum = sum;
       
       for(int i=1;i<=n-k;i++)
       {
           sum=sum-arr[i-1]+arr[i+k-1];
           
           maxsum = max(maxsum,sum);
           
       }
        return maxsum;
    }
};