class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        vector<int>police;
        vector<int>thief;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]=='P'){
                police.push_back(i);
            }
            else{
                thief.push_back(i);
            }
        }
        
        int i=0,j=0;
        int count=0;
        while(i<police.size() && j<thief.size()){
            if(abs(police[i]-thief[j])<=k){
                count++;
                i++;
                j++;
            }
            else if(police[i]<thief[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};