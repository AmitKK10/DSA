class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        
int count=0,OneCount=0,i;
for(i=0;i<arr.size();i++)
{
if(arr[i] == 1)
{
count++;
}
else
{

OneCount = max(count,OneCount);
count =0;

}
}

OneCount = max(count,OneCount);

return OneCount;

    }
};