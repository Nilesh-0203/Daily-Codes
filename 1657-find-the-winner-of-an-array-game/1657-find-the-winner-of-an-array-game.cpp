class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        int maxi=*max_element(arr.begin(),arr.end());
        if(k>=n){
            return maxi;
        }
        int winner=arr[0];
        int count=0;
        for(int i=1;i<n;i++){
            if(arr[i]>winner){
                winner=arr[i];
                count=1;
            }
            else{
                count++;
            }

            if(count==k || winner==maxi){
                return winner;
            }
        }
        return winner;
    }
};