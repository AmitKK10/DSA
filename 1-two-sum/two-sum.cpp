class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int sum) {
         int i,j;

for(i=0;i<arr.size();i++)
{
  for(j=i+1;j<arr.size();j++)
{
   if(arr[i]+arr[j] ==sum)
{
return {i,j};
}
}
}
return {};
    }
    
};