#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct card
{
    const char *face;
    const char *suit;
};

int main()
{
    srand(time(NULL));
    int decknum = 51;
    struct card deste[52];
    int i = 0;
    struct card temp;

    const char *faces[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    for (i = 0; i < 52; i++)
    {
        deste[i].face = faces[i % 13];
        deste[i].suit = suits[i / 13];
    }

    for (i = decknum; i >= 0; i--)
    {

        int random = rand() % (i + 1);
        printf("%s  of  %s  \t", deste[random].face, deste[random].suit);
        if (i % 2 == 0)
        {
            printf("\n");
        }

        temp = deste[random];
        deste[random] = deste[i];
        deste[i] = temp;
    }
    return 0;
}