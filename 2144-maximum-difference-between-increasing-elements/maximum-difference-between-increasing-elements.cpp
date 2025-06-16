class Solution {
public:
    int maximumDifference(vector<int>& num) {
        int n = num.size();
        int maxdiff= -1;
        int minval = num[0];

        for(int i=1;i<n;i++)
        {
            if(num[i]>minval)
            {
                maxdiff = max(maxdiff,(num[i]-minval));
            }

            else minval = num[i];
        }
       return maxdiff;
    }
};