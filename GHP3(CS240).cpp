/*
Name: Collin Puchta
Program Name: GHP#3 (Alternate Assignment)
Written In: C++ (Compiled using GNU GCC Compiler) using the Code;;Blocks IDE
Description: Queries the user for a file name, then reads that file
and determines how many words within do not start with the letter 'D'


Information was taken from http://www.cplusplus.com/doc/tutorial/files/ and Professor Sarner's lectures and handouts
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string filename; //User input for what file to open
string line; //Each line of selected file is written here (gets overwritten each time)
int position = 0; //Used to track position of selected character while reading file
int not_d_words = 0;//Counter for each word that does not start with the letter 'D'

int main(void){

cout<<"Enter the name of a file to be processed:\n";
cin>>filename; //User inputs the filename to be opened

ifstream fileIn; //declaring fileIn as an input stream

fileIn.open(filename.data()); //Attempts to open entered file name

if(fileIn.is_open()){ //Check to see if the file the user entered has been opened

while(getline(fileIn, line)){ //Get each line in the opened file
    position = 0; //reset the position of selected character each time a new line is written
    while(position <= line.length()){//Read each character on selected line (stored in variable 'line')
        if(line[position] != 'D' && line[position] != 'd' && line[position] != ' ' && line[position] != '\0'){//check if selected character is not d or a space
            if(position == 0){ //If selected character is the first in its line, and is not a 'd' or a space, it is a word that doesn't start with 'd'
                not_d_words ++;
            }
            else{
                if(line[position - 1] == ' '){//If selected character is preceded by a space, and is not a 'd' or a space, it is a word that doesn't start with 'd'
                    not_d_words ++;
                }
            }
        }
    position ++; //Increment position by 1 after a character is read
    }
}
cout<<"The number of words in "<<filename<<" that do not start with the letter 'D' is: "<<not_d_words;  //Output the number of words that do not start w/ the letter 'd'
fileIn.close(); //Close the file that was read from
}
else{
    cout<<"ERROR: File could not be found\n"; //If file could not be found, notify the user.
}
return 0; //Exit program
}
