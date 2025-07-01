class Solution {
  public:
    vector<int> primeFac(int n) {
        // code here
        vector<int> result;
       if(n%2==0)
       {
           result.push_back(2);
           while(n%2 ==0)
           {
               n/=2;
           }
       }
       
       for(int i=3;i*i<=n;i++)
       {
           if(n%i==0)
           result.push_back(i);
           while(n%i==0)
           {
               n/=i;
           }
       }
       
       if(n>2)
       {
           result.push_back(n);
       }
       
       return result;
    }
};