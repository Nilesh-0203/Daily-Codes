class Solution {
  public:
    int andInRange(int l, int r) {
        int curr = 0, res = 0;
        for(int i=0; i<31; ++i){
            if(l&(1<<i)){
                int diff = (1<<i) - curr;
                if(r-l+1 <= diff) res |= (1<<i);
            }
            
            curr |= (l&(1<<i));
        }
        
        return res;
    }
};
