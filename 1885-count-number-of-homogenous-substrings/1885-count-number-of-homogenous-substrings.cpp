class Solution {
public:
    int countHomogenous(string s) {
        long long int sum=0;
        long long int n=0;
        int mod=1e9+7;
        for(int i=0;i<s.length();i++){
            if(s[i]==s[i+1]){
                n=(n%mod)+1;
            }
            else{
                 n=(n%mod)+1;
                sum+=((n*(n+1)/2)%mod);
                n=0;
            }
        }
        return sum;
    }
};