class Solution {
  public:
    vector<int> asciirange(string& s) {
        int n = s.size();
        unordered_map<char, vector<int>> freq;
        vector<int> vt;
        for(int i = 0; i < n; i++){
            freq[s[i]].push_back(i);
        }
        
        
        for(const auto& it : freq){
            int firstpos = it.second.front();
            int lastpos = it.second.back();
            if(firstpos == lastpos || lastpos == firstpos + 1)
                continue;
            int res = 0;
            for(int i = firstpos + 1; i < lastpos; i++){
                res += static_cast<int>(s[i]);
            }
            vt.push_back(res);
        }
        return vt;
    }
};