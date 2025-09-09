// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string ans="";
        
        sort(arr.begin(),arr.end());
        
        int n = arr.size();
        
        string first = arr[0];
        string last = arr[n-1];
        
        for(int i =0 ;i<first.length() && i<last.length();i++)
        {
            if(first[i] == last[i])
            {
                ans+=first[i];
            }
            
            else break;
        }
        
        return ans;
    }
};