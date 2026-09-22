class Solution {
  public:
    string findLongestWord(string &s, vector<string> &d) {
            // code here
            int n  = s.size() , m = d.size();
            vector<vector<pair<int,int>>>arr(26);
            for(int i = 0 ;i<m ; i++){
                arr[d[i][0]-'a'].push_back({i,  0});
            }
            int ans = -1;
            auto comp = [&](int curr){
                if(ans == -1 || d[ans].size() < d[curr].size())ans = curr;
                else if(d[ans].size() == d[curr].size()){
                    if(d[ans] > d[curr])ans = curr;
                }
                return;
            };
            for(int i = 0 ;i<n ; i++){
                vector<pair<int,int>>temp;
                for(auto &[x , y]:arr[s[i] - 'a']){
                    if(y+1 == d[x].size())comp(x);
                    else if(d[x][y+1] == s[i]){
                        temp.push_back({x , y+1});
                    }else arr[d[x][y+1] - 'a'].push_back({x , y+1});
                }
                swap(temp , arr[s[i] - 'a']);
            }
            if(ans == -1)return "";
            else return d[ans];
        }
};