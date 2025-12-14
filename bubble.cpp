#include <iostream>
#include<ctime>
using namespace std;

int main() {
    
    int arr[]={10,1,4,3,6,5,8,7,25,9};

    int temp;
    bool sort=false;
    int index=0;
    int size=sizeof(arr)/sizeof(int);
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                
            }
        }
    }
    for(int num:arr){
        cout<<num<<" ";
    }
    return 0;
}
