class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a=0;
        long long b=sqrt(c);
        while(a<=b){
            long long k=a*a + b*b;
            if(k<c){
                a++;
            }
            else if(k>c){
                b--;
            }
            else{
                return true;
            }
        }
        return false;
    }
};