//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        
        int n = arr.size();
        if(n==1) return 0;
        
        int low = 0;
        int high = n-1;
        
        if(arr[low] < arr[high]) return 0;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(arr[mid]>arr[mid+1]) return mid+1;
            else if(arr[mid]<arr[mid-1]) return mid;
            else{
                if(arr[mid] > arr[low]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
// } Driver Code Ends