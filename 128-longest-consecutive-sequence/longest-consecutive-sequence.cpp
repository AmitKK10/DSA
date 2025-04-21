class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         if (nums.empty()) return 0;
         int i,Maxcount=1,count=1;
   sort(nums.begin(),nums.end());
  for(i=1;i<nums.size();i++)
{ 
  if(nums[i] == nums[i - 1] + 1)
{
count++;
}
else if (nums[i] != nums[i - 1]) 
{
    count = 1;
}

Maxcount = max(count,Maxcount);
}
return Maxcount;
    }
};