class Solution {
  public:
    int binaryToDecimal(string &b) {
        // Code here.
        int n =b.length();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(b[i]=='1')
            {
                sum+=pow(2,n-1-i);
            }
            
        }
        
        return sum;
    }
};