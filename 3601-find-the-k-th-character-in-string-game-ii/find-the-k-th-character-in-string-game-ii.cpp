class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int shift = 0;
        k--;
        
        for(int i = operations.size() - 1; i >= 0; i--) {
            long long half;
            if(i >= 60) {
                half = LLONG_MAX;
            } else {
                half = 1LL << i;
            }
            
            if(k >= half) {
                k -= half;
                shift += operations[i];
            }
        }
        
        return (char)('a' + shift % 26);
    }
};