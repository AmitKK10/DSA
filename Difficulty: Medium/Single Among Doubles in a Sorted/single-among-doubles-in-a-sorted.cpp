class Solution {
  public:
    int findOnce(vector<int>& arr) {
        // code here.
        int xo=0;
        for(int i=0;i<arr.size();i++)
        {
            xo= xo xor arr[i];
        }
        
        return xo;
    }
};