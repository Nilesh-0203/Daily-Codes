class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize){
            return false;
        }
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        while(!mp.empty()){
            int k=mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mp[k+i]==0){
                    return false;
                }
                mp[k+i]--;
                if(mp[k+i]<1){
                    mp.erase(k+i);
                }
            }
        }
        return true;
    }
};