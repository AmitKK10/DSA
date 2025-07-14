class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
      
         if (arr.size() < 2) return -1;

        int max1, max2;

        // Initialize max1 and max2
        if (arr[0] > arr[1]) {
            max1 = arr[0];
            max2 = arr[1];
        } else if (arr[0] < arr[1]) {
            max1 = arr[1];
            max2 = arr[0];
        } else {
            max1 = max2 = arr[0];
        }

        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] > max1) {
                max2 = max1;
                max1 = arr[i];
            } else if (arr[i] < max1 && arr[i] > max2) {
                max2 = arr[i];
            }
        }

        // If max1 == max2, it means no second largest distinct value
        if (max1 == max2) {
            return -1;
        } else {
            return max2;
        }
        
    }
};