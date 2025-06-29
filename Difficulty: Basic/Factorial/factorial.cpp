class Solution {
  public:
    int factorial(int n) {
        // code here
        int fact =1,i;
        for(i=1;i<=n;i++)
        {
            fact*=i;
        }
        
        return fact;
    }
};