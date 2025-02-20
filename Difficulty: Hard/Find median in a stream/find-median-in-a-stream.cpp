//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        vector<double>ans;
        
        priority_queue<double>maxHeap;
        priority_queue<double,vector<double>,greater<double>>minHeap;
        
        for(int i=0;i<arr.size();i++){
            if(!maxHeap.empty() && maxHeap.top()<arr[i]){
                minHeap.push(arr[i]);
            }
            else{
                maxHeap.push(arr[i]);
            }
            
            if(maxHeap.size()>minHeap.size()+1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if(minHeap.size()>maxHeap.size()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            if(i%2==0){
                ans.push_back(maxHeap.top());
            }
            else{
                ans.push_back((maxHeap.top()+minHeap.top())/2.0);
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends