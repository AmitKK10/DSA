class Solution {
  public:
    // Helper function to check if Koko can eat all bananas at speed s within k hours
    bool canEatAll(vector<int>& arr, int k, int s) {
        long long totalHours = 0;
        for (int bananas : arr) {
            totalHours += (bananas + s - 1) / s;  // Equivalent to ceil(bananas / s)
        }
        return totalHours <= k;
    }

    int kokoEat(vector<int>& arr, int k) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canEatAll(arr, k, mid)) {
                result = mid;
                high = mid - 1; // Try smaller speed
            } else {
                low = mid + 1; // Increase speed
            }
        }
        return result;
    }
};
