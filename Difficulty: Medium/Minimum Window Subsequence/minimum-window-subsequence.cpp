class Solution {
  public:
    string minWindow(string &s1, string &s2) {
    string ans = "";
    int size1 = s1.size();
    int size2 = s2.size();
    vector<vector<int>> charToIndex(26);
    
    // Mapping all index for characters
    for(int i=0; i<size1; i++) {
        charToIndex[s1[i] - 'a'].push_back(i);
    }
    
    // If s2's size is 1, just check if it appears in s1
    if(size2 == 1) {
        if(charToIndex[s2[0] - 'a'].size() > 0) {
            return s2;
        }
        
        return "";
    }
    
    // Check all the index for s2[0]
    for(int &val: charToIndex[s2[0] - 'a']) {
        int start = val;
        int lastSearched = val;
        int end = -1;
        
        // upper_bound because for same continuous character like hh, lower will fetch same index for h
        for(int j=1; j<size2; j++) {
            vector<int> &v = charToIndex[s2[j] - 'a'];
            auto lb = upper_bound(v.begin(), v.end(), lastSearched);
            
            // No upper_bound found
            if(lb == v.end()) {
                break;
            }
            else {
                lastSearched = *lb;

                if(j == size2-1) {
                    end = *lb;
                }
            }
        }
        
        // If we reached to the end
        if(end != -1) {
            if(ans.empty() || ans.size() > end-start+1) {
                ans = s1.substr(start, end-start+1);
            }
        }
    }
    
    return ans;
}
};
