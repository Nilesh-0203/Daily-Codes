class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t=minutesToTest/minutesToDie+1;
        int pigs=0;
        while(pow(t,pigs) < buckets){
            pigs++;
        }
        return pigs;
    }
};