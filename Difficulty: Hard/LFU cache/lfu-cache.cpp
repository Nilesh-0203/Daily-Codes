//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#include <unordered_map>
#include <list>

class LFUCache {
private:
    int capacity;
    int minFrequency; // Minimum frequency in the cache
    std::unordered_map<int, std::pair<int, int>> keyData; // key -> {value, frequency}
    std::unordered_map<int, std::list<int>> frequencyKeys; // frequency -> list of keys
    std::unordered_map<int, std::list<int>::iterator> keyIter; // key -> iterator to the key in frequencyKeys

public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        minFrequency = 0;
    }
    
    int get(int key) {
        if (keyData.find(key) == keyData.end()) {
            return -1;
        }

        int frequency = keyData[key].second;
        auto it = keyIter[key];

        // Update frequency and move the key to the next frequency list
        frequencyKeys[frequency].erase(it);
        frequencyKeys[frequency + 1].push_back(key);
        keyIter[key] = --frequencyKeys[frequency + 1].end();

        // If the minimum frequency list is empty, update minFrequency
        if (frequencyKeys[minFrequency].empty()) {
            minFrequency++;
        }

        return keyData[key].first;
    }
    
    void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }

        // If key already exists, update its value and frequency
        if (keyData.find(key) != keyData.end()) {
            keyData[key].first = value;
            get(key); // Update frequency
            return;
        }

        // If capacity is reached, remove the LFU key
        if (keyData.size() >= capacity) {
            int lfuKey = frequencyKeys[minFrequency].front();
            frequencyKeys[minFrequency].pop_front();
            keyData.erase(lfuKey);
            keyIter.erase(lfuKey);
        }

        // Add the new key with value, frequency, and iterator
        keyData[key] = {value, 1};
        frequencyKeys[1].push_back(key);
        keyIter[key] = --frequencyKeys[1].end();
        minFrequency = 1; // Reset minFrequency to 1
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LFUCache *cache = new LFUCache(capacity);

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