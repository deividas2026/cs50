#include <cs50.h>
#include <stdio.h>

#define QUARTER 25
#define DIME 10
#define NICKEL 5

int main(int argc, char *argv[])
{
    int coins = 0;
    int cash;
    
    do
    {
        cash = get_int("Cash owed: ");
    }
    while (cash < 0);
    

    if (cash >= QUARTER)
    {
        coins += cash / QUARTER;
        cash %= QUARTER;
    }
    
    if (cash >= DIME)
    {
        coins += cash / DIME;
        cash %= DIME;
    }

    if (cash >= NICKEL)
    {
        coins += cash / NICKEL;
        cash %= NICKEL;
    }
    
    coins += cash;
    printf("%d\n", coins);

    return 0;
}

