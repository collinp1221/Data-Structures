/*
Written By: Collin Puchta
Program Name: GHP #6
Description: User inputs 15 stock prices, and the program outputs each price, highest and lowest price, daily price
changes, and sorts the prices from low to high

References: http://www.cplusplus.com/reference/vector/vector/ (Used to reference vector class functions)
http://www.cplusplus.com/reference/algorithm/max_element/ (Used to reference the min and max element functions
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void){

//Declarations
vector <int> stocks(15); //Stores the stock prices, as input by the user
vector <int> difference(15); //Stores the data generated by adjacent_difference
int i; //Iterator
bool loop = 1; //Variable to check whether or not the input loop will be looped

//User Inputs Stock Prices
for(i=0;i<15;i++){
    loop = 1;
    while(loop == 1){ //Loop until the user enters a positive integer
        cout<<"Enter the price of the stock on day "<<i+1<<endl;
        cin>>stocks[i];
        if(stocks[i] < 0)
            cout<<"ERROR: Enter a positive integer: "<<endl;
        else
            loop = 0;
    }
}

//Output Stock Prices
cout<<endl<<"Stock Prices: \n\n";
for(i=0;i<15;i++){
    cout<<"Day "<<i+1<<":  "<<stocks[i]<<endl;
}

//Output the highest and lowest stock prices
cout<<"The highest trading price is: "<<*max_element(stocks.begin(),stocks.end())<<endl;
cout<<"The lowest trading price is: "<<*min_element(stocks.begin(),stocks.end())<<endl;

//Calculate the difference between adjacent items in vector "stocks" and output it
adjacent_difference(stocks.begin(),stocks.end(),difference.begin());
cout<<endl<<"Daily Price Difference: "<<endl;
for(i=0;i<15;i++){
    cout<<"Day "<<i+1<<": ";
    if(difference[i] > 0) //Add a '+' to positive values
        cout<<"+";
    cout<<difference[i]<<endl;
}

//Sort vector Stocks from low to high, and output vector Stocks
sort(stocks.begin(),stocks.end());
cout<<endl<<"Stocks Sorted from Low to High:"<<endl;
for(i=0;i<15;i++){
    cout<<stocks[i]<<endl;
}

//End Program
return 0;
}
