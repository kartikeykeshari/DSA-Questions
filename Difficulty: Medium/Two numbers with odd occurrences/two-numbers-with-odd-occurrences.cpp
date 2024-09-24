//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        vector<long long int> ans;
        int res = 0;
        for(int i=0;i<N;i++) res = res^Arr[i];
        int temp = res;
        int k = 0;
        while(true){
            if((temp&1) == 1){
                break;
            }
            temp = temp>>1;
            k++;
        }
        int retval = 0;
        for(int i=0;i<N;i++){
            int num = Arr[i];
            if(((num >> k) & 1) == 1) retval ^= num;
        }
        res = retval^res;
        if(res>retval){
            ans.push_back(res);
            ans.push_back(retval);
        }
        else{
            ans.push_back(retval);
            ans.push_back(res);
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends