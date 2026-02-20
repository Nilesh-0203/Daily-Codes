class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
           vector<string> temp;
        for(int& num : arr){
            temp.push_back(to_string(num));
        }
        
        string res = "";
        
        sort(temp.begin(),temp.end(),[](string& str1,string& str2){
            return str1 + str2 > str2 + str1;
        });
        
        for(string& str : temp){
            res+=str;
        }
        
        return res[0] == '0' ? "0" : res;
    }
};