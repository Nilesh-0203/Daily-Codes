class Solution {
  public:
    char maxLex(string s, int &l , int &r){
        int n= s.size();
        char c= s[l];
        int pos= l;
        for(int i=l+1;i<=r;i++){
            if(s[i]> c){
                pos= i;
                c= s[i];
            }
        }
        l= pos+1;
        r= r+1;
        return c;
    }
  
  
    string maxSubseq(string& s, int k) {
        // code here
        // function to give maxLex in a range 
        string ans="";
        int n=s.size();
        int len= n- k;
        int l=0, r= k;
        
        while(len>0){
            ans+= maxLex(s, l, r);
            len--;
        }
        return ans;
        
    }
};
