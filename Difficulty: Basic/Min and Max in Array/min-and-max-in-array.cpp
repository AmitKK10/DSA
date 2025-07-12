// User function Template for C++
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        // code here
        int n =arr.size();
        
        if(n==0) return {0,0};
        
            int min= arr[0];
            int max= arr[0];
            
            for(int i=1;i<n;i++)
            {
                if(arr[i]<min)
                {
                    min=arr[i];
                }
                
                 if(arr[i]>max)
                {
                    max=arr[i];
                }
                
            }
                
        return {min,max};
        
    }
};