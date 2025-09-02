class Solution {
  public:
    string modify(string& s) {
        // code here.
        
        string result = "";
        
        for(char ch : s)
        {
            if(ch == ' ') continue;
            else result+=ch;
        }
        
        return result;
    }
};