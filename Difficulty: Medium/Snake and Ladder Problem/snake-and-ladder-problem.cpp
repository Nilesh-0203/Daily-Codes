class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
         // code here

         unordered_map<int, int> ladders;
         unordered_map<int, int> snacks;

         for (int i = 0; i + 1 < lad.size(); i+=2) {

             int st = lad[i];
             int end = lad[i+1];

             ladders[st] = end;
         }

         for (int i = 0; i + 1 < sn.size(); i+=2) {

             int st = sn[i];
             int end = sn[i+1];

             snacks[st] = end;
         }

         int ans = 0;
         queue<int> q;
         vector<bool> visited(n*n+1, false);
         visited[1] = true;
         q.push(1);

         while (!q.empty()) {

             int N = q.size();

             while (N--) {

                 int curr = q.front();
                 q.pop();


                 if (curr == n*n) {
                     return ans;
                 }


                 for (int i=1; i<=6; i++) {

                     int newNum = curr + i;
                     if (newNum > n*n) continue;

                     if (ladders.count(newNum)) {
                         newNum = ladders[newNum];
                     } else if (snacks.count(newNum)) {
                         newNum = snacks[newNum];
                     }

                     if (!visited[newNum]) {
                         q.push(newNum);
                         visited[newNum] = true;
                     }
                 }
             }

             ans++;
         }

         return -1;

     }
};