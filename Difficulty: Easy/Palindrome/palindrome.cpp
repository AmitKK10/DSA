// User function Template for C++

class Solution {
  public:
    bool isPalindrome(int n) {
        // Code here.
        int temp =n;
        int reverse=0;
        while(temp!=0)
        {
            int digit = temp%10;
            reverse = reverse*10+digit;
            temp /= 10;
        }
        
        return reverse == n;
    }
};