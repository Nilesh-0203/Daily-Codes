class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        unordered_map<int,int>mp;
        int n=arr.size();
        for(int a:arr){
            mp[a]++;
        }
        while(start<=end){
            if(mp[start]==0)return false;
            start++;
        }
        return true;
    }
};
