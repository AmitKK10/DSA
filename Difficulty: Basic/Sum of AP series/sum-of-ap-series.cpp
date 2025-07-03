
class Solution {
  public:
    long sum_of_ap(long n, long a, long d) {
        // Code here.
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+(a+i*d);
        }
        
        return sum;
    }
};