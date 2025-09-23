class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        stack<int>s;
        while(!q.empty()){
            int t=q.front();
            s.push(t);
            q.pop();
        }
        queue<int>que;
        while(!s.empty()){
            int t=s.top();
            que.push(t);
            s.pop();
        }
        q=que;
    }
};