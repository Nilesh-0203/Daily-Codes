class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        multiset<int>st;
        
        int l=0,r=0,maxlen =0,ind =0;
        
         while(r<arr.size()){
             
             st.insert(arr[r]);
             
             while(*st.rbegin()-*st.begin()>x){
                 st.erase(st.find(arr[l]));
                 l++;
             }
             int len = r-l+1;
             if(maxlen < len){
                 maxlen = len;
                 ind = l;
             }
             r++;
             
        }
        return vector<int>(arr.begin()+ind,arr.begin()+ind+maxlen);
    }
};