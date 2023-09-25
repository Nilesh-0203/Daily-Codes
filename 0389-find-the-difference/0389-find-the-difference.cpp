class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum=0;
        for(char &ch :t){
            sum+=ch;
        }
        for(char &ch :s){
            sum-=ch;
        }
        return (char)sum;
    }
};