/*
Name: Collin Puchta
Program Name: GHP #1
Written in: C++, Using Code::Blocks IDE, and compiled using the GCC Compiler
Last Modified: 1/31/19
Description: This program requires the user to enter an integer, then enter 9 more integers.
the program then outputs either 0 or 1 for each of thoe 9 integers, 1 if the integer entered is equal to the
integer initially entered, and 0 otherwise
*/

#include <iostream>
using namespace std;

int matrix[3][3]; //List is used to store the user's input. This is a 3x3 Matrix, I set it at size [3][3] because at [2][2] it was acting weird (feel free to change it back to see what I mean)
int input; //Used to represent the integer the user enters for the program to look for.
int x; //Used at the end of the program to

int main(void){

cout<<"GHP #1\nBy: Collin Puchta\n\n"; //GUI
cout<<"Enter an integer to be searched for:\n";
cin>>input; //The number we are testing for (Comparing w/ user input)
cout<<"\nEnter 9 integers into the program, and it will detect if any are equal to the one you have entered.\n";
cout<<"If the number is equal, the program will output the number 1. Otherwise, it will output the number 0.\n";

for(int h=0;h<=2;h++){ //Loop used to allow the user to input the values of the 3x3 matrix
    for(int i=0;i<=2;i++){
    cout<<"\nEnter the item to be stored in Row "<<h+1<<" , Column "<<i+1<<": ";
    cin>>matrix[h][i];
    cout<<"\nStored at: "<<h<<" and "<<i<<" \n";
}}

for(int h=0;h<3;h++){ //Loop used to test whether or not the values in the matrix are equal to the selected value (Output)
    for(int i=0;i<3;i++){
    if(matrix[h][i] == input){
        cout<<"Row Number "<<h+1<<" Column Number "<<i+1<<" is "<<1<<" (You entered "<<matrix[h][i]<<")\n"; //If the integer entered is equal to the integer the user entered, output the item # and then the # 1
    }
    if(matrix[h][i] != input){
        cout<<"Row Number "<<h+1<<" Column Number "<<i+1<<" is "<<0<<" (You entered "<<matrix[h][i]<<")\n"; //if the integer entered is not equal to the integer the user entered, output the item # and then the # 0

}}}

cout<<"Input any character and press <ENTER> to end the program\n"; //For users running the .exe, to ensure that they can see all data
cin>>x;
return 0; //End Program
}
