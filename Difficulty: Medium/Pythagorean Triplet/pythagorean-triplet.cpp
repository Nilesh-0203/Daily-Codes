class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int>ump;
         for (int i = 0; i < n; ++i) {
            int sq = arr[i] * arr[i];
            ump[sq]++;
        }
      vector<int>tes;
      for(const auto&k:ump){
          tes.push_back(k.first);
      }
      int m=tes.size();
        vector<int>vp;
        for(int i=0; i<m-1; i++){
            int temp=tes[i];
            for(int j=i+1; j<m; j++){
                vp.push_back(temp+tes[j]);
            }
        }
        
       for(auto&k:vp){
           if(ump.find(k)!=ump.end()){
               return true;
           }
       }
        return false;
    }
};