class Solution {
public:
    const int MOD = 1e9 + 7;
    int numerator;

    int powMod(int x,int n){
        if(n == 0) return 1;
        long long res = powMod(x,n/2);
        (res*=res)%=MOD;
        if(n&1) (res*=x)%=MOD;
        return res;
    }

    vector<long long> fact,invFact;
    vector<vector<vector<int>>> dp;

    int solve(int digit,int places,int target,vector<int>& freq){
        if(digit == 10){
            if(places == 0){
                return target == 0 ? numerator : 0;
            }
            return 0;
        }

        if(dp[digit][places][target] != -1) return dp[digit][places][target];

        long long ans = 0;
        int limit = min({places,freq[digit],digit > 0 ? target/digit : INT_MAX});

        for(int i=0;i<=limit;i++){
            long long waysToPlaceDigit = (invFact[i]*invFact[freq[digit] - i])%MOD;
            ans+=(waysToPlaceDigit*solve(digit+1,places-i,target - digit*i,freq))%MOD;
            ans%=MOD;
        }

        return dp[digit][places][target] = ans;
    }

    int countBalancedPermutations(string num) {
        int n = num.length(),sum = 0;
        vector<int> freq(10,0);

        for(int x : num) freq[x - '0']++,sum+=x-'0';

        if(sum%2 == 1) return 0;

        fact.assign(n+1,1),invFact.assign(n+1,1);
        fact[0] = 1,invFact[0] = 1;

        for(int i=1;i<=n/2+1;i++){
            fact[i] = (fact[i-1]*i)%MOD;
            invFact[i] = powMod(fact[i],MOD-2);
        }

        numerator = (fact[n - n/2]*fact[n/2])%MOD;
        dp.assign(10,vector<vector<int>>(n/2+1,vector<int>(sum/2+1,-1)));
        return solve(0,n/2,sum/2,freq);
    }
};