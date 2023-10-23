Approch 1 :
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        int ans=log(n)/log(4);
        return pow(4,ans)==n;
    }
};

Approch 2 :
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0){
            return false;
        }
        while(n%4==0){
            n=n/4;
        }
        return n==1;
    }
};

Approch 3 :
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        if((n&(n-1))==0 && (n-1)%3==0){
            return true;
        }
        return false;
    }
};
