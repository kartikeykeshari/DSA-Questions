//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        int low = 1;
        int high = n;
        int ans = 0;
        
        if(n==0 || n==1) return n;
        
        while(low<=high){
            long long int mid = low + (high-low)/2;
            if(mid*mid == n) return mid;
            else if(mid*mid < n){
                low = mid+1;
                ans = mid;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends