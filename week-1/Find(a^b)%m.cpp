//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


unsigned int aModM(string s, unsigned int mod) 
{ 
    unsigned int number = 0; 
    for (unsigned int i = 0; i < s.length(); i++) 
    { 
        // (s[i]-'0') gives the digit value and form 
        // the number 
        number = (number*10 + (s[i] - '0')); 
        number %= mod; 
    } 
    return number; 
} 

// } Driver Code Ends
class Solution {
  public:
    long long powerMod(string a, long long b, long long p) {
        // code here
        long long ans = 1;
        long long num = aModM(a, p);
        num %= p;
        
        while (b > 0) {
            if (b & 1) {
                ans = (ans * num) % p;
            }
            num = (num * num) % p;
            b >>= 1;
        }
        return ans % p;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        long long b,m;
        
        cin>>a>>b>>m;

        Solution ob;
        cout << ob.powerMod(a,b,m) << endl;
    }
    return 0;
}
// } Driver Code Ends