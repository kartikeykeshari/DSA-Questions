//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
        int low = 0, high = n - 1;
        int ans1 = -1, ans2 = -1;

        // Find the first occurrence of the target
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x) {
                high = mid - 1;
                if (arr[mid] == x) ans1 = mid;
            } else {
                low = mid + 1;
            }
        }

        low = 0;
        high = n - 1;

        // Find the last occurrence of the target
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= x) {
                low = mid + 1;
                if (arr[mid] == x) ans2 = mid;
            } else {
                high = mid - 1;
            }
        }

        // If the target was not found, return [-1, -1]
        if (ans1 == -1 || ans2 == -1) return 0;

        return ans2-ans1+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends