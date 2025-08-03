class Solution {
  public:
    vector<int> sort012(vector<int>& arr) {
        // code here
        vector<int> temp1,temp2,temp3;
        
        for(int num : arr)
        {
            if(num == 0)
            {
                temp1.push_back(num);
            }
            
            else if(num == 1)
            {
                temp2.push_back(num);
            }
            
            else 
            {
                temp3.push_back(num);
            }
        }
        
        arr.clear();
        
       arr.insert(arr.end(),temp1.begin(),temp1.end());
       arr.insert(arr.end(),temp2.begin(),temp2.end());
       arr.insert(arr.end(),temp3.begin(),temp3.end());
        
        return arr;
    }
};