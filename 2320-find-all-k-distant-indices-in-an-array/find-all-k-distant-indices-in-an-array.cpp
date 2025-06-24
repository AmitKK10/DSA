class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& num, int key, int k) {
        int n = num.size();
        vector<int>newNum;
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<n;j++)
            {
                 if(num[j] == key && abs(i - j) <= k)
                  
                  {
                    newNum.push_back(i);
                    break;
                  }
            }

           
        }
        return newNum;
    }
};