class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        map<int,int> freq;
        for(int num : arr)
        {
            freq[num]++;
            if(freq[num]>n/2)
            {
                return num ;
            }
        }
        
        return -1;
    }
};