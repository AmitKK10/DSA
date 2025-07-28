

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n= arr.size();
   int rightMax= arr[n-1];
   vector<int> leader;
   leader.push_back(rightMax);
   
   for(int i =n-2;i>=0;i--)
   {
     if(arr[i]>=rightMax)
     {
        leader.push_back(arr[i]);
        rightMax = arr[i];
        
     }
   }

   reverse(leader.begin(),leader.end());
       return leader;

        
    }
};