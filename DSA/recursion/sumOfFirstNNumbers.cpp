#include <bits/stdc++.h>
using namespace std;

int sumOfFirstNumbers(int n){
    
    if(n<=1) return n;
    
    return n+sumOfFirstNumbers(n-1);
    
}

int main() {
	// your code goes here
	
	cout<<sumOfFirstNumbers(5)<<endl;

}
