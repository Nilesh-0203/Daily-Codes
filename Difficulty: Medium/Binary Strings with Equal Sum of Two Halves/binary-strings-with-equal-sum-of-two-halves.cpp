class Solution {
  public:
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        
        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % mod;
            
            base = (base * base) % mod;
            exp >>= 1;
        }
        
        return result;
    }
    
    int computeValue(int n) {
        const long long MOD = 1000000007;
        
        long long fact2n = 1;
        long long factn = 1;
        
        for (int i = 1; i <= 2 * n; i++) {
            fact2n = (fact2n * i) % MOD;
            
            if (i == n)
                factn = fact2n;
        }
        
        long long invFactn = power(factn, MOD - 2, MOD);
        
        long long ans = fact2n;
        ans = (ans * invFactn) % MOD;
        ans = (ans * invFactn) % MOD;
        
        return (int)ans;
    }
};