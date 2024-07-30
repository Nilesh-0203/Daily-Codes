//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        unordered_set<string>st;
        for(string word:wordList){
            st.insert(word);
        }
        if(st.find(targetWord)==st.end()){
            return 0;
        }
        int len=startWord.size();
        int level=0;
        queue<string>q;
        q.push(startWord);
        while(!q.empty()){
            level++;
            int n=q.size();
            for(int i=0;i<n;i++){
                string front=q.front();
                q.pop();
                for(int j=0;j<len;j++){
                    char org=front[j];
                    for(char ch='a';ch<='z';ch++){
                        front[j]=ch;
                        if(front==targetWord){
                            return level+1;
                        }
                        if(st.find(front)==st.end()){
                            continue;
                        }
                        st.erase(front);
                        q.push(front);
                    }
                    front[j]=org;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends