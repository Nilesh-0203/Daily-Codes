// User function template for C++
class Solution {
  public:
     int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int ans = 0 , maxi = 0 ;
        int n = arr.size() ,m= arr[0].size();
        for(int i = 0 ; i < n ; i++ ){
            int sum = 0 ;
            for(int j = 0 ; j < m ; j++){
                sum += arr[i][j];
            }
            if(maxi < sum ) ans = i;
            maxi = max(maxi , sum);
        }
        
        return maxi != 0 ? ans : -1;
    }
};