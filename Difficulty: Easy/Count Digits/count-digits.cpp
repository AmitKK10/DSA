class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int count=0;
        int temp =n;
        while( temp != 0)
        { 
            int digit = temp%10;
            if(digit !=0 && n%digit ==0)
            {
                count++;
            }
                temp /= 10;
        }
        
        return count;
    }
};