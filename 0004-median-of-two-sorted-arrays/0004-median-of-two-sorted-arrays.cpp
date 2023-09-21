class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size()+nums2.size();
        vector<int>v;
        for(int i=0;i<nums1.size();i++){
            v.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            v.push_back(nums2[i]);
        }
       
        sort(v.begin(),v.end());
        if(n%2!=0){
            return double(v[n/2]);
        }
        else{
            double ans=(v[(n/2)]+v[(n/2)-1])/2.0;
            return ans;
        }
    }
};