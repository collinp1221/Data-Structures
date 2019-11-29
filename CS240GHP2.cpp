/*
Name: Collin Puchta
Program Name: GHP#2 (Alternate Assignment)
Programmed in: C++ (GNU GCC Compiler)
Description: Allows the user to input an odd integer, and makes a magic square of that size

All code in this program is 100% my own. The only external source I used was Stackoverflow.com for some C++ syntax
*/

#include <iostream>
using namespace std;

bool loop = 1; //Used to infinitely loop the input loop until an odd # is entered
int remainder = 0; //Used to check if input is an odd number
int input = 0; //User input for the magic square size
int square[50][50]; //Array for the magic square to be stored in. Max size is 50

int main(void){

cout<<"Magic Square Generator\nBy: Collin Puchta\n\n";
while(loop==1){ //Gets user input and makes sure it is an odd integer
    cout<<"Enter an odd integer between 1 and 50:  ";
    cin>>input;
    remainder = input%2; //Checks to see if input is actually a positive odd number between 1 and 25
    if(remainder == 0 || input > 50 || input < 0)
        cout<<"Invalid Input\n";
    else
        loop = 0; //Allows the loop to be exited on the condition that the input is odd
        }

for(int a=0;a<50;a++){ //Sets the matrix as all 0's (This will be overwritten)
    for(int b=0;b<50;b++)
        square[a][b] = 0;
}

int c = 0; //Row 0
int d = input/2; //Middle Column
bool alreadyMoved = 0;


//Code to actually build the magic square

for(int k=1;k<=input*input;k++){
    square[c][d] = k; //Set the current position to k (increments once per loop)

    if((c-1 < 0) && (d+1 == input) || ((square[c-1][d+1] != 0) && c != 0 && d+1 != input) ){ //If movement would lead to exiting via the upper right corner OR moving diagonally would overwrite a previously
                                                                   //entered value (any value not equal to zero has been manually written), move down 1
        c++; //Move c down 1
        alreadyMoved = 1; //Prevents program from moving again after moving down
    }
    if( (c-1) < 0 && alreadyMoved == 0){ //Attempt to move c up one
        c = input - 1; //If c goes above the range of the array, move c to the bottom of the array
    }
    else{
        if(alreadyMoved == 0){ //Will fail if c and d have already been moved
            c--; //Move c up one space
            }
    }
    if( (d+1) == input && alreadyMoved == 0){ //Attempt to move d right one
        d = 0; //If d goes outside of the array (input - 1 is the last spot to the right)
    }
    else{
        if(alreadyMoved == 0){
            d++; //Move d to the right one
        }
    }
    alreadyMoved = 0;
}

//Code to print the Magic Square (And space the numbers out properly

int a;
int b;

for(int a=0;a<input;a++){
    cout<<"\n";
    for(int b=0;b<input;b++){

    //Code for properly spacing numbers

        if(input > 3){ //3 is the smallest input that will not generate a number with 2 digits
            if(square[a][b] < 10){
                cout<<" ";
            }
        }
        if(input > 9){ //9 is the smallest input that will not generate a number with 3 digits
            if(square[a][b] < 100){
                cout<<" ";
            }
        }
        if(input > 31){ //31 is the smallest input that will not generate a number with 4 digits
            if(square[a][b] < 1000){
                cout<<" ";
            }
        }
    //Print the actual number

        cout<<square[a][b]<<" ";
    }
    }


cout<<"\n";


return 0;
}
