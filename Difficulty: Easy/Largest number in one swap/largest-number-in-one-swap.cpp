class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        vector<int>v(10,-1);
        for(int i=0;i<s.length();i++){
            v[s[i]-'0']=i;
        }
        for(int i=0;i<s.length();i++){
            int ele=s[i]-'0';
            for(int j=9;j>ele;j--){
                if(i<v[j]){
                    swap(s[i],s[v[j]]);
                    return s;
                }
            }
        }
        return s;
    }
};