#include<iostream>
using namespace std;
int main(){

    int a;
    
    do{
        cout<<"Enter A Value Between 1-10 :"<<endl;
        cin>>a;
        
    }while(a<1 || a>10);
    
    cout<<"Success";
    return 0;
}