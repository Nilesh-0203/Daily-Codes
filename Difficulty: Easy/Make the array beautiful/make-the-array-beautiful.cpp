class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int>s;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(s.empty() || (s.top()>=0 && arr[i]>=0)){
                s.push(arr[i]);
            }
            else if(s.top()<0 && arr[i]<0){
                s.push(arr[i]);
            }
            else{
                s.pop();
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};