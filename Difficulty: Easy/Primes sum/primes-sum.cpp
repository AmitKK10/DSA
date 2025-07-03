// User function Template for C++
class Solution {
  public:
  
   bool IsPrime(int n)
       {
           if(n<=1) return false;
           if(n==2) return true;
           if(n%2==0) return false;
           
           for(int i=3;i*i<=n;i+=2)
           {
               if(n%i==0) return false;
           }
           return true;
       }
       
    string isSumOfTwo(int N) {
        // code here
        for(int i=2;i<N;i++)
        {
            if(IsPrime(i) && IsPrime(N-i))
            {
                return "Yes";
            }
            
        }
        
        return "No";
    }
};