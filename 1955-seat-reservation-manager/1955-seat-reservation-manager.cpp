class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        #pragma unroll
        for(int i=1; i<=n; i++)
            pq.push(i);
    }
    
    int reserve() {
        int x=pq.top();
        pq.pop();
        return x;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */