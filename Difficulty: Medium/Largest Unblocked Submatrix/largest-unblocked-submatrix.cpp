class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
       set<int>rows, cols;
for (auto it:arr) {
int r = it[0];
int c = it[1];
rows.insert(r);
cols.insert(c);
}
 
vector<int> nrows, ncols;
for (int i = 1; i <= n; i++) {
if (rows.count(i) == 0) {
nrows.push_back(i);
}
}
for(int i=1;i<=m;i++){
    if(cols.count(i)==0){
        ncols.push_back(i);
    }
}
 
// find the consective length in nrows as wll as in the ncols
 
int k = arr.size();
// int i = 0;
// int j = 1;
int cnt1 = 0;
int cnt2 = 0;
int t1 = 1;
int t2 = 1;
 
 
 
 
 
for (int i = 1; i<nrows.size(); i++) {
if (nrows[i] == nrows[i - 1]+1) {
t1++;
}
else {
cnt1 = max(cnt1, t1);
t1 = 1;
 
}
}
 
cnt1 = max(cnt1,t1);
 
for (int i = 1; i<ncols.size(); i++) {
if (ncols[i] == ncols[i - 1]+1) {
t2++;
}
else {
cnt2 = max(cnt2, t2);
t2 = 1;
 
}
}
cnt2 = max(cnt2, t2);
 
   if(nrows.size()==0 || ncols.size()==0) return 0;
return cnt1*cnt2;
}
};