//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
             vector<int> ans;
            string str="";
            int n=pattern.size();
            int i=0,j=0;
            while(j<text.size()){
                str+=text[j];
                if(j-i+1==n){
                    if(str==pattern) ans.push_back(i+1);
                    i++;
                    str.erase(0,1);
                }
                j++;
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends