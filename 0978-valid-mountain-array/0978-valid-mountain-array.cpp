class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        int maxi=*max_element(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(maxi==arr[i]){
                ans=i;
            }
        }
        if ((ans == 0) || (ans == n - 1)) return false;
        for(int i=0;i<ans;i++){
            if(arr[i]>=arr[i+1]){
                return false;
            }
        }
        for(int i=ans;i<n-1;i++){
            if(arr[i]<=arr[i+1]){
                return false;
            }
        }
        return true;
    }
};