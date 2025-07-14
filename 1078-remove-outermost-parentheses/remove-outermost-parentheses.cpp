class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int count=0;
        string ans;
        for(char ch : s)
        {
            if(ch == '(' )
            {
                 count++;
               if(count>1)
               {
                  ans.push_back(ch);
               }
            }

            else if(ch == ')') 
            {
                count--;

                if(count>0)
                {
                    ans.push_back(ch);
                }
            }

        }

        return ans;
    }
};