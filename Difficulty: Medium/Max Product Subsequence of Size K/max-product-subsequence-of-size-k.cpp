class Solution {
  public:
     int maxProduct(vector<int> &arr, int k) {


         const long long NEG_INF = LLONG_MIN;
         const long long POS_INF = LLONG_MAX;

         vector<long long> mx(k + 1, NEG_INF);
         vector<long long> mn(k + 1, POS_INF);

         mx[0] = 1;
         mn[0] = 1;

         for (int x : arr) {

             for (int j = k; j >= 1; j--) {

                 long long oldMax = mx[j - 1];
                 long long oldMin = mn[j - 1];

                 if (oldMax != NEG_INF) {
                     mx[j] = max(mx[j], oldMax * x);
                     mn[j] = min(mn[j], oldMax * x);
                 }

                 if (oldMin != POS_INF) {
                     mx[j] = max(mx[j], oldMin * x);
                     mn[j] = min(mn[j], oldMin * x);
                 }
             }
         }

         return (int)mx[k];

        }
};