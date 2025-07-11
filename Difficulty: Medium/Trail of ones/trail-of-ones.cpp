class Solution {
  public:
    int countConsec(int n) {
        // code here
         int a[n + 1], b[n + 1];
        a[1] = 1; // ending with 0
        b[1] = 1; // ending with 1

        for (int i = 2; i <= n; i++) {
            a[i] = a[i - 1] + b[i - 1];
            b[i] = a[i - 1];
        }

        int totalStrings = 1 << n; // 2^n
        int noConsecutiveOnes = a[n] + b[n];
        return totalStrings - noConsecutiveOnes;
    }
};