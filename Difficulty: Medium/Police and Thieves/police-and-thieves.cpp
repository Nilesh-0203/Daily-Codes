class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        int n = arr.size();
        int m = k+1;
        int count = 0;
        deque<int>police;
        deque<int>thief;
            
        for(int i=0;i<n;i++){
            if(arr[i]=='P'){
                if(thief.empty()){
                    police.push_back(i);
                }
                else{
                    while(!thief.empty() && i-thief.front()>k){
                        thief.pop_front();
                    }
                    if(!thief.empty()){
                        thief.pop_front();
                        count++;
                    }
                }
            }
            else{
                if(police.empty()){
                    thief.push_back(i);
                }
                else{
                    while(!police.empty() && i-police.front()>k){
                        police.pop_front();
                    }
                    if(!police.empty()){
                        police.pop_front();
                        count++;
                    }
                }
            }
        }
        return count;
    }
};