// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int temp =n;
        int num=0;
        while(n!=0)
        {
            int digit = n%10;
            
            num = num + digit*digit*digit;
            n=n/10;
        }
        
        return  (num == temp);
    }
};