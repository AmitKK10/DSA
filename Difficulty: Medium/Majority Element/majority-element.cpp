class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        
        map<int,int> freq;
        
        for(int num :arr)
        {
           freq[num]++;
        }
        
        for(auto &ans : freq )
        {
            if(ans.second >n/2)
            {
                return ans.first;
            }
        }
        
        return -1;
    }
};