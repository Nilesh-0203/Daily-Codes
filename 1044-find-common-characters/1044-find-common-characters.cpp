class Solution {
public:
    void fillArray(string &word,int count[26]){
        for(auto &ch:word){
            count[ch-'a']++;
        }
    }
    vector<string> commonChars(vector<string>& words) {
        vector<string>result;
        int n=words.size();
        int count[26]={0};
        fillArray(words[0],count);

        for(int i=1;i<n;i++){
            int temp[26]={0};
            fillArray(words[i],temp);
            for(int i=0;i<26;i++){
                count[i]=min(count[i],temp[i]);
            }
        }
        for(int i=0;i<26;i++){
            int j=count[i];
            while(j--){
                result.push_back(string(1,i+'a'));
            }
        }
        return result;
    }
};