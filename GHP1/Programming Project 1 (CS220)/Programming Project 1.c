/*





*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Variable Declarations
int input; //Uses input into the program (# to be converted)
int solution[16];
int finalinput;
int j; //Used in for loops
int e = 0; //Used to calculate the power of 2 when converting from decimal to binary
int a; //Throwaway variable used to prevent the .exe from automatically closing (see lines 49 and 50)


int main()
{
    for(j=0;j<16;j++){ //Sets the list as all 0's
    solution[j] = 0;
    }


    printf("Please enter a decimal number below 65536: \n");
    scanf("%d",&input);
    printf("\n");
    finalinput = input; //Finalinput is used to print out what the input was at the end of the program
    input++;

    while(input > 0){ //Loop to convert decimal to binary

        while( pow(2,e) < input){ //While 2^i is less than the remaining input, increment i by 1
              e++;
              }
        e--; //Decrements i by 1 so it is the largest exponent of 2 that is less than input
        input = input - pow(2,e); //2^i is subtracted from input
        solution[e] = 1; //a 1 is placed in the 'i'th spot in the list
        e = 0;
    }
    printf("The binary value is: ");
    for(j=15;j>=0;j--){ //This loop prints the binary string generated in the previous loop backwards (It was reversed previously)
        printf("%d",solution[j]);
    }

    printf("\n\n\nEnter any integer to end program:\n");
    scanf("%d",a);
    return 0;
}
