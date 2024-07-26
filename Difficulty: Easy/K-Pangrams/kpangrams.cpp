//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        unordered_map<char,int>m;
        int count = 0;
        for(auto it:str){
            if(it==' '){
                continue;
            }
            else if(m.find(it)!=m.end()){
                count++;
            }
            else{
                m[it]++;
            }
        }
        int req = 26-m.size();
        if(req-k<=0 && count-req>=0){
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends