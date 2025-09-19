class Solution {
  public:
    int minParentheses(string& s) {
        // code here
         int balance = 0;   // counts unmatched '('
    int insertions = 0; // counts needed '('

    for (char c : s) {
        if (c == '(') {
            balance++;  
        } else { // c == ')'
            if (balance > 0) {
                balance--; // match with an '('
            } else {
                insertions++; // need one '(' before this ')'
            }
        }
    }

    // leftover '(' must be closed
    return insertions + balance;
    }
};