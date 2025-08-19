class Solution {
  public:
    bool isPalindrome(string& s) {
        // code here
        
        int low =0;
        int high =s.size() -1;
        
        while(low<high)
        {
            
            if(s[low] != s[high])
            {   
                return false;
                
            }
            
            low++;
            high--;
        }
        
        return true ;
    }
};