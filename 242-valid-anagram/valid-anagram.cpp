class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map1,map2;

        if(s.length() != t.length()) return false ;

        for(char ch :s)
        {
            map1[ch]++;
        }

        for(char ch : t)
        {
            map2[ch]++;
        }

       return (map1 == map2)? true :false ;
    }
};