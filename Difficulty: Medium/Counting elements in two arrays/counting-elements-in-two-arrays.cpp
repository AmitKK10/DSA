class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
  sort(b.begin(), b.end());  

        vector<int> result;
        for (int i = 0; i < a.size(); i++) {
            
            int count = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
            result.push_back(count);
        }

        return result;
    }
        
};