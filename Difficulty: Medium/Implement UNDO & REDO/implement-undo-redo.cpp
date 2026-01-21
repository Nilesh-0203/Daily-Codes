class Solution {
  public:
    string current="";
  string past="";
    void append(char x) {
        // append x into document
        current.push_back(x);
    }

    void undo() {
        // undo last change
        past.push_back(current.back());
        current.pop_back();
    }

    void redo() {
        // redo changes
        current.push_back(past.back());
        past.pop_back();
    }

    string read() {
        // read the document
       string res="";
       for(int i=0;i<current.size();i++){
           res+=current[i];
       }
       return res;
        
    }
};