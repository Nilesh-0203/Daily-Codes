class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
          
        int size = arr.size();
        int troops = 0;
        int cnt = 0;
        int mid = (size+1)/2;
        
        sort(arr.begin(),arr.end(),[&k](int a,int b){
              return (k-a%k)%k<(k-b%k)%k;
        });
        
        
        for(const auto & i:arr ){
            if(cnt>=mid) return troops;
            if(i%k!=0) troops += (k-i%k);
            cnt++;
        }
        
        return troops;
    }
};