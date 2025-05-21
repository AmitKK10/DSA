class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
        if (m > n) swap(m, n);

        int low = 1, high = m * n;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;

            for (int i = 1; i <= m; ++i) {
                count += min(mid / i, n);
            }

            if (count < k) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};
