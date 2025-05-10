class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0, sum2=0, num1Zero =0,num2Zero=0;
        for(int i=0;i<nums1.size();i++)
        {
            sum1+=nums1[i];
            if(nums1[i]==0)
            {
                sum1++;
                num1Zero++;
            }
        }

         for(int j=0;j<nums2.size();j++)
        {
            sum2+=nums2[j];
            if(nums2[j]==0)
            {
                sum2++;
                num2Zero++;
            }
        }

        if(!num1Zero && sum1<sum2 || !num2Zero && sum1>sum2)
        {
            return -1;
        }
        return  max(sum1,sum2);

    }
};