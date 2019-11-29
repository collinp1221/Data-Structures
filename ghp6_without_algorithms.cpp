/*
Written By: Collin Puchta
Program Name: GHP #6
Description: User inputs 15 stock prices, and the program outputs each price, highest and lowest price, daily price
changes, and sorts the prices from high to low

References: http://www.cplusplus.com/reference/vector/vector/ (Used to reference vector class functions)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){

    //Variable Declarations
    vector <int> stocks(15); //Stores the stock prices input by the user
    vector <int> stocksCopy(15); //Copy of vector "stocks" for use in sorting from highest to lowest
    vector <int> highToLow(15); //vector to store the values of stocks from lowest to high
    vector <int> positions(15); //vector ro store the day corresponding to each stock (used for output of high to low values)
    int highest_price = 0; //Stores the location of the highest number in vector "stocks" (defaults to 0)
    int lowest_price = 0; //Stores the location of the lowest number in vector "stocks" (defaults to 0)
    int current_largest = 0; //Stores highest value in vector "stocksCopy" for the purpose of sorting from highest to lowest
    int i = 0; //Iterator
    int j = 0; //Iterator
    bool loop = 1; //Used to keep track of loops (specifically input loop)

    //User Interface
    cout<<"Stock Tracker"<<endl;
    cout<<"\nInstructions: Enter the stock prices for 15 days in order, starting at day 1, and ending at day 15"<<endl<<endl;

    //User Input
    for(i=0;i<15;i++){
        loop = 1;
        while(loop == 1){
            cout<<"Enter the stock price for day "<<i + 1<<endl;
            cin>>stocks[i];
            cout<<"\n";
            if(stocks[i] >= 0) //Check to make sure input is positive
                loop = 0; //break loop
            else //if not positive, output an error and repeat loop
                cout<<"ERROR: Value must be a positive integer!"<<endl;
        }
    }

    //Output user input in a way that is readable
    cout<<"Stocks over the past 15 days: "<<endl;
    for(i=0;i<15;i++){
        cout<<"Day "<<i+1<<":  "; //Output each day number
        if(i < 9) //Add an extra space when i is less than 9 (day is less than 10), to make everything line up neatly
            cout<<" ";
        cout<<stocks[i]<<endl; //Output the stock price corresponding to what day was output (i+1)
    }

    //copy vector "stocks" to vector "stocksCopy"
    for(i=0;i < 15;i++){
        stocksCopy[i] = stocks[i];
    }

    cout<<"The highest trading value was "<<max_element(stocks[0],stocks[14])<<endl;
    cout<<"The lowest trading value was "<<min_element(stocks[0],stocks[14])<<endl;


    //Determine highest trading price
    for(int i = 1;i<15;i++){
        if(stocks[i] > stocks[highest_price]) //Check each value of vector "stocks" and determine which is the greatest, set variable highest_price to that location
            highest_price = i;
    }

    //Determine lowest trading price
    for(int i = 1;i<15;i++){
        if(stocks[i] < stocks[lowest_price]) //Check each value of vector "stocks" and determine which is the smallest, set variable highest_price to that location
            lowest_price = i;
    }




    //Output greatest and smallest trading prices
    cout<<endl; //Spacing to separate this data from previous outputs
    cout<<"The highest trading value was "<<stocks[highest_price]<<" (Day "<<highest_price + 1<<")"<<endl; //Output highest trading value
    cout<<"The lowest trading value was "<<stocks[lowest_price]<<" (Day "<<lowest_price + 1<<")"<<endl; //Output highest trading value

    //Display the daily changes in price
    cout<<endl; //Space to separate this data from previous outputs
    cout<<"Daily price changes: "<<endl;
    cout<<"Day 1:  N/A"<<endl; //Output Day 1 for the sake of neatness
    for(int i = 1;i<15;i++){
        cout<<"Day "<<i+1<<":  ";
        if(i < 9) //Add an extra space for day 1 - day 9 for formatting
            cout<<" ";
        if(stocks[i]-stocks[i-1] > 0)
            cout<<"+"; //Output a + in front of all positive values
        cout<<stocks[i]-stocks[i-1]<<endl; //Output the value of the current day (i) minus the value of the previous day (i-1)
    }

    //Sort the stocks from high to low
    for(i=0;i<15;i++){
        current_largest = 0;
        for(j=0;j < 15;j++){
            if(stocksCopy[j] >= current_largest){
                current_largest = stocksCopy[j];
                positions[i] = j;
            }
        }
    highToLow[i] = current_largest;
    stocksCopy[positions[i]] = -999; //Set the largest item in stocksCopy to an impossible value
    }

    //Output the stocks from high to low
    cout<<endl<<endl<<"Stock Values from Highest to Lowest: "<<endl;
    for(i=0;i<15;i++){
        cout<<"Day "<<positions[i] + 1<<": ";
        if(positions[i] < 9) //Add an extra space to days 1 through 9 for formatting
            cout<<" ";

        cout<<highToLow[i]<<endl;
    }

return 0; //Exit program
}
