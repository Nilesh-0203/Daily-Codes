class Solution{   
public:
    string sum(string s1, string s2)
{
    if (s1.length() < s2.length())
    {
        return sum(s2, s1);
    }
    string s3;
    int sum = 0, carry = 0, rem = 0;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for (int i = 0; i < s2.length(); i++)
    {
        int val = s1[i] - '0' + s2[i] - '0' + carry;
        if (val >= 10)
        {
            carry = val / 10;
        }
        else
            carry = 0;
        s3.push_back(val % 10 + '0');
    }
    for (int i = s2.length(); i < s1.length(); i++)
    {
        int val = carry + s1[i] - '0';
        if (val >= 10)
        {
            carry = val / 10;
        }
        else
            carry = 0;
        s3.push_back(val % 10 + '0');
    }
    if (carry > 0)
    {
        s3.push_back(carry+'0');
    }
    reverse(s3.begin(),s3.end());
    return s3;
}
bool help(string s,int idx,int len1,int len2){
    string s1=s.substr(idx,len1);
    string s2=s.substr(idx+len1,len2);
    string s3=sum(s1,s2);
    int p=s3.length();
    if(s3.length()>s.length()-len1-len2-idx) return false;
    if(s3==s.substr(idx+len1+len2,p)){
        if(idx+len1+len2+p==s.length()) return true;
        return help(s,idx+len1,len2,s3.length());
    }
    return false;
}
    int isSumString(string S){
        // code here 
      int n=S.length();
      for(int i=1;i<n;i++){
          for(int j=1;i+j<n;j++){
              if(help(S,0,i,j)) return true;
          }
      }
      return false;
        
    }
};
