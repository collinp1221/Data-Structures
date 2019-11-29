#include <iostream>
using namespace std;

#include "stack.h"

bool loop = 1; //Used to make the user input numbers until they input an integer greater than 1
int input = 0; //User input number
int number; //Used to find the Prime Factors of input

Stack(factors); //Generate a stack called factors

int main(void){

cout<<"Enter an integer greater than 1"<<endl; //User input
while(loop == 1){ //Loops until the user enters an integer greater than 1
    cin>>input;
    if(input > 1){
        loop = 0;
    }
    else{
        cout<<"Invalid Input! You must enter an input greater than 1!"<<endl;
    }
}

number = input; //Set number equal to the value of input

for(int d = 2;number > 1; d ++){ //if d can divide evenly into number, push that number onto the stack and divide number by d. Then reset d to 2. Otherwise, increment d by 1.
    if(number % d == 0){
        factors.push(d);
        number = number / d;
        d = 1;
    }
}

cout<<endl<<"The prime factors of "<<input<<" are:"<<endl; //Output
factors.display(cout);

return 0; //End Program
}
