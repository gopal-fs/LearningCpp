#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    void countWords(map<string, int>& wordCount, const string& paragraph) {
        //Write your code here...
        stringstream ss(paragraph);
        string word;
        while(ss>>word){
            wordCount[word]++;
        }
        
    }
    
    void displayWordCount(const map<string, int>& wordCount) {
        //Write your code here...
        for (const auto& pair : wordCount) {
        cout << pair.first << "-" << pair.second << endl;
    }
        
    }
};