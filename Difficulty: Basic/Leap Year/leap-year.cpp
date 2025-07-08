class Solution {
  public:
    bool checkYear(int n) {
        // code here
      
        return (n % 4 == 0 && n % 100 != 0) || (n % 400 == 0);
        
    }
};