class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(begin(seats), end(seats));
        sort(begin(students), end(students));
        int moves = 0;

        for(int i = 0; i < seats.size(); ++i) {
            moves += abs(seats[i] - students[i]);
        }
        
        return moves;
    }
};