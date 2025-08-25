class Solution {
public:

bool isAlphaNumeric(char ch )
        {
            return ((ch >= '0' && ch <= '9') ||
             (ch >= 'a' && ch <= 'z') ||
             (ch >= 'A' && ch <= 'Z'));
        }
        
    bool isPalindrome(string s) {

        int start =0;
        int end = s.size()-1;

        while ( start<end)
        {
            if(! isAlphaNumeric(s[start]))
            {
                start++;
                continue;
            }

            else if (! isAlphaNumeric(s[end]))
            {
                end--;
                continue;
            }

            else if (tolower(s[start++]) != tolower(s[end--] ))
            {
                return false ;
            }
        }

        return true;
    }
};