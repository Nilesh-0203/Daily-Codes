class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        
        int n = a.size();
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        
        int i,j,k;
        i=j=k=0;
        
        int t1=0,t2=0,t3=0;
        int value = INT_MAX;
        
        while(i<n && j<n && k<n){
            
           int largest = a[i];
           if(largest<b[j])largest = b[j];
           if(largest<c[k])largest = c[k];
           
           char z = 'a';
           int smallest = a[i];
           if(smallest>b[j]){smallest = b[j];z='b';}
           if(smallest>c[k]){smallest = c[k];z='c';}
           
           int diff = largest-smallest;
           
           if(diff<value){
               value=diff;
               t1=a[i];
               t2=b[j];
               t3=c[k];
           }
           
           if(z=='a')i++;
           else if(z=='b')j++;
           else k++;
           
            
        }
        
        vector<int>ans;
        ans.push_back(t1);
        ans.push_back(t2);
        ans.push_back(t3);
        
        sort(ans.begin(),ans.end(),greater<int>());
        
        return ans;
        
        
    }
};