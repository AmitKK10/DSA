class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        
        int n = digits.size();
        set<int> result;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(digits[i]==0) continue;

                    if(i==j || j==k || k==i) continue;

                        int num = 100*digits[i]+10*digits[j]+digits[k];
                        if(num%2==0)
                        {
                            result.insert(num);
                        }
                    
                }
            }
        }

        return vector<int>(result.begin(),result.end()) ;
    }
};