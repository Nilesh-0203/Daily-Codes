//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        // code here
        double m1=double(q1[1]-p1[1])/double(q1[0]-p1[0]);
        double m2=double(q2[1]-p2[1])/double(q2[0]-p2[0]);
        if(m1==m2)  return "false";
        
        bool c1=false,c2=false,c3=false,c4=false;
        if(p2[1]-p1[1]-m1*(p2[0]-p1[0])>0) c1=true;
        if(q2[1]-p1[1]-m1*(q2[0]-p1[0])>0) c2=true;
        if(p1[1]-p2[1]-m2*(p1[0]-p2[0])>0) c3=true;
        if(q1[1]-p2[1]-m2*(q1[0]-p2[0])>0) c4=true;
        
        if((c1 && c2) || (!c1 && !c2)|| (c3 && c4) || (!c3 && !c4))   return "false";
        return "true";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >> q2[1];
        // if (q2[1] == -2) {
        //     cout << "true" << endl;
        //     return 0;
        // }
        Solution ob;
        // int a = ob.doIntersect(p1, q1, p2, q2);
        // if (a)
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends