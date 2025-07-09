class Solution {
  public:
      vector<int> nse(vector<int> &arr){
        int n=arr.size();
        stack<int> sk;
        sk.push(n);
        vector<int> ans(n,n);
        for(int i=n-1;i>=0;i--){
            while(sk.size()>1 && arr[i] <= arr[sk.top()])    sk.pop();
            ans[i] = sk.top();
            sk.push(i);
        }
        return ans;
    }
    vector<int> pse(vector<int> &arr){
        int n=arr.size();
        stack<int> sk;
        sk.push(-1);
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            while(sk.size()>1 && arr[i] < arr[sk.top()])  sk.pop();
            ans[i] = sk.top();
            sk.push(i);
        }
        return ans;
    }
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> ns = nse(arr),ps = pse(arr);
        int ans = 0;
        for(int i=0;i<n;i++){
            int sz = (ns[i]-i)*(i-ps[i]);
            ans += sz*arr[i];
        }
        return ans;
    }
};