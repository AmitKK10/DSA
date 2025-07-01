class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int ans = 0;
        unordered_map<char, int> mp;
        int i = 0, n = s.size();
        while (i < k){
            mp[s[i]]++;
            i++;
        }
        if (mp.size() == k-1) ans++;
        int j = i;
        i = 0;
        while (j < n){
            mp[s[j]]++;
            mp[s[i]]--;
            if (mp[s[i]] == 0) mp.erase(s[i]);
            if (mp.size() == k-1) ans++;
            j++;
            i++;
        }
        return ans;
    }
};