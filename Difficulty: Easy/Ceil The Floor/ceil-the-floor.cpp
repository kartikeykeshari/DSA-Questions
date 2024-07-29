//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int floor = -1, ceil = -1; 
        vector<int> ans;
        sort(arr.begin(),arr.end());
        while(low<=high){
            int mid =(low+high)/2;
            if(arr[mid]<=x){
                floor = arr[mid];
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            
        }
        int l = 0 , h = n-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(arr[mid]>=x){
                ceil =arr[mid];
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        ans.push_back(floor);
        ans.push_back(ceil);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends