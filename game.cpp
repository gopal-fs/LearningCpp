#include <iostream>
#include<ctime>
using namespace std;


string findChoice(char res);

char userChoice(){
    char userOp;
    do{
        cout<<"Choose One of the following"<<endl;
        cout<<"r for Rock"<<endl;
        cout<<"p for Paper"<<endl;
        cout<<"s for Scissor"<<endl;
        cin>>userOp;
    }while(userOp!='r' && userOp!='p' && userOp!='s');
    cout<<"You CHoose: "<<findChoice(userOp)<<endl;
    return userOp;
}

string chooseWinner(char user,char comp){
    switch (user)
    {
    case 'r':
        if(comp=='r') return "Tie!";
        else if(comp=='p') return "Computer Won!";
        else if(comp=='s') return "You Won!";
        break;
    case 'p':
        if(comp=='p') return "Tie!";
        else if(comp=='s') return "Computer Won!";
        else if(comp=='r') return "You Won!";
        break;
    case 's':
        if(comp=='s') return "Tie!";
        else if(comp=='r') return "Computer Won!";
        else if(comp=='p') return "You Won!";
        break;
    
    default:
        break;
    }

}
char ComputerChoice(){
    srand(time(NULL));
    int computerNum=rand()%3+1;
    char comp;
    switch (computerNum)
    {
    case 1:
        comp='r';
        break;
    case 2:
        comp='p';
        break;
    case 3:
        comp='s';
        break;
    default:
        cout<<"Enter Valid One.."<<endl;
        break;
    }

    cout<<"Computers Choice: "<<findChoice(comp)<<endl;
    return comp;

}

string findChoice(char res){
    
    if(res=='r') return "Rock";
    else if(res=='p') return "Paper";
    else if(res=='s') return "Scissor";

}




int main() {
    
    cout << "******************ROCK PAPER SCISSOR GAME*************************" << endl;
    char user=userChoice();
    char comp=ComputerChoice();

    cout<<chooseWinner(user,comp)<<endl;
    

    cout << "*******************END***************************" << endl;
    return 0;
}
