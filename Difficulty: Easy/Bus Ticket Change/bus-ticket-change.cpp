class Solution {
  public:
     bool canServe(vector<int> &arr) {
        int cntFive = 0;
        int cntTen = 0;
        
        for ( int i = 0; i < arr.size(); i++){
            //first we check for 5 ruppes
            if(arr[i] == 5) {
                cntFive++;
            }
            
            else if(arr[i] == 10){
                //check we have 5 ruppes change
                if(cntFive > 0){
                    cntFive--; //ek hata denge
                    cntTen++; //jo paisa aaya use add kr denge
                }else{ //change nhi h
                    return false;
                }
            } 
            else if(arr[i] == 20){
                //check we have 5 and 10 ruppes have or not
                if(cntFive > 0 && cntTen > 0){
                    cntTen--; //10 rupee de diya
                    cntFive--; //phir 5 rupee de deiya
                }else if(cntFive >= 3){ //10 ka nhi h toh 5 ka de do teen
                    cntFive -= 3;
                }else{ //change nhi h
                    return false;
                }
            } else{ 
                return false;
            }
        }
        return true;
        
    }
};