class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();

        int prev1 = max(h[0], l[0]);

        int prev2 = 0;

        for (int i = 1; i < n; i++) {
            int lowChoice = prev1 + l[i];

            int highChoice = prev2 + h[i];

            int current = max(lowChoice, highChoice);

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};