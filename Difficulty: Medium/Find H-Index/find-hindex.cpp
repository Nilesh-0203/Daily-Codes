class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        vector<int> citarr(n+1,0);
        for(int i:citations){
            citarr[ min(i,n) ]++;
        }
        int citres = 0;
        for(int hidx = n;hidx>=0;hidx--){
            citres += citarr[hidx];
            if(citres >= hidx) return hidx;
        }
        return 0;
    }
};