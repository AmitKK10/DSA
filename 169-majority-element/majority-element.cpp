class Solution {
public:
    int majorityElement(vector<int>& num) {
        
        int i,j;
for(i=0;i<num.size();i++)
{ int count =0;
for(j=0;j<num.size();j++)
{
if(num[i]==num[j])
{
count ++;

if(count>(num.size())/2)
{
return num[j];
}
}
}
}
return -1;
    }
};