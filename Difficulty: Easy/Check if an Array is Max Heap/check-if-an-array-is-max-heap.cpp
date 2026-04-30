class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code
        
        int n = arr.size();
        
        for(int i=0; i<n; i++)
        {
            int left_child = i*2 + 1;
            int right_child = i*2 + 2;
            
            if(left_child < n && arr[left_child] > arr[i])
            {
                return false;
            }
            if(right_child < n && arr[right_child] > arr[i])
            {
                return false;
            }
        }
        
        return true;
        
    }
};
