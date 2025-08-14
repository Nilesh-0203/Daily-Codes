class Solution {
  public:
    int countPairs(vector<int> &arr, int low, int mid, int high)
    {
        int count = 0, right = mid+1;
        
        for(int i = low; i <= mid; i++)
        {
            while(right <= high and (arr[i] > 2*arr[right]))
                right++;
            
            count += right - (mid +1);
            
        }
        return count;
    }
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid+1;
        
        while(left <= mid and right <= high)
        {
            if(arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = low; i <= high; i++)
        {
            arr[i] = temp[i-low];
        }
    }
    int mergesort(vector<int> &arr, int low, int high)
    {
        int count = 0;
        int mid = (low + high)/2;
        if(low >= high)
            return count;
        count += mergesort(arr,low,mid);
        count += mergesort(arr,mid+1,high);
        count += countPairs(arr, low, mid, high);
        merge(arr,low,mid,high);
        return count;
    }
    int countRevPairs(vector<int> &arr)
    {
        return mergesort(arr,0,arr.size()-1);
        
    }
};