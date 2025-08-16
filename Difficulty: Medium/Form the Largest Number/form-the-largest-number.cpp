class Solution {
  public:
    string findLargest(vector<int> &a) {
        // code here
        vector<string>arr;
        for(int i:a){
            arr.push_back(to_string(i));
        }
        string num="";
	    sort(arr.begin(),arr.end(),[](string s1,string s2){return s1+s2>s2+s1;});
	    for(string st:arr){
	        num+=st;
	    }
	    return num[0]=='0' ? "0" : num;
    }
};