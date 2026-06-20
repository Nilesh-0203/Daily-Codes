class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        // code here
        int n=(a[a.length()-1]-'0');
        if(b=="0") return 1;
        int p = 0;
        for (char c : b) {
            p = (p * 10 + (c - '0')) % 4;
        }
        
        
        if(n==0 || n==1 || n==5 || n==6) return n;
        else if(n==4 || n==9){
            p=(p%2);
            if(p==1) return n==4?4:9;
            else return n==4?6:1;
        }else{
            p=(p%4);
            if(p==1){
                if(n==2){
                    return 2;
                }else if(n==3){
                    return 3;
                }else if(n==7){
                    return 7;
                }else return 8;
            }else if(p==2){
                if(n==2){
                    return 4;
                }else if(n==3){
                    return 9;
                }else if(n==7){
                    return 9;
                }else return 4;
            }else if(p==3){
                if(n==2){
                    return 8;
                }else if(n==3){
                    return 7;
                }else if(n==7){
                    return 3;
                }else return 2;
            }else{
                if(n==2){
                    return 6;
                }else if(n==3){
                    return 1;
                }else if(n==7){
                    return 1;
                }else return 6;
            }
        }
        return 0;
    }
};