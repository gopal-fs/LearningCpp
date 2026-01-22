#include<bits/stdc++.h>
using namespace std;

class solution{
public:
    static bool comparator(const pair<string,int>& p1,
                           const pair<string,int>& p2){
        return p1.second < p2.second;   // price ASC
    }
    
    void sortProducts(vector<pair<string, int>>& products) {
        sort(products.begin(), products.end(), comparator);
    }
    
    void displayProducts(const vector<pair<string, int>>& products) {
        for(const auto &k : products){
            cout << k.first << ":" << k.second << endl;
        }
    }
};
