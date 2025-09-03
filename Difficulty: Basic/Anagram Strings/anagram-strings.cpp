// User function Template for C++
class Solution {
  public:
    int areAnagram(string S1, string S2) {
        // code here
        
     unordered_map<char,int> map1,map2;
        
     
        if(S1.length() != S2.length() ) return 0;
     
            for(char ch : S1)
            {
                map1[ch]++;
            }
            
             for(char ch: S2)
            {
                map2[ch]++;
            }
        
        return (map1==map2) ? 1:0;
    }
};