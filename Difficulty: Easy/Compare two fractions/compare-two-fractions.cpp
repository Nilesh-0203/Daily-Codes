//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        string a="";
        string b="";
        string c="";
        string d="";
        int i=0;
        for(i=0;i<str.length();i++){
            if(str[i]=='/'){
                break;
            }
            a+=str[i];
        }
        i++;
        while(i<str.length()){
            if(str[i]==','){
                break;
            }
            b+=str[i];
            i++;
        }
        i+=2;
        while(i<str.length()){
            if(str[i]=='/'){
                break;
            }
            c+=str[i];
            i++;
        }
        i++;
        while(i<str.length()){
            d+=str[i];
            i++;
        }
        //cout<<"a : "<<a<<" "<<"b : "<<b<<" "<<c<<" "<<d;
        double l=stoi(a);
        double m=stoi(b);
        double n=stoi(c);
        double p=stoi(d);
        
        double ans1=l/m;
        double ans2=n/p;
        if(ans1==ans2){
            return "equal";
        }
        else if(ans1>ans2){
            return a+"/"+b;
        }
        else{
            return c+"/"+d;
        }
        return "";
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends