class Solution {
  public:
    long missingNum(vector<int>& arr) {
        // code here
        
        long long  n = arr.size();
        long long TotSum = ((n+1)*(n+2))/2;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        
        return TotSum - sum;
    }
};