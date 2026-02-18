class Solution {
  public:
    int Merge(vector<int> &arr, int l, int m, int r)
    {
        vector<int> merged(r-l+1);
        int i = l, j = m+1, k = 0, cnt = 0;
        while(i<m+1 and j<r+1){
            if(arr[i]>arr[j]){
                merged[k] = arr[j];
                cnt+=(m-i+1);
                j++;
            }
            else{
                merged[k] = arr[i];
                i++;
            }
            k++;
        }
        while(i<m+1){
            merged[k] = arr[i];
            i++;
            k++;
        }
        while(j<r+1){
            merged[k] = arr[j];
            j++;
            k++;
        }
        
        for(int i = 0;i<(r-l+1);i++)
        {
            arr[l+i] = merged[i];
        }
        return cnt;
    }
    int MergeSort(vector<int> &arr, int l, int r){
        if(l>=r)return 0;
        int m = l + (r-l)/2;
        int lc = MergeSort(arr, l, m);
        int rc = MergeSort(arr, m+1, r);
        
        int mc = Merge(arr, l, m, r);
        
        return lc+rc+mc;
    }
    int inversionCount(vector<int> &arr) {
        return MergeSort(arr, 0, arr.size()-1);
    }
};