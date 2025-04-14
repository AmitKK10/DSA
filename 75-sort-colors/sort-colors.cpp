class Solution {
public:
    void sortColors(vector<int>& num) {
        int i,CountZero=0,CountOne=0,CountTwo=0;
for(i=0;i<num.size();i++)
{
if(num[i]==0)
{
CountZero++;
}

else if(num[i]==1)
{
CountOne++;
}
else CountTwo++;
}

for(i=0;i<CountZero;i++)
{
num[i]=0;
}

for(i=CountZero;i<CountZero+CountOne;i++)
{
num[i]=1;
}

for(i=CountZero+CountOne;i<num.size();i++)
{
num[i]=2;
}

for(i=0;i<num.size();i++)
{
    cout<<num[i];
}
    }
};