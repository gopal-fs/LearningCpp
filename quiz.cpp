#include <iostream>
#include<ctime>
using namespace std;

int main() {
    
    string questions[]={"What Year C++ Created?","Who Invented C++","what is the predecessor of c++","is the earth flat?"};
    string options[][4]={
        {"A. 1969","B. 1975","C. 1985","D. 1989"},
        {"A. Guido Van Rossum","B. Bjarne stroustrup","C. John","D. Marck Zuckerburg"},
        {"A. C", "B. C+","C. C--","D. B++"},
        {"A. yes","B. no","C. sometimes","D. None of the above"}
    };
    char answerKey[]={'C','B','A','B'};
    int score=0;

    int questionsSize=sizeof(questions)/sizeof(string);
    for(int i=0;i<questionsSize;i++){
        cout<<"************************"<<endl;
        cout<<questions[i]<<endl;
        cout<<"************************"<<endl;
         cout<<"Options:"<<endl;
        for(int j=0;j<sizeof(options[i])/sizeof(options[i][0]);j++){
           
            cout<<options[i][j]<<endl;
            


            
        }
        char userChoice;
        do{
            cout<<"Please Choose One of the following[A,B,C,D]:";
            cin>>userChoice;
        }while (userChoice !='A' && userChoice !='B' && userChoice !='C' && userChoice !='D');

        if(answerKey[i]==userChoice){
            cout<<"Correct Answer!"<<endl;
            score++;
        }
        else{
            cout<<"Incorrect Answer!"<<endl;
            score--;
        }
    }

    cout<<"*************************************"<<endl;
    cout<<"Hurray You Completed the Quiz! Score: "<<score;
    return 0;
}
