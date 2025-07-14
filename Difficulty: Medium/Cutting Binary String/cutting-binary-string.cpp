class Solution {
  public:
    bool isPowerOfFive(long long num) {
        if (num <= 0) return false;
        while (num % 5 == 0) {
            num /= 5;
        }
        return num == 1;
    }

    int cuts(string s) {
        int n = s.length();
        const int INF = 1e9;
        vector<int> dp(n + 1, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') continue; // no leading zeros allowed
            long long num = 0;
            for (int j = i; j < n; j++) {
                num = num * 2 + (s[j] - '0'); // convert binary to decimal
                if (isPowerOfFive(num)) {
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
                }
            }
        }

        return dp[0] >= INF ? -1 : dp[0];
    }
};