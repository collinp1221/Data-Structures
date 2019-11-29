/*
Name: Collin Puchta
Written in: C++ (Compiled Using GNU GCC Compiler)
Program Name: GHP #5 (Alternate Assignment)
Description: Queries the user for a filename, and then reads that file, and outputs the number of palindromes in that file (Only the first word in each line will be read)
*/

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

string filename; //Name of the file the user inputs
string line; //Current line of the file being processed
bool loop = 1; //Variable used to track whether or not to loop a while loop
int wordcount = 0; //Tracks number of words processed
int palindromecount = 0; //Tracks number of palindromes processed
int length = 0; //Variable used to track the length of the first word in string 'line'
int i = 0; //Variable incremented in for loops
bool isPalindrome = 1; //Variable used to track whether or not variable being checked can be a palindrome. 1 = yes(true), 0 = no(false)
ifstream fileIn;
stack <char> words; //Stack to hold the word being processed
queue <char> wordq; //Queue to hold the word being processed
queue <char> temp; //Temporary queue, which is a copy of wordq for the purpose of printing out the queue is it is a palindrome after the word is processed

int main(void){
while(loop == 1){ //Loop until a correct filename is found, and then write that to variable 'filename'
    cout<<"Enter the name of the file to be read: ";
    cin>>filename;

    //Attempt to open the file that the user entered
    fileIn.open(filename.data());
    if(fileIn.is_open()) //If the file is able to be opened, end the loop, otherwise output an error message
        loop = 0;
    else{
        cout<<"ERROR: File could not be found"<<endl;
        fileIn.close();
    }
}


while(getline(fileIn,line)){ //get a line of text from the file opened (Done one line at a time)

    length = line.length(); //Assume that the length of the word is equal to the length of the line, unless proven otherwise
    for(i = 0;i < line.length();i++){ //Loop to find the length of the first word of the line
        if(line[i+1] == ' '){ //If the next character is a space:
            length = i + 1; //length of the first word is equal to the current position plus 1 (to represent the actual size of the word, not 1 less)
            i = line.length(); //Exit for loop
        }
    }

    for(i = 0;i < length;i++){ //Put word of size length onto stack words and queue wordq
        words.push(line[i]); //Word stored in a stack
        wordq.push(line[i]); //Word stored in a queue
    }
    temp = wordq; //Set queue temp as a copy of queue wordq


    for(i=0;i < length;i++){ //Check if the word is a palindrome by comparing the stack and queue of that word
        if(words.top() != wordq.front())
            isPalindrome = 0; //Is not a palindrome
        //Remove the top value of the stack and the front value of the queue
        words.pop();
        wordq.pop();
    }


    if(isPalindrome == 1){ //If processed word is a palindrome:
        palindromecount ++; //Increment palindrome counter by 1
        for(i = 0;i < length;i++){ //Output the palindrome
            cout<<temp.front();
            temp.pop();
        }
        cout<<endl; //Line break to make output legible
    }

//Things that occur right before reading the next line of text//

    isPalindrome = 1; //Reset variable isPalindrome to its initial value
    wordcount ++; //Increment word counter by 1
    length = 0; //Reset the length tracker to zero
}

//Output the number of words and palindromes processed
cout<<"The total number of words processed was: "<<wordcount<<endl;
cout<<"The total number of palindromes processed was: "<<palindromecount<<endl;


return 0; //End program
}


