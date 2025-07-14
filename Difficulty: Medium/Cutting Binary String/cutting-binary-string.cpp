class Solution {
  public:
    // Function to check if a binary string represents a power of 5
    bool checkFive(string &s){
        // If the string is empty or has leading zero (since we process reversed string, leading zero means trailing zero in original)
        if(s.size() > 0 and s.back() == '0') return false;
        int ans = 0;
        int cnt = 0;
        // Convert binary string to decimal
        for(char ch : s){
            ans += ((int)(ch - '0')) << (cnt++);
        }
        // Edge case: ans is 0 (invalid)
        if(ans == 0) return false;
        
        // Check if ans is a power of 5
        int ele = 1;
        while(ans > ele){
            ele *= 5;
        }
        
        return (ans == ele);
    }   
    
    // Helper function to recursively find the minimum splits
    int help(int idx, string temp, string &s){
        // Base case: end of string
        if(idx >= s.length()){
            if(temp == "") return 0; // valid split
            else return 1e9; // invalid split (remaining characters)
        }
        
        // Option to pick current character and check if temp is a power of 5
        int ans = 1e9;
        temp.push_back(s[idx]);
        
        if(checkFive(temp)){
            // If temp is valid, split here and recurse with new substring
            string newTmp = "";
            ans = min(ans, 1 + help(idx+1, newTmp, s));
        }
        
        // Option to not split here and continue extending the current substring
        ans = min(ans, help(idx+1, temp, s));
        
        return ans;
    }
    
    int cuts(string s) {
        int n = s.length();
        // Reverse the string to process from LSB to MSB
        reverse(s.begin(), s.end());
        
        string temp = "";
        int ans = help(0, temp, s);
        
        // If ans is still 1e9, it means no valid split was found
        return ans >= 1e9 ? -1 : ans;
    }
};