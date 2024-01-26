//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
     {
        // Your code here
        priority_queue<pair<double,int>> pq;
        
        for(int i = 0; i<n ; i++){
            pq.push({(arr[i].value*1.0/arr[i].weight) , arr[i].weight});
        }
        
        double sum = 0;
        double profit = 0;
        
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            
            if(sum + it.second <= W){
                sum += it.second*1.0;
                profit += it.second*it.first*1.0;
            }
            else{
                double rem = W - sum;
                profit += rem*it.first*1.0;
                break;
            }
        }
        
        return profit;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends