class Solution {
  public:
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
         int n = arr.size();
        
        // Binary search on the answer (minimum height)
        int left = 0, right = k + *max_element(arr.begin(), arr.end());
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if we can achieve minimum height of 'mid'
            if (canAchieveMinHeight(arr, k, w, mid)) {
                result = mid;  // This height is achievable
                left = mid + 1;  // Try for a higher minimum height
            } else {
                right = mid - 1;  // This height is too high, try lower
            }
        }
        
        return result;
    }
    
private:
    bool canAchieveMinHeight(vector<int>& arr, int k, int w, int targetMin) {
        int n = arr.size();
        vector<int> heights = arr;  
        int watersUsed = 0;
    
        for (int i = 0; i < n; i++) {
          
            if (heights[i] < targetMin) {
                int needed = targetMin - heights[i];  
              
                if (watersUsed + needed > k) {
                    return false;  
                }
            
                int startPos = i;
                int endPos = min(i + w - 1, n - 1);  // End of watering window
                
                // Add 'needed' amount of water to all flowers in the window
                for (int j = startPos; j <= endPos; j++) {
                    heights[j] += needed;
                }
                
                watersUsed += needed;  // Update total watering days used
            }
        }
        
        return true; 
    }
};