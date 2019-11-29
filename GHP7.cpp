/*
Name: GHP #7
Written By: Collin Puchta
Written In: C++ Using Code::Blocks IDE and GNU GCC Compiler
Description: Program to store 15 user-inputted strings in a hash table, using the hash function '((first_letter) +  (last_letter))%23'
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Hash{
    public:


    //Fills the hash table with junk data, to signify that every location in the table is empty. This is required
    //before running hash.fill()
    int create(void){
        //vector <string> hashtable(23); //Create a vector to be used as the hash table
        for(int i=0;i<23;i++)
            hashtable[i] = "GaRbAgE_sTrInG_1258876315"; //Fill the hash table with "garbage data" to signify that these slots are available
        return 0;
    }

    //Add string 'input' to the hash table, using the hash function '((first + last)%23)'
    int fill(string input){
        char first = input.at(0); //Set equal to first character of string input
        char last = input.at(input.size()-1); //Set equal to last character of string input;
        int hashvalue = ((first + last)%23); //Implementation of hash function on string input
        int i = 0; //Iterator
        int k; //Used as a copy of i
        bool loop = 1; //Tracks whether or not to loop a while loop

        while(loop == 1){
            k = i; //k is set equal to i, so that the program can modify k without disrupting i from counting the number of iterations of this while loop

            if((k + hashvalue) >= 23) //If the sum of i and hashvalue exceeds 22, subtract 23 from i. This causes the target of the next loop to wrap around to position 0, instead of 23
                k=k-23;

            if(hashtable[hashvalue+k] == "GaRbAgE_sTrInG_1258876315"){ //If selected location is empty (signified by presence of garbage string), place user input inside of it, and end the loop
                hashtable[hashvalue+k] = input;
                loop = 0;
            }

            i++; //Increment i

            //After 23 attempts (testing every position), display an error message and exit loop
            if(i == 24){
                loop = 0; //End loop
                cout<<"ERROR: Hash table is full. Unable to add element to table"<<endl; //Display error message
            }
        }
        return 0; //Exit function 'fill'
    }

    //Outputs the hash table
    int display(void){
        cout<<"\n\n\nHash Table:"<<endl;

        for(int i=0;i<23;i++){
            cout<<"Position #"<<i<<":  ";
            if(i < 10) //Add an extra space for numbers under 10 (for formatting)
                cout<<" ";
            if(hashtable[i] == "GaRbAgE_sTrInG_1258876315") //If selected location is empty (signified by presence of garbage string), print <empty>
                cout<<"<Empty>"<<endl;
            else
                cout<<hashtable[i]<<endl;
        }
        return 0; //Exit function 'display'
    }

    //Checks to see if string input is in the hash table, and outputs the result
    int check(string input){
        char first = input.at(0); //Set first to the first character of string input
        char last = input.at(input.size() - 1); //Set last to the last character of string input
        int hashvalue = ((first + last)%23); //Implementation of hash function on string input
        bool loop = 1; //Loop tracker
        int i = 0; //Iterator
        int icopy;

        while(loop == 1){
            icopy = i;
            if((hashvalue + icopy) > 22)
                icopy = icopy - 23;
            if(hashtable[hashvalue + icopy] == input){
                cout<<"String "<<input<<" was found at position "<<hashvalue<<endl;
                loop = 0;
            }

            i++; //Increment i
            if(i > 22 && loop == 1){
                cout<<"String "<<input<<" could not be found"<<endl;
                loop = 0; //Exit loop
            }
        }
        return 0;
    }
    private:

    vector <string> hashtable = vector <string>(23); //Vector to be used as the hash table
};

int main(void)
{
    string input; //Used to store user input
    int i; //Iterator
    Hash hashobject; //Initialize object 'hashobject'
    hashobject.create(); //Initialize the hash table (required)
    bool loop = 1; //Loop tracker

    //User inputs 15 words, one by one, which are then placed inside of the hash table
    cout<<"Instructions: Enter fifteen words to be placed inside of a hash table (Note: Program is Case-Sensitive)"<<endl<<endl;
    for(i=0;i<15;i++){
        cout<<"Enter word #"<<i+1<<":  ";//Example Output: Enter word # 4:
        if(i < 9) //Add an extra space for numbers under 10 (for formatting)
            cout<<" ";
        cin>>input;
        hashobject.fill(input); //Add the string input by the user to the hash table
    }
    cout<<endl; //Output and extra endl for formatting

    //Display the hash table
    hashobject.display();

    cout<<endl<<endl<<"Enter a word to check if it is in the hash table, or enter 'STOP' (in all caps) to exit program"<<endl<<endl;
    while(loop == 1){
        cin>>input;
        cout<<endl; //Endline for formatting
        if(input == "STOP") //End loop if user inputs STOP
            loop = 0;
        else
            hashobject.check(input); //Check if input is in the hash table
    }


    return 0; //End program
}
