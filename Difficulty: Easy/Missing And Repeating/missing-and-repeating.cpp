class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
       int xr_all = 0;
       
       for(int i=0;i < n;i++){
           xr_all ^= arr[i];
           xr_all ^= (i+1);
       }
       
       int rightMostSetBit = xr_all & ~(xr_all-1);
      
       int xr_1 = 0,xr_2 = 0;
       for(int i=0;i < n;i++){
           if(arr[i] & rightMostSetBit){
               xr_1 ^= arr[i];
           }else{
               xr_2 ^= arr[i];
           }
           
           if((i+1) & rightMostSetBit){
               xr_1 ^= (i+1);
           }else{
               xr_2 ^= (i+1);
           }
       }
       
       int missing,repeating;
       for(int i=0;i < n;i++){
           if(arr[i]==xr_1){
               repeating = xr_1;
               missing = xr_2;
               break;
           }else if(arr[i] == xr_2){
               repeating = xr_2;
               missing = xr_1;
           }
       }
       
       return {repeating,missing};
    }
};