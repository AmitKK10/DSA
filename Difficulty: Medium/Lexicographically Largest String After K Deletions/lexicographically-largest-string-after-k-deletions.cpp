class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
         int n = s.size();
        string res = "";
        res.push_back(s[0]);
        
        for (int i = 1; i < n; i++) {
            if (res.size() > 0) {
                
                while (k && res.size() && res.back() < s[i]) {
                    res.pop_back();
                    k--;
                }
            }

            res.push_back(s[i]);
            
        }
        
        while (k--) res.pop_back();

        return res;
    }
};
