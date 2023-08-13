//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    
    void helper(vector<vector<int>> &m,int row,int col,vector<string>&ans,string path,int n){
        if(row<0 || col<0 || row>=n || col>=n) return;
        
        
        if(m[row][col]==0) return;
        if(row==n-1 && col==n-1){
            ans.push_back(path);
            return;
        }
        
        
        m[row][col]=0;
        helper(m,row+1,col,ans,path+'D',n);
        helper(m,row-1,col,ans,path+'U',n);
        helper(m,row,col+1,ans,path+'R',n);
        helper(m,row,col-1,ans,path+'L',n);
        m[row][col]=1;
    }
    
    
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string path = "";
        
        helper(m,0,0,ans,path,n);
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends