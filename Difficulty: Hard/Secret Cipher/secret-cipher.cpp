class Solution {
  public:
    string compress(string s) {
         int n = s.length();
         if (n == 0) return "";

         // Compute KMP prefix function array
         vector<int> pi(n, 0);
         for (int i = 1; i < n; i++) {
             int j = pi[i - 1];
             while (j > 0 && s[i] != s[j]) {
                 j = pi[j - 1];
             }
             if (s[i] == s[j]) {
                 j++;
             }
             pi[i] = j;
         }

         string result = "";
         int i = n - 1;

         while (i >= 0) {
             int len = i + 1;

             // If prefix s[0...i] has an even length, check if first half matches second half
             if (len % 2 == 0) {
                 int half = len / 2;
                 int k = pi[i];
                 while (k > half) {
                     k = pi[k - 1];
                 }

                 if (k == half) {
                     result += '*';
                     i = half - 1;
                     continue;
                 }
             }

             result += s[i];
             i--;
         }

         reverse(result.begin(), result.end());
         return result;
     }
};
