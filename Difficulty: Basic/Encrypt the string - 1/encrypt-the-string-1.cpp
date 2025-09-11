

class Solution {
  public:
    string encryptString(string s) {
        // code here
      int n= s.length();
      int count=1;
      char ch = s[0];
      string ans ="";
      
      for(int i=1;i<n;i++)
      {
          if(s[i] == ch)
          {
              count++;
          }
          
          else 
          {
               ans+=ch;
              ans+=to_string(count);
              count=1;
              ch=s[i];
          }
      }
      
      ans+=ch;
      ans+=to_string(count);
   
      reverse (ans.begin(),ans.end());
      
      return ans;
    }
};