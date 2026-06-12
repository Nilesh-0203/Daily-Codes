class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        // Your Code Here
        int n = s.size();
        unordered_map<string,pair<int,int>>m;
        
        if(n%k!=0)return false;
        
        int ptr = 0;
        
        while(ptr<n){
            
            string temp = "";
            
            for(int i=0;i<k;i++){
                temp+=s[ptr];
                ptr++;
            }
            
            if(m.count(temp))m[temp].second++;
            else {
                pair<int,int>p = {ptr-k,1};
                m[temp]=p;
            }
            
        }
        
        if(m.size()>2)return false;
        if(m.size()==1)return true;
        
        
        for(const auto& temp : m) {
            
            pair<int,int>p = temp.second;
            
            if(p.second==1){
                if(p.first%k==0)return true;
            }
       
        }
        
        return false;
        
    }
};