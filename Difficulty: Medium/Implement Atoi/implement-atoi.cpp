class Solution {
  public:
    int myAtoi(string &s) {
        // code here
        int sign = 1, r = 0, i = 0;
        while(s[i] == ' ')      i++;        // ignore whitespaces
        if(s[i] == '-' || s[i] == '+'){
            if(s[i++] == '-')       sign = -1;
        }
        while(s[i] >= '0' && s[i] <= '9'){ 
            if(r > INT_MAX/10 || r == INT_MAX/10 && s[i]-'0' > 7)     
                return      sign == 1 ? INT_MAX : INT_MIN;
            r = 10*r+(s[i++]-'0');
        }
        return  r*sign;
    }
};
