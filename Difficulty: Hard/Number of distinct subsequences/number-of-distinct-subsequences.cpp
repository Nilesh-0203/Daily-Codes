class Solution {
  public:
    int distinctSubseq(string &str) {
        // code here
        int ans = 1;
    int m = 1e9 + 7;
    int mp[26] = {0};
    for (char i : str)
    {
        int seq = mp[i - 'a']; // repeating sub-sequence
        mp[i - 'a'] = ans;
        ans = (1LL * ans * 2 - seq + m) % m;
    }
    return ans;
    }
};