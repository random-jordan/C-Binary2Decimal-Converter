/**
 * Binary to Decimal Converter
*/
#include <stdio.h>
#include <string.h>

double power(long double number, int times){
    if(times == 0)
    {
        return 1;
    }
    float original = number;
    number = (double) number;
    for (int i = 1; i < times; i++)
    {
        number *= original;
    }
    return number;
};

int main()
{
    char c[17];
    int floatingDotIndex, numbersLength;
    long double decimal = 0.0L;
    printf("  Enter a Real Number in binary form : ");
    scanf("%s", c);
    numbersLength = strlen(c);

    // if more than 16 bit written
    if(numbersLength > 17)
    {
        printf("***Error! number is more than 16 bit!***\n");
        return 0;
    }

    //finding floating dot index
    for(int i = 0; i < numbersLength; i++)
    {
        if(c[i] == '.')
        {
            floatingDotIndex = i;
            break;
        }
    }

    // finding integer part of number
    for(int i = 0; i < floatingDotIndex; i++)
    {
        if(c[i] == '1')
        {
            decimal += power(2, (floatingDotIndex - i - 1));
        } 
        else if(c[i] == '0') 
        {
            continue;
        } 
        else 
        {
            printf("***Wrong input!***\n");
            return 0;
        }
    }

    //finding fractional part of number
    for (int i = floatingDotIndex + 1; i < numbersLength; i++)
    {
        if(c[i] == '1')
        {
            decimal += power(0.5, (i - floatingDotIndex));
        } 
        else if(c[i] == '0') 
        {
            continue;
        } 
        else 
        {
            printf("***Wrong input!***\n");
            return 0;
        }   
    }
    

    printf("  Real number in Decimal form : %16.8Lf\n", decimal);
    return 0;
}
