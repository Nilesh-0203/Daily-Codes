class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {
        vector<int> ans;
        vector<int> prefix;
        int sum = 0;
        for(int i = 0;i<arr.size();i++){
            sum += arr[i];
            prefix.push_back(sum);
        }
        for(int i = 0;i<arr.size();i++){
            int mid = (0 + i)/2;
            int main = arr[mid];
            int sum1 = main*(mid) - (prefix[mid-1]);
            int sum2 = (prefix[i] - prefix[mid]) - (main*(i-mid));
            ans.push_back(sum1+sum2);
        }
        return ans;
    }
};