#include <iostream>
using namespace std;

int main() {
    int index = 0;
    
    int even=0;
    int odd=0;


    /* Approach:
        -First Calculate all the odd positions and check wether that odd position is >9 after multiplying with 2 if yes split and add to odd
        -Second Calculate all the even positons and add to the even variable
        -Third Add that even and odd sum and check if it is divisible by 10 or not if yes valid else Not Valid*/;
        
    long long cardNum= 6011000990139424;
    

    while (cardNum != 0) {
        int lastDigit = cardNum % 10;
        cardNum = cardNum / 10;
        if (index % 2 != 0) {
            int digit=lastDigit*2;
            if(digit>9){
                
                odd+=(digit%10)+(digit/10%10);

            }
            else odd+=digit;
            
           
        }
        else{
            even+=lastDigit;
        }
        index++; 
    }
    
    if((even+odd)%10==0) cout<<"It is a Valid Card Number";
    else cout<<"It is not a valid Card Number";

    return 0;
}
