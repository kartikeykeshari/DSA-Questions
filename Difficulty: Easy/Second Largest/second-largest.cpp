//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        int n = arr.size();
        int larger = INT_MIN;
        int s_larger = INT_MIN;
        if(n==1) return -1;
        for(int i=0;i<n;i++){
            if(larger<arr[i]){
                s_larger = larger;
                larger = arr[i];
            }
            else if(s_larger < arr[i] && arr[i] != larger){
                s_larger = arr[i];
            }
        }
        return s_larger;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends