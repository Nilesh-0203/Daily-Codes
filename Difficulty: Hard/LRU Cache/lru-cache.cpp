//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
  public:
    // Constructor for initializing the cache capacity with the given value.
    list<pair<int, int>> dq;
    unordered_map<int, list<pair<int, int>> :: iterator> ma;
    int n;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        n = cap;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        auto it = ma.find(key);
        if(it == ma.end())
          return -1;
        
        //int ans;  
        else
        {
            dq.splice(dq.begin(), dq, it->second);
            
            return it->second->second;
        }
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
         if(ma.find(key) == ma.end())
        {
            if(dq.size() == n)
            {
                pair<int, int> last = dq.back();
                dq.pop_back();
                
                ma.erase(last.first);
            }
        }
        
        else
          dq.erase(ma[key]);
          
        dq.push_front({key, value});
        ma[key] = dq.begin();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends