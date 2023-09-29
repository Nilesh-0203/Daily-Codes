class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncreasing=true;
        bool isDecreasing=true;

        for(int i=1;i<nums.size();i++){
            if(nums[i] <= nums[i-1]){
                continue;
            }
            else{
                isIncreasing=false;
                break;
            }
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i] >= nums[i-1]){
                continue;
            }
            else{
                isDecreasing=false;
                break;
            }
        }
        return isIncreasing || isDecreasing;
    }
};