//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int>v1;
        vector<int>v2;
        for(int i:arr){
            if(i>=0){
                v1.push_back(i);
            }
            else{
                v2.push_back(i);
            }
        }
        int i=0,j=0,k=0;
        while(j<v1.size() && k<v2.size()){
            if(i%2==0){
                arr[i]=v1[j];
                j++;
            }
            else{
                arr[i]=v2[k];
                k++;
            }
            i++;
        }
        while(j<v1.size()){
            arr[i]=v1[j];
            i++;
            j++;
        }
        while(k<v2.size()){
            arr[i]=v2[k];
            i++;
            k++;
        }
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends