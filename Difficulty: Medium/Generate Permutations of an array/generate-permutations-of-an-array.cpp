class Solution {
  public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>>ans;
        vector<int>temp = arr;
        ans.push_back(temp);
        while(next_permutation(temp.begin(),temp.end())){
            ans.push_back(temp);
        }
        temp = arr;
        while(prev_permutation(temp.begin(),temp.end())){
            ans.push_back(temp);
        }
        return ans;
    }
};