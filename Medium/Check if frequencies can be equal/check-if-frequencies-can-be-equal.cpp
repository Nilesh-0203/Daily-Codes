//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
bool sameFreq(string s)
    {
        // code here 
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        unordered_set<int> st;
        for(auto it:mp)
        {
            st.insert(it.second);
        }
        
        if(st.size()>2)
        {
            return false;
        }
        else
        {
            if(st.size()==1)
            {
                return true;
            }
            else
            {
                vector<int> ans;
                for(auto it:st)
                {
                    ans.push_back(it);
                }
                
                sort(ans.begin(),ans.end());
                int a0=0;
                int a1=0;
                for(auto it:mp)
                {
                    if(it.second==ans[0])
                    {
                        a0++;
                    }
                    else if(it.second==ans[1])
                    {
                        a1++;
                    }
                }
                
                if(a0==1 && ans[0]==1)
                {
                    return true;
                }
                else if(ans[1]-ans[0]==1 && a1==1){
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends