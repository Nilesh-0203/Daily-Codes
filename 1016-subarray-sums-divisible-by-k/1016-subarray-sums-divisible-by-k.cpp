class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int a=sum%k;
            if(a<0){
                a=sum%k+k;
            }
            if(mp.find(a)!=mp.end()){
                count+=mp[a];
                mp[a]++;
            }
            else{
                mp[a]++;
            }
        }
        return count;
    }
};