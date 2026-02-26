class Solution {
  public:
    bool areIsomorphic(string &s, string &t) {
        // code here
        if (s.size() != t.size()) return 0;
        int mapS[256] = {0}, mapT[256] = {0};
        
        for (int i = 0; i < s.size(); i++) {
            char cs = s[i], ct = t[i];
            if (mapS[cs] != mapT[ct]) return 0;
            mapS[cs] = mapT[ct] = i + 1;
        }
        
        return 1;
    }
};