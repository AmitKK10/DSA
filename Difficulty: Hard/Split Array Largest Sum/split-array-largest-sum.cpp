class Solution {
  public:
    bool isValid(vector<int>& arr, int k, int maxSum) {
        int count = 1;
        int currentSum = 0;
        
        for (int num : arr) {
            if (currentSum + num > maxSum) {
                count++;
                currentSum = num;
                if (count > k) return false;
            } else {
                currentSum += num;
            }
        }
        return true;
    }
    int splitArray(vector<int>& arr, int k) {
        // code here
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isValid(arr, k, mid)) {
                result = mid;
                high = mid - 1;  // try to minimize the max sum
            } else {
                low = mid + 1;  // need a larger max sum
            }
        }
        
        return result;
    }
};