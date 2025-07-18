class Solution {
public:
    long long kMirror(int k, int n) {
       auto ispk=[&](long long x){
            long long t=x,rev=0;
            while(t){
                rev=rev*k + t%k;
                t/=k;
            }
            return rev==x;
        };
        long long ans=0;
        int cnt=0;
        long long pow10[12]; pow10[0]=1;
        for(int i=1;i<12;i++) pow10[i]=pow10[i-1]*10;
        for(int len=1;cnt<n;++len){
            int half=(len+1)/2;
            long long start=pow10[half-1], end=pow10[half];
            for(long long h=(half==1?1:start);h<end && cnt<n;++h){
                long long t=h, rev=0, x=h;
                if(len&1) t/=10;
                while(t){
                    rev=rev*10 + t%10;
                    t/=10;
                }
                long long p = x * pow10[len-half] + rev;
                if(ispk(p)){
                    ans += p;
                    ++cnt;
                }
            }
        }
        return ans;  
    }
};