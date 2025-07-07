class Solution {
  public:
    long sum_of_gp(long n, long a, long r) {
        // Code here
        if (r == 1) {
            return a * n;
        }
        
        long result = 0;
        long term = a;
        for (long i = 0; i < n; ++i) {
            result += term;
            term *= r;
        }
        
        return result;

    }
};