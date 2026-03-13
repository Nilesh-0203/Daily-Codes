class Solution {
  public:
    vector<string>ans;
    int n;
    bool isValid(string temp){
        if(temp[0]=='0')return false;
        int num=stoi(temp);
        if(num>=1 && num<=255)return true;
        return false;
    }
    void solve(string& s,int idx,int parts,string curr){
        if(idx==n && parts==4){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        if((idx+1)<=n){
            solve(s,idx+1,parts+1,curr+s.substr(idx,1)+".");
        }
        if((idx+2)<=n && isValid(s.substr(idx,2))){
            solve(s,idx+2,parts+1,curr+s.substr(idx,2)+".");
        }
        if((idx+3)<=n && isValid(s.substr(idx,3))){
            solve(s,idx+3,parts+1,curr+s.substr(idx,3)+".");
        }
    }
    vector<string> generateIp(string s) {
        // code here
        n=s.length();
        string curr="";
        solve(s,0,0,curr);
        return ans;
    }
};