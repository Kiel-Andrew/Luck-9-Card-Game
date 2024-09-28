#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>

int i, j, number, max, total;
int player_card1, player_card2, player_card3;
int check;
int winner = 0;
int player_result[100];
int player_total[100];
char choice;

void getname(char *name);
int generate_card();
int get_player_decision();

void menu();
void play();
void instruction();
void option();
void quit();

void dealer();
void duel();
void multiplayer();

void truth_or_dare();
void truth();
void dare();


void delay(unsigned int secs)
{
    clock_t interval = clock() + secs;
    while(interval > clock());
}


void loading()
{
    system("cls");

    char *word = "LIBRARIAN'S CHOICE";
    int t = 0;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t ");
    for (t = 0; word[t]; t++)
    {
        printf("%c", word[t]);
        fflush(stdout);
        usleep(100000);
    }
    printf("\r");
}


int main()
{
    delay(3000);
    loading();
    delay(1000);

    do
    {
        system("cls");
        system("COLOR 0F");

        printf("\n\n\n=====================================================================================================================================\n");
        printf("| \t                                                                                                +------------------+        |\n");
        printf("| \t ====              ====         ====     ===========     ====      ====    ====          ====   |     ========     |        |\n");
        printf("| \t ====              ====         ====    =============    ====     ====      ====        ====    |    ==========    |        |\n");
        printf("| \t ====              ====         ====   ====       ====   ====    ====        ====      ====     |   ===      ===   |        |\n");
        printf("| \t ====              ====         ====   ====       ====   ====   ====          ====    ====      |   ===      ===   |        |\n");
        printf("| \t ====              ====         ====   ====              ====  ====            ====  ====       |   ===      ===   |        |\n");
        printf("| \t ====              ====         ====   ====              =========              ========        |    ===========   |        |\n");
        printf("| \t ====              ====         ====   ====              =========               ======         |     ==========   |        |\n");
        printf("| \t ====              ====         ====   ====              ====  ====               ====          |            ===   |        |\n");
        printf("| \t ====              ====         ====   ====       ====   ====   ====              ====          |   ===      ===   |        |\n");
        printf("| \t ====              ====         ====   ====       ====   ====    ====             ====          |   ===      ===   |        |\n");
        printf("| \t ===============    ===============     =============    ====     ====            ====          |    ==========    |        |\n");
        printf("| \t ===============      ===========        ===========     ====      ====           ====          |     ========     |        |\n");
        printf("| \t                                                                                                +------------------+        |\n");
        printf("=====================================================================================================================================\n");
        printf("|                         +-------+                                                               +-------+                         |\n");
        printf("|                         |T      |                                                               |D      |                         |\n");
        printf("|                         |       |                   Press [1]: Start the game                   |       |                         |\n");
        printf("|                         |       |                                                               |       |                         |");
        printf("|                         |       |                   Press [0]: Exit                             |       |                         |\n");
        printf("|                         |      T|                                                               |      D|                         |\n");
        printf("|                         +-------+                                                               +-------+                         |\n");
        printf("=====================================================================================================================================\n");
        printf("|                                                                                                                                   |\n");
        printf("|                                                    Created by: Kiel Andrew Esta                                                   |\n");
        printf("|                                                                                                                                   |\n");
        printf("=====================================================================================================================================\n");

        switch(number = getch())
        {
            case '1': menu();  break;
            case '0': exit(0); break;
        }
    }
    while(number != 1);
}


void menu()
{
    do
    {
        system("cls");
        int code[] = {1, 2, 3, 4};
        char operation [][50] = {"Play", "Instruction", "Option", "Quit" };

        printf("\n\t                                                       +-------------------+                                        \n");
        printf("\t                                        +--------------|     =========     |--------------+                         \n");
        printf("\t                         +--------------|              |    ===========    |              |                         \n");
        printf("\t          +--------------|              |     =========|   ===       ===   |==     ====   |--------------+          \n");
        printf("\t          |              |   ====     ==|    ==========|   ===       ===   |==    ====    |              |          \n");
        printf("\t          |   ====       |   ====     ==|   ====     ==|   ===       ===   |==   ====     |=      ====   |          \n");
        printf("\t          |   ====       |   ====     ==|   ====     ==|    ============   |==  ====      |==    ====    |          \n");
        printf("\t          |   ====       |   ====     ==|   ====       |     ===========   |=======       |===  ====     |          \n");
        printf("\t          |   ====       |   ====     ==|   ====       |             ===   |== ====       |========      |          \n");
        printf("\t          |   ====       |   ====     ==|   ====     ==|   ===       ===   |==  ====      | ======       |          \n");
        printf("\t          |   ====       |   ====     ==|   ====     ==|   ===       ===   |==   ====     |  ====        |          \n");
        printf("\t          |   ====       |   ====     ==|    ==========|    ===========    |==    ====    |  ====        |          \n");
        printf("\t          |   ====       |    ==========|     =========|     =========     |==     ====   |  ====        |          \n");
        printf("\t          |   ===========|     =========|              +-------------------+              |  ====        |          \n");
        printf("\t          |   ===========|              +-------------------+         +-------------------+  ====        |          \n");
        printf("\t          |              +-------------------+                                       |                   |          \n");
        printf("\t          +-------------------+                                                      +-------------------+          \n\n\n\n");

        for(i = 0; i < 4 && sizeof(operation)/sizeof(operation[0]); i++)
        {
            printf("\n\n\t Press [%i]: \t%s\n", code[i], operation[i]);
        }

        switch(number=getch())
        {
            case '1': play();        break;
            case '2': instruction(); break;
            case '3': option();      break;
            case '4': quit();        break;
            default: menu();
        }
    }
    while (number != 4);
}

void play()
{
    do
    {
        system("cls");

        printf("\t ===================================================================================================================\n");
        printf("\t |                                                      PLAY                                                       |\n");
        printf("\t ===================================================================================================================\n\n");
        printf("\t  +-------------------+                          +-------------------+                        +-------------------+ \n");
        printf("\t  |                   |                          |  ==               |                        |      =======      | \n");
        printf("\t  |      ==========   |                          | ===               |                        |     =========     | \n");
        printf("\t  |      ==========   |                          |  ==               |                        |    ===     ===    | \n");
        printf("\t  |         ====      |                          |  ==               |                        |   ===       ===   | \n");
        printf("\t  |         ====      |                          |======             |                        |    ===     ===    | \n");
        printf("\t  |         ====      |                          |                   |                        |           ===     | \n");
        printf("\t  |         ====      |                          |                   |                        |          ===      | \n");
        printf("\t  |         ====      |                          |               ==  |                        |         ===       | \n");
        printf("\t  |   ====  ====      |                          |              ===  |                        |        ===        | \n");
        printf("\t  |   ==========      |                          |               ==  |                        |                   | \n");
        printf("\t  |    ========       |                          |               ==  |                        |        ===        | \n");
        printf("\t  |                   |                          |              ==== |                        |        ===        | \n");
        printf("\t  +-------------------+                          +-------------------+                        +-------------------+ \n");
        printf("\t                                                                                                                    \n");
        printf("\t  Press [1]: Dealer                                 Press [2]: Duel                          Press [3]: Multiplayer \n");
        printf("\n\t ===================================================================================================================\n");
        printf("\t |\t\t\t\t\t\t<---- Press [4]: Back                                              |\n");
        printf("\t ===================================================================================================================\n");

        switch(number = getch())
        {
            case '1': dealer();      break;
            case '2': duel();        break;
            case '3': multiplayer(); break;
            case '4': menu();        break;
            default: play(); break;
        }
    }
    while(number != 4);
}

char player_name[8][50];


void dealer()
{
    system("cls");
    srand(time(NULL));
    int dealer_card1, dealer_card2, dealer_card3, dealer_total;

    printf("\n\t\t\t\t ======================================================================   ");
    printf("\n\t\t\t\t |                           DEALER GAME                              |   ");
    printf("\n\t\t\t\t ====================================================================== \n");

    do
    {
        printf("\n\t\t\t\t  How many players are there? ");
        check = scanf("%d", &max);

        if(check != 1 || max < 1 || max > 10)
        {
            printf("\n\n\t\t\t\t  Invalid number of players. Please enter a number between 1 and 10.\n\n");
            fflush(stdin);
        }
    }
    while (check != 1 || max < 1 || max > 10);

    for(j = 0; j < max; j++)
    {
    printf("\n\t\t\t\t  Enter Player #%i ", j+1);
    getname(player_name[j]);
    }

    for(i = 0; i < max; i++)
    {
        system("cls");

        printf("\n\t\t\t\t ======================================================================   ");
        printf("\n\t\t\t\t |                           DEALER GAME                              |   ");
        printf("\n\t\t\t\t ====================================================================== \n");

        printf("\n\t\t\t\t  Player %s: \n", player_name[i]);
        player_card1 = generate_card();
        player_card2 = generate_card();

        printf("\n\t\t\t\t  Player %s's cards:                                           ", player_name[i]);
        printf("\n\t\t\t\t                        +-------+       +-------+                              ");
        printf("\n\t\t\t\t                        |%d      |       |%d      |", player_card1, player_card2);
        printf("\n\t\t\t\t                        |       |       |       |                              ");
        printf("\n\t\t\t\t                        |       |       |       |                              ");
        printf("\n\t\t\t\t                        |      %d|       |      %d|", player_card1, player_card2);
        printf("\n\t\t\t\t                        +-------+       +-------+                            \n");

        if (get_player_decision() == 1)
        {
            player_card3 = generate_card();
            printf("\n\t\t\t\t  Player %s's 3rd card:             ", player_name[i]);
            printf("\n\t\t\t\t                        +-------+                   ");
            printf("\n\t\t\t\t                        |%d      |   ",  player_card3);
            printf("\n\t\t\t\t                        |       |                   ");
            printf("\n\t\t\t\t                        |       |                   ");
            printf("\n\t\t\t\t                        |      %d|    ", player_card3);
            printf("\n\t\t\t\t                        +-------+                   ");

            player_total[i] = (player_card1 + player_card2 + player_card3) % 10;
            printf("\n\t\t\t\t  Your total is %d.\n\n\n\t\t\t\t  ", player_total[i]);
            system("pause");
        }
        else
        {
            player_total[i] = (player_card1 + player_card2) % 10;
            printf("\n\t\t\t\t  Your total is %d.\n\n\n\t\t\t\t  ", player_total[i]);
            system("pause");
        }
    }

    system("cls");

    printf("\n\t\t\t\t ======================================================================   ");
    printf("\n\t\t\t\t |                           DEALER GAME                              |   ");
    printf("\n\t\t\t\t ====================================================================== \n");

    dealer_card1 = generate_card();
    dealer_card2 = generate_card();

    printf("\n\t\t\t\t  Dealer's cards:                                                              ");
    printf("\n\t\t\t\t                        +-------+       +-------+                              ");
    printf("\n\t\t\t\t                        |%d      |       |%d      |", dealer_card1, dealer_card2);
    printf("\n\t\t\t\t                        |       |       |       |                              ");
    printf("\n\t\t\t\t                        |       |       |       |                              ");
    printf("\n\t\t\t\t                        |      %d|       |      %d|", dealer_card1, dealer_card2);
    printf("\n\t\t\t\t                        +-------+       +-------+                            \n");

    dealer_total = (dealer_card1 + dealer_card2) % 10;

    if(dealer_total < 5)
    {
        dealer_card3 = generate_card();
        printf("\n\t\t\t\t  Dealer's 3rd card:                              ");
        printf("\n\t\t\t\t                        +-------+                 ");
        printf("\n\t\t\t\t                        |%d      |  ", dealer_card3);
        printf("\n\t\t\t\t                        |       |                 ");
        printf("\n\t\t\t\t                        |       |                 ");
        printf("\n\t\t\t\t                        |      %d|  ", dealer_card3);
        printf("\n\t\t\t\t                        +-------+               \n");

        dealer_total = (dealer_card1 + dealer_card2 + dealer_card3) % 10;
        printf("\n\t\t\t\t  Dealer's total: %d\n\n\n\t\t\t\t  ", dealer_total);
        system("pause");
    }
    else
    {
        dealer_total = (dealer_card1 + dealer_card2) % 10;
        printf("\n\t\t\t\t  Dealer's total: %d\n\n\n\t\t\t\t  ", dealer_total);
        system("pause");
    }

    system("cls");

    printf("\n\t\t\t\t ======================================================================   ");
    printf("\n\t\t\t\t |                           DEALER GAME                              |   ");
    printf("\n\t\t\t\t ====================================================================== \n");

    for(i = 0; i < max; i++)
    {
         if(player_total[i] > dealer_total)
        {
            player_result[i] = 1;
        }
        else if(dealer_total > player_total[i])
        {
            player_result[i] = 0;
        }
        else if(player_total[i] == dealer_total)
        {
            player_result[i] = 2;
        }


        if (player_result[i] == 1)
        {
            printf("\n\t\t\t\t  Player %s wins! \n", player_name[i]);
        }
        else if (player_result[i] == 0)
        {
            printf("\n\t\t\t\t  Player %s lose against dealer! \n", player_name[i]);
        }
        else if(player_result[i] == 2)
        {
            printf("\n\t\t\t\t  Tie! Dealer and Player %s. \n", player_name[i]);
        }
    }
    printf("\n\n\t\t\t\t  ");
    system("pause");

    for(i = 0; i < max; i++)
    {
        system("cls");

        printf("\n\t\t\t\t ======================================================================   ");
        printf("\n\t\t\t\t |                           DEALER GAME                              |   ");
        printf("\n\t\t\t\t ====================================================================== \n");

        if(player_result[i] == 0)
        {
            printf("\n\t\t\t\t  Player %s:", player_name[i]);
            truth_or_dare();
        }
    }

    system("cls");

    printf("\n\t\t\t\t ======================================================================   ");
    printf("\n\t\t\t\t |                           DEALER GAME                              |   ");
    printf("\n\t\t\t\t ====================================================================== \n");

    printf("\n\t\t\t\t\t\t      Do you want to play again?");
    printf("\n\t\t\t\t\t\t          [Y]es       [N]o      ");
    choice = getch();
    if(choice == 'y' || choice == 'Y')
    {
        dealer();
    }
    else if(choice == 'n' || choice == 'N')
    {
        play();
    }
}


void duel()
{
    max = 2;
    system("cls");
    srand(time(NULL));

    printf("\n\t\t\t\t ======================================================================   ");
    printf("\n\t\t\t\t |                            DUEL GAME                               |   ");
    printf("\n\t\t\t\t ====================================================================== \n");

    for (j = 0; j < max; j++)
    {
    printf("\n\t\t\t\t  Enter Player #%i ", j+1);
    getname(player_name[j]);
    }

    for(i = 0; i < max; i++)
    {
        system("cls");

        printf("\n\t\t\t\t ======================================================================   ");
        printf("\n\t\t\t\t |                            DUEL GAME                               |   ");
        printf("\n\t\t\t\t ====================================================================== \n");

        printf("\n\t\t\t\t  Player %s: \n", player_name[i]);
        player_card1 = generate_card();
        player_card2 = generate_card();

        printf("\n\t\t\t\t  Player %s's cards:                                           ", player_name[i]);
        printf("\n\t\t\t\t                        +-------+       +-------+                              ");
        printf("\n\t\t\t\t                        |%d      |       |%d      |", player_card1, player_card2);
        printf("\n\t\t\t\t                        |       |       |       |                              ");
        printf("\n\t\t\t\t                        |       |       |       |                              ");
        printf("\n\t\t\t\t                        |      %d|       |      %d|", player_card1, player_card2);
        printf("\n\t\t\t\t                        +-------+       +-------+                            \n");


        if (get_player_decision() == 1)
        {
            player_card3 = generate_card();
            printf("\n\t\t\t\t  Player %s's 3rd card:             ", player_name[i]);
            printf("\n\t\t\t\t                        +-------+                   ");
            printf("\n\t\t\t\t                        |%d      |   ",  player_card3);
            printf("\n\t\t\t\t                        |       |                   ");
            printf("\n\t\t\t\t                        |       |                   ");
            printf("\n\t\t\t\t                        |      %d|    ", player_card3);
            printf("\n\t\t\t\t                        +-------+                   ");

            player_total[i] = (player_card1 + player_card2 + player_card3) % 10;
            printf("\n\t\t\t\t  Your total is %d.\n\n\n\t\t\t\t  ", player_total[i]);
            system("pause");
        }
        else
        {
            player_total[i] = (player_card1 + player_card2) % 10;
            printf("\n\t\t\t\t  Your total is %d.\n\n\n\t\t\t\t  ", player_total[i]);
            system("pause");
        }
    }

    system("cls");

    printf("\n\t\t\t\t ======================================================================   ");
    printf("\n\t\t\t\t |                            DUEL GAME                               |   ");
    printf("\n\t\t\t\t ====================================================================== \n");

    for (i = 0; i < max; i++)
    {
        if (player_total[i] > player_total[winner])
        {
            winner = i;
        }
    }

    if (player_total[0] == player_total[1])
    {
        printf("\n\t\t\t\t  Tie! Player %s & Player %s.\n\n\n\t\t\t\t  ", player_name[0], player_name[1]);
        system("pause");
        play();
    }
    else
    {
        printf("\n\t\t\t\t  Result: \n");
        printf("\n\t\t\t\t  Player %s had the highest total of %d and wins.\n", player_name[winner], player_total[winner]);
        printf("\n\t\t\t\t  Player %s had the lowest total of %d and loses.\n\n\n\t\t\t\t  ", player_name[(winner + 1) % max], player_total[(winner + 1) % max]);
        system("pause");
    }

    system("cls");

    printf("\n\t\t\t\t ======================================================================   ");
    printf("\n\t\t\t\t |                            DUEL GAME                               |   ");
    printf("\n\t\t\t\t ====================================================================== \n");

    printf("\n\t\t\t\t  Player %s:", player_name[(winner + 1)% max]);
    truth_or_dare();


    system("cls");

    printf("\n\t\t\t\t ======================================================================   ");
    printf("\n\t\t\t\t |                            DUEL GAME                               |   ");
    printf("\n\t\t\t\t ====================================================================== \n");

    printf("\n\t\t\t\t\t\t      Do you want to play again?");
    printf("\n\t\t\t\t\t\t          [Y]es       [N]o      ");
    choice = getch();
    if(choice == 'y' || choice == 'Y')
    {
        duel();
    }
    else if(choice == 'n' || choice == 'N')
    {
        play();
    }
}


void multiplayer()
{
    system("cls");

    printf("\n\t\t\t\t ======================================================================   ");
    printf("\n\t\t\t\t |                         MULTIPLAYER GAME                           |   ");
    printf("\n\t\t\t\t ====================================================================== \n");

    do
    {
        printf("\n\t\t\t\t  How many players are there? ");
        check = scanf("%d", &max);

        if(check != 1 || max < 2 || max > 10)
        {
            printf("\n\n\t\t\t\t  Invalid number of players. Please enter a number between 2 and 10.\n\n");
            fflush(stdin);
        }
    }
    while (check != 1 || max < 2 || max > 10);

    for (j = 0; j < max; j++)
    {
    printf("\n\t\t\t\t  Enter Player #%i ", j+1);
    getname(player_name[j]);
    }

    for (i = 0; i < max; i++)
    {
        system("cls");

        printf("\n\t\t\t\t ======================================================================   ");
        printf("\n\t\t\t\t |                         MULTIPLAYER GAME                           |   ");
        printf("\n\t\t\t\t ====================================================================== \n");

        printf("\n\t\t\t\t  Player %s: \n", player_name[i]);
        player_card1 = generate_card();
        player_card2 = generate_card();

        printf("\n\t\t\t\t  Player %s's cards:                                           ", player_name[i]);
        printf("\n\t\t\t\t                        +-------+       +-------+                              ");
        printf("\n\t\t\t\t                        |%d      |       |%d      |", player_card1, player_card2);
        printf("\n\t\t\t\t                        |       |       |       |                              ");
        printf("\n\t\t\t\t                        |       |       |       |                              ");
        printf("\n\t\t\t\t                        |      %d|       |      %d|", player_card1, player_card2);
        printf("\n\t\t\t\t                        +-------+       +-------+                            \n");

        if (get_player_decision() == 1)
        {
            player_card3 = generate_card();
            printf("\n\t\t\t\t  Player %s's 3rd card:             ", player_name[i]);
            printf("\n\t\t\t\t                        +-------+                   ");
            printf("\n\t\t\t\t                        |%d      |   ",  player_card3);
            printf("\n\t\t\t\t                        |       |                   ");
            printf("\n\t\t\t\t                        |       |                   ");
            printf("\n\t\t\t\t                        |      %d|    ", player_card3);
            printf("\n\t\t\t\t                        +-------+                   ");

            player_total[i] = (player_card1 + player_card2 + player_card3) % 10;
            printf("\n\t\t\t\t  Your total is %d. \n\n\n\t\t\t\t  ", player_total[i]);
            system("pause");
        }
        else
        {
            player_total[i] = (player_card1 + player_card2) % 10;
            printf("\n\t\t\t\t  Your total is %d.\n\n\n\t\t\t\t  ", player_total[i]);
            system("pause");
        }
    }

    for (i = 1; i < max; i++)
    {
        if (player_total[i] < player_total[winner])
        {
            winner = i;
        }
    }

    system("cls");

    printf("\n\t\t\t\t ======================================================================   ");
    printf("\n\t\t\t\t |                         MULTIPLAYER GAME                           |   ");
    printf("\n\t\t\t\t ====================================================================== \n");

    printf("\n\t\t\t\t  The player(s) with the lowest total is/are: \n");

    for (i = 0; i < max; i++)
    {
        if (player_total[i] == player_total[winner])
        {
            printf("\n\t\t\t\t  Player %s with total %d\n", player_name[i], player_total[i]);
        }
    }

    system("cls");

    printf("\n\t\t\t\t ======================================================================   ");
    printf("\n\t\t\t\t |                         MULTIPLAYER GAME                           |   ");
    printf("\n\t\t\t\t ====================================================================== \n");

    for (i = 0; i < max; i++)
    {
        if (player_total[i] == player_total[winner])
        {
            printf("\n\t\t\t\t  Player %s: ", player_name[i]);
            truth_or_dare();
        }
    }

    system("cls");

    printf("\n\t\t\t\t ======================================================================   ");
    printf("\n\t\t\t\t |                         MULTIPLAYER GAME                           |   ");
    printf("\n\t\t\t\t ====================================================================== \n");

    printf("\n\t\t\t\t\t\t      Do you want to play again?");
    printf("\n\t\t\t\t\t\t          [Y]es       [N]o      ");
    choice = getch();
    if(choice == 'y' || choice == 'Y')
    {
        multiplayer();
    }
    else if(choice == 'n' || choice == 'N')
    {
        play();
    }
}


int generate_card()
{
    return rand() % 9 + 1;
}


void getname(char *name)
{
    printf("Name: ");
    scanf("%s", name);
}


int get_player_decision()
{
    char decision;

    printf("\n\t\t\t\t\t\t   Do you want to pick a 3rd card?  ");
    printf("\n\t\t\t\t\t\t          [Y]es       [N]o        \n");
    decision = getch();

    if (decision == 'Y' || decision == 'y')
    {
        return 1;
    }
    return 0;
}


void truth_or_dare()
{
    printf("\n\t\t\t\t\t\t     Do you want truth or dare?\n");
    printf("\n\t\t\t\t\t\t       [T]ruth        [D]are   \n");
    choice = getch();
    choice = toupper(choice);

    switch(choice)
    {
        case 'T': truth(); break;
        case 'D': dare();  break;
        default: truth_or_dare();
    }
}


void truth()
{
    srand(time(NULL));

    char truth[10][100] =
    {
        "What is your biggest secret?",
        "Who was your first crush?",
        "What is the bravest thing you have ever done?",
        "Who are you upset with?",
        "What makes you happy?",
        "Tell us about your crush",
        "Confess any secret you hiding to your friend",
        "Who caught your attention in the group?",
        "Have you ever stolen anything?",
        "What is the worst thing you have ever done?"
    };

    int i = rand() % 10;
    printf("\n\t\t\t\t  Truth: %s\n\n\t\t\t\t  ", truth[i]);
    system("pause");
}


void dare()
{
    srand(time(NULL));

    char dares[10][100] =
    {
        "Sing a song in front of the group",
        "Call your crush and tell them how you feel",
        "Jump into a pool with your clothes on",
        "Dance wet the bed",
        "Tell your best friend you like him/her",
        "Ask your crush out on a date",
        "Do the love scars with your crush",
        "Act like the opposite of your gender for an hour",
        "Do 100 push-ups",
        "Eat a spoonful of hot sauce"
    };

    int i = rand() % 10;
    printf("\n\t\t\t\t  Dare: %s\n\n\t\t\t\t  ", dares[i]);
    system("pause");
}


void instruction()
{
    system("cls");
    printf("\t ===================================================================================================================\n");
    printf("\t |                                                    INSTRUCTION                                                  |\n");
    printf("\t ===================================================================================================================\n");
    printf("\n\t  How to play: \n");
    printf("\n\t  *    The game asks how many players you wanted in the match. \n");
    printf("\n\t  *    Player/s will input their name to remind their player number. \n");
    printf("\n\t  *    The card randomly shuffles and give [2] Cards to each player. \n");
    printf("\n\t  *    Each player will be given to pick the 3rd Card whether they will pick from the deck or not. \n");
    printf("\n\t  *    The result of each player will be calculated automatically. \n");
    printf("\n\t  *    It's possible to tie with another player/dealer. \n");
    printf("\n\t  *    Player who has the lowest number will lose. \n");
    printf("\n\t  *    The loser will then choose between truth or dare. \n");
    printf("\n\t  *    Truth asks a random question while dare command the loser to do something. \n");
    printf("\n\n\t  Reminder: This can only be played in one device. \n\n\n\n\n\n\n\n\n\n");

    system("pause");
}


void option()
{
    do
    {
        system("cls");

        printf("\t ===================================================================================================================\n");
        printf("\t |                                                      OPTION                                                     |\n");
        printf("\t ===================================================================================================================\n");
        printf("\t |                                                                                                                 |\n");
        printf("\t | Customizing Background & Font Color:                                                                            |\n");
        printf("\t |                                                                                                                 |\n");
        printf("\t | Press [1]: Theme Display                                                                                        |\n");
        printf("\t |                                                                                                                 |\n");
        printf("\t | Press [2]: Font Color Display                                                                                   |\n");
        printf("\t |                                                                                                                 |\n");
        printf("\t | Press [3]: Back                                                                                                 |\n");
        printf("\t |                                                                                                                 |\n");
        printf("\t ===================================================================================================================\n");
        choice = getch();


        if(choice == '1')
        {
            printf("\t |                                                                                                                 |\n");
            printf("\t | Theme Display:                                                                                                  |\n");
            printf("\t |                                                                                                                 |\n");
            printf("\t | Press [1]: Light Theme                                                                                          |\n");
            printf("\t |                                                                                                                 |\n");
            printf("\t | Press [2]: Dark Theme                                                                                           |\n");
            printf("\t |                                                                                                                 |\n");
            printf("\t ===================================================================================================================\n\n");
            number = getch();

            switch(number)
            {
                case '1': system("COLOR 70"); break;
                case '2': system("COLOR 07"); break;
            }
        }
        else if(choice == '2')
        {
            printf("\t |                                                                                                                 |\n");
            printf("\t | Font Color Display:                                                                                             |\n");
            printf("\t |                                                                                                                 |\n");
            printf("\t | Press [1]: Red                                                                                                  |\n");
            printf("\t |                                                                                                                 |\n");
            printf("\t | Press [2]: Green                                                                                                |\n");
            printf("\t |                                                                                                                 |\n");
            printf("\t | Press [3]: Yellow                                                                                               |\n");
            printf("\t |                                                                                                                 |\n");
            printf("\t | Press [4]: White                                                                                                |\n");
            printf("\t |                                                                                                                 |\n");
            printf("\t ===================================================================================================================\n\n");
            number = getch();

            switch(number)
            {
               case '1': system("COLOR 0C"); break;
               case '2': system("COLOR 0A"); break;
               case '3': system("COLOR 0E"); break;
               case '4': system("COLOR 0F"); break;
            }
        }
        else if(choice == '3')
        {
            menu();
        }
    }
    while(choice != 4);
}


void quit()
{
    system("cls");

    printf("\n\n\n\n\n\n\t\t\t\t ===================================================================== \n");
    printf("\t\t\t\t |                           WARNING!                                |   ");
    printf("\n\t\t\t\t ===================================================================== \n");
    printf("\t\t\t\t |                                                                   |   ");
    printf("\n\t\t\t\t |                Are you sure you want to leave?                    | \n");
    printf("\t\t\t\t |                                                                   |   ");
    printf("\n\t\t\t\t |                       [Y]es      [N]o                             | \n");
    printf("\t\t\t\t |                                                                   |   ");
    printf("\n\t\t\t\t ===================================================================== \n");

    choice = getch();
    if (choice == 'y' || choice == 'Y')
    {
        printf("\n\n\t\t\t\t\t\t   Thank you for playing Lucky 9!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        exit(0);
    }
    else if (choice == 'n' || choice == 'N')
    {
        menu();
    }
    else
    {
        quit();
    }
}
