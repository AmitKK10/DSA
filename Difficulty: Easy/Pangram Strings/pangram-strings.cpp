// User function template for C++
class Solution {
  public:

    int isPanagram(string S) {
        // Your code goes here
        
        set<char> s;
        
        for(char ch : S)
        {
            if(isalpha(ch))
            {
                s.insert(tolower(ch));
                
            }
            
        }
        
        return (s.size() == 26)?1:0;
    }
};