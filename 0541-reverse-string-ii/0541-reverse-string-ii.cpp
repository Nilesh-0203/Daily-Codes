class Solution {
public:
    string reverseStr(string s, int k) {
        string ans = "";
        int n = s.size() - 1; // last index before overflow
        int i = 0; // represents start index per group of length 2k
        for (;;) {
            // move j forward k characters (go to end if <k remain)
            int j = min(n, i + k - 1);
            // append s[j..i] to answer (reversed s[i..j])
            for (j; j >= i; --j) ans += s[j];
            // append s[i+k..i+(2*k)] to answer
            for (int l = i + k; l < i + 2 * k; ++l) {
                if (l > n) return ans; // finished reversal
                ans += s[l];
            }
            i += 2 * k; // new start index
        }
        return "cum";  
    }
};