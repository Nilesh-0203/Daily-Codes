class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int> st;
        for(auto it:arr){
            if(it!="+" && it!="-" && it!="*" && it!="/" && it!="^")
                st.push(stoi(it));
            else {
                int ans;
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(it=="+")ans=a+b;
                else if(it=="-")ans=b-a;
                else if(it=="*")ans=a*b;
                else if(it=="/")ans=floor((double)b/(double)a);
                else ans=pow(b,a);
                st.push(ans);
            }
        }
        return st.top();
    }
};