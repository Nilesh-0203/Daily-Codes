class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int k=nums.size()/3;
        vector<int>v;
        for(auto i : mp){
            if(i.second > k){
                v.push_back(i.first);
            }
        }
        return v;
    }
};