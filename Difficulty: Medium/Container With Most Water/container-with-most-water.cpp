class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int s=0,e=arr.size()-1,maxarea=0,area=0;
        while(s<e){
            area=min(arr[s],arr[e])*(e-s);
            maxarea=max(maxarea,area);
            if(arr[s]<arr[e]) s++;
            else e--;
        }
        return maxarea;
    }
};