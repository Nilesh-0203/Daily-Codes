class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        
        int i = 0, j = 0;
        int hSeg = 1, vSeg = 1;
        int totalCost = 0;
        
        while(i < x.size() && j < y.size()) {
            if(x[i] >= y[j]) {
                totalCost += x[i] * hSeg;
                vSeg++;
                i++;
            } else {
                totalCost += y[j] * vSeg;
                hSeg++;
                j++;
            }
        }
        while(i < x.size()) {
            totalCost += x[i] * hSeg;
            vSeg++;
            i++;
        }
        while(j < y.size()) {
            totalCost += y[j] * vSeg;
            hSeg++;
            j++;
        }
        return totalCost;
    }
};
