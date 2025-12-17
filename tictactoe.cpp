#include <iostream>
#include <ctime>
using namespace std;



void drawBoard(char *spaces);
void playerMove(char *spaces,char player);
void computerMove(char *spaces,char computer);
bool checkWinner(char *spaces,char player,char computer);
bool checkTie(char*spaces);

int main() {

    char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player='X';
    char computer='O';
    bool running=true;
    drawBoard(spaces);
    bool playerTurn=true;
    while(running){
        if(playerTurn){
            playerMove(spaces,player);
            drawBoard(spaces);
            playerTurn=false;
            if(checkWinner(spaces,player,computer)){
                cout<<"You Won!";
                running=false;
                break;

            }

        }
        else{
            computerMove(spaces,computer);
            drawBoard(spaces);
            playerTurn=true;
            if(checkWinner(spaces,player,computer)){
                cout<<"Computer Won!";
                running=false;
                break;

            }

        }
        if(checkTie(spaces)){
            running=false;
            cout<<"Tie!";

        }
       
        
        
    }

    

    return 0;
}


void drawBoard(char *spaces){
    cout<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<spaces[0]<<"  |  "<<spaces[1]<<"  |  "<<spaces[2]<<"   "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<spaces[3]<<"  |  "<<spaces[4]<<"  |  "<<spaces[5]<<"   "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<spaces[6]<<"  |  "<<spaces[7]<<"  |  "<<spaces[8]<<"   "<<endl;
    cout<<"     |     |     "<<endl;
    cout<<endl;
    
    

}
void playerMove(char *spaces,char player){
   int number;

   do{
    cout<<"Enter a Spot to place a marker[1-9]:";
    cin>>number;
    number--;
    if(spaces[number]==' '){
        spaces[number]=player;
        break;
    }

   }while (number < 0 || number > 8 || spaces[number] != ' ');

}
void computerMove(char *spaces,char computer){
   srand(time(NULL));
   bool run=true;
   do{
        int number=rand()%9;
        if(spaces[number]==' '){
            spaces[number]=computer;
            run=false;
        }
        

   }while(run);

}
bool checkWinner(char *spaces,char player,char computer){
    int winPatterns[8][3] = {
    {0, 1, 2}, 
    {3, 4, 5}, 
    {6, 7, 8}, 

    {0, 3, 6}, 
    {1, 4, 7}, 
    {2, 5, 8}, 

    {0, 4, 8}, 
    {2, 4, 6}  
    };
    int rows=sizeof(winPatterns)/sizeof(winPatterns[0]);
    for(int i=0;i<rows;i++){
        if(spaces[winPatterns[i][0]]=='X' && spaces[winPatterns[i][1]]=='X' && spaces[winPatterns[i][2]]=='X'){
            return true;
        }
        else if(spaces[winPatterns[i][0]]=='O' && spaces[winPatterns[i][1]]=='O' && spaces[winPatterns[i][2]]=='O'){
            return true;
        }
        

    }
    return false;
}
bool checkTie(char *spaces){
    for(int i=0;i<9;i++){
        if(spaces[i]==' ') return false;
    }
    return true;
   
}