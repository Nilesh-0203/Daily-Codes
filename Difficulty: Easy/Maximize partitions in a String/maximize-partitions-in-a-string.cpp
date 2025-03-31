//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     int maxPartitions(string &s) {
    
    string temp="";
    unordered_map<char, pair<int, bool>> m;
    int n=s.length();
    unordered_map<char,int>mp;
    for(int i=0;i<n;i++){
        mp[s[i]]=mp[s[i]]+1;
        m[s[i]]={mp[s[i]],true};
    }
    int count=0;
    for(int i=0;i<=n;i++){
        if(temp.size()!=0){
            bool flag=true;
            for(int j=0;j<temp.size();j++){
              if(mp[temp[j]] > 0){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                count++;
                 temp="";
            }
           
        }
        
        if(i<n){
        temp+=s[i];
        int c=mp[s[i]];
        c--;
        mp[s[i]]=c;
        m[s[i]]={c,false};
        }
        
    }
    return count;
    
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends