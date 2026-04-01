class Solution {
  public:
    int countStrings(int n) {
        // code here
         int a = 1;
        int b = 1;
        for(int i =0;i<n;i++)
        {
            int sum = a+b;
            b = a;
            a = sum;
        }
        return a;
    }
};