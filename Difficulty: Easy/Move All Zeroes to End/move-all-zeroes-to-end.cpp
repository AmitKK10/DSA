// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int countZero = 0;
        int n = arr.size();
        vector<int> temp;
        
        for(int num:arr)
        {
            if(num != 0)
            {
                 temp.push_back(num);
            }
            
            else 
            {
              countZero++;
            }
        }
        
        temp.insert(temp.end(),countZero,0);
        
        arr = temp;
        
       
    }
};