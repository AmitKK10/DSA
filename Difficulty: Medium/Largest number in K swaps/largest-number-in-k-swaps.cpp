//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
             int n=s.size();
        int i=0;
        while(i<n && k!=0){
            int tempMax=s[n-1]-'0';
            
            int ind=n-1;
            for(int j=n-1;j>=i;j--){
                if(tempMax<s[j]-'0'){
                  tempMax=s[j]-'0';
                  ind=j;
                } 
            }
            if(s[i]-'0'>=tempMax){
                i++;
                continue;
            } 
            else{
                char temp=s[i];
                s[i]=s[ind];
                s[ind]=temp;
                i++;
                k--;
            }
        }
        return s;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends