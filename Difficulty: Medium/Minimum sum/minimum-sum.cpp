class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        string a = "", b = "";
        bool flag = true;
        for(int x : arr){
            if(x == 0) continue;
            if(flag)
            {
                a += to_string(x);
                flag = false;
            }
            else
            {
                b += to_string(x);
                flag = true;
            }
        }
        string ans = "";
        // cout<<"a = "<<a<<" b = "<<b<<endl;
        int sizea = a.size(), sizeb = b.size();
        int mathay = 0;
        for(int i=sizea-1, j=sizeb-1; i>=0; i--, j--)
        {
            int digit = (a[i]-'0') + (j>=0 ? b[j]-'0' : 0) + mathay;
            mathay = digit/10;
            digit = digit%10;
            ans += to_string(digit);
        }
        if(mathay) ans += to_string(mathay);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};