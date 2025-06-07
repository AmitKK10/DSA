class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        // TIME: 23mins
        // maybe we can do by hashing
        unordered_map<int,int>mp;
        int n=a1.size();
        vector<int>pre1(n,0);
        vector<int>pre2(n,0);
        int ans=0;
        pre1[0]=a1[0];
        pre2[0]=a2[0];
        mp[0]=-1;
        
        if(pre1[0]==pre2[0]){
            ans=1;
        }
        int diff=pre2[0]-pre1[0];
        if(mp.find(diff)==mp.end()){
            mp[diff]=0;
        }
        
        for(int i=1;i<n;i++){
            pre1[i]=pre1[i-1]+a1[i];
            pre2[i]=pre2[i-1]+a2[i];
            // suppose a sum is bigger then we can find a
            // index such that prefix sum of both is equal to diff
            // pre1[0..i-1]+pre1[i..j] = sum1
            // pre2[0..i-1]+pre2[i..j] = sum2
            // if sum2=sum1+diff
            // pre2[0..i-1]-pre1[0..i-1] = diff
            // so we can store this i index in our unordered map
            diff=pre2[i]-pre1[i];
            if(mp.find(diff)!=mp.end()){
                int idx=mp[diff];
                ans=max(ans,i-idx);
            }
            if(mp.find(diff)==mp.end()){
                mp[diff]=i;
            }
        }
        return ans;
    }
};