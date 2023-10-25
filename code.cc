#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<dos.h>
#include<conio.h>
#define ENTER 13
#define TAB 9
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

int  DIARY_PASSWORD();
void EDID_DIARY_PASSWORD();
void addrecord();
void viewrecord();
void editrecord();
void DIAGRAM();
void GAME();

FILE* USERNAME, * PASS, * fptr;
int C = 1, n, i, m = 5, r = 0, z = 0;

struct record
{
    char time[6];
    char name[30];
    char note[500];
};

int main()
{
    int ch;
    system("COLOR 1C");
    DIARY_PASSWORD();
levelA:

    DIAGRAM();

    printf("\n\t\t PRESS (1). TO ADD YOUR RECORD: ");
    printf("\n\t\t PRESS (2). TO VIEW YOUR RECORD: ");
    printf("\n\t\t PRESS (3). TO EDIT YOUR RECORD: ");
    printf("\n\t\t PRESS (4). TO PLAY GAME: ");
    printf("\n\t\t PRESS (5). TO EDIT YOU DIARY'S PASSWORD: ");
    printf("\n\t\t PRESS (6). TO EXIT FROM HERE: \n ");

levelb:
    scanf("%d", &ch);
    printf("\n\n\t\t*=========*==========*==========*\n");

    switch (ch)
    {
    case 1:
        addrecord();
        if (m == 5)
        {
            goto levelA;
        }
        break;
    case 2:
        viewrecord();
        if (r == 1)
        {
            goto levelA;
        }
        break;
    case 3:

        editrecord();
        if (C == 1)
        {
            goto levelA;
        }
        break;
    case 4:
        GAME();
        if (C == 1)
        {
            goto levelA;
        }
    case 5:
        EDID_DIARY_PASSWORD();
        break;
    case 6:
        printf("\n\n\t\t******THANK YOU FOR USING OUR PROGRAM ******");

        printf("\n\nCoded by:\n");
        printf("\t\t|------------------------------------------------------------|");
        printf("\n\t\t\t        Aleema          Dahim         Sajjad\n");
        printf("\n\t\t          ヾ(⌐■_■)ノ       ( •̀ᴗ•́ )و ̑̑      ᕦ(ò_óˇ)ᕤ  \n");
        printf("\t\t|------------------------------------------------------------|");
        getch();
        exit(0);
    default:
        printf("\n\n\t WRONG ENTRYP:\n\t. TRY AGAIN");
        goto levelb;
    }

    printf("\n");
    system("pause");
    return 0;
}


int  DIARY_PASSWORD()   // ONLY FOR DIARY AT START
{
    system("cls");
    system("COLOR D");
    printf("\n");
    USERNAME = fopen("USERNAME.txt", "r");
    PASS = fopen("Password.txt", "r");
    char password[10], ch, USER[15];
    char PAK1[15], Pak[10];
    int i = 0;
    printf("\n\tUSERNAME::\t  ");
    scanf("%s", &USER);
    printf("\n\tENTER PASSWORD::\t ");
    while (1)
    {
        ch = getch();
        if (ch == 13)   // ASCII CODE OF ENTER
        {
            password[i] = '\0';
            break;
        }
        else if (ch == 8)   // ASCII CODE OF BACKSPACE
        {
            if (i > 0)
            {
                putch('\b');
                putch(NULL);
                putch('\b');
                i--;
                continue;
            }
        }
        else if (ch == 32) // ASCII CODE OF SPACE
        {
            continue;
        }
        password[i++] = ch;
        putch('*');
    }
    password[i] = '\0';
    fgets(PAK1, 15, USERNAME);
    fgets(Pak, 10, PASS);
    fclose(USERNAME);
    fclose(PASS);
    if (strcmp(password, Pak) == 0 && strcmp(USER, PAK1) == 0)
    {
        printf("\n\n\tACCESS GRANTED...\n");
        printf("\n\t:: TO MOVE FORWARD PRESS ANY KEY \n");
    }
    else
    {
        printf("\n\n\tWRONG USERNAME OR PASSWORD..\tACCESS DENIED....:");
        exit(0);
    }
    getch();
    return 0;
}

void EDID_DIARY_PASSWORD()    // TO EDIT DIARY'S PASSWORD
{
    system("cls");
    system("\n");
    system("color 0B");
    char USERNAME1[15], PASSWORD[10];
    USERNAME = fopen("USERNAME.txt", "w");
    PASS = fopen("Password.txt", "w");
    printf("\n\n\t\t ::WELLCOME TO PASSWORD EDITING MENU:: \n");

    printf("\n\t\t NEW USER NAME:\t ");
    scanf("%s", &USERNAME1);

    printf("\n\t\t PASSWORD:\t ");
    scanf("%s", &PASSWORD);

    fprintf(USERNAME, "%s", USERNAME1);
    fprintf(PASS, "%s", PASSWORD);

    fclose(USERNAME);
    fclose(PASS);
    printf("\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...");
    int b;
    printf("\n\t If U WANNA GET BACK TO UR DIARY. THEN,\t PRESS (1)");
    scanf("%d", &b);
    switch (b)
    {
    case 1:
        main();
        break;
    default:
        exit(0);
        break;
    }
}

void DIAGRAM()
{
    system("cls");
    printf("\n");
    system("color 2");
    printf("\n\t  __________________________________________________________________________");
    printf("\n\t |                                                                            |");
    printf("\n\t|                        PASSWORD PROTECTED PERSONAL DIARY                      |");
    printf("\n\t |                                                                            |");
    printf("\n\t  __________________________________________________________________________");


    printf("\n\n\n\t\t\t  `/\\ \n");
    printf("\t\t\t `=\\/\\ __...--~~~~~-._   _.-~~~~~--...__\n");
    printf("\t\t\t  `=\\/\\             \\ /                \\\n");
    printf("\t\t\t   `=\\/                V                 \\\n");
    printf("\t\t\t   //_\\___--~~~~~~-._  |  _.-~~~~~~--...__\\\n");
    printf("\t\t\t  // ____..----~~~~._\\ | /_.~~~~----.....__\\\n");
    printf("\t\t\t ===| INK |===========\\|//====================\n");
    printf("\t\t\t_____\\___/________dwb`---`____________________\n");

}

void addrecord()
{
    system("color B");
    system("cls");
    FILE* fp;
    char another, time[10];
    struct record e;
    char filename[15];
    int choice;
    printf("\n\n\t\t_______________________________________________________________________\n");
    printf("\n\t                                                                             \n");
    printf("\t                 WELCOME TO THE ADD MENU                          \n");
    printf("\t                                                              \n");
    printf("\n\t\t________________________________________________________________________\n\n");

    printf("\t\t\t      |\\      _,,,---,,_\n");
    printf("\t\t\tZZZzz /,`.-'`'    -.  ;-;;,_\n");
    printf("\t\t\t     |,4-  ) )-,_. ,\\ (  `'-'\n");
    printf("\t\t\t    '---''(_/--'  `-'\\_)  \n");

    printf("\n\n\tENTER DATE OF YOUR RECORD:[yyyy-mm-dd]:");
    fflush(stdin);
    getchar();
    gets(filename);
    fp = fopen(filename, "ab+");
    if (fp == NULL)
    {
        fp = fopen(filename, "wb+");
        if (fp == NULL)
        {
            printf("\nSYSTEM ERROR...");
            printf("\nPRESS ANY KEY TO EXIT");
            getch();
            return;
        }
    }
leveD:
    {
        choice = 0;
        fflush(stdin);
        printf("\n\tENTER TIME:[hh:mm]:");
        scanf("%s", time);
        getchar();
        rewind(fp);
        while (fread(&e, sizeof(e), 1, fp) == 1)
        {
            if (strcmp(e.time, time) == 0)
            {
                printf("\n\tTHE RECORD ALREADY EXISTS.\n");
                choice = 1;
            }
        }
        if (choice == 0)
        {
            strcpy(e.time, time);
            printf("\tENTER YOUR RECORD'S NAME:");
            fflush(stdin);
            gets(e.name);
            fflush(stdin);
            printf("\n\tENTER YOUR RECORD:");
            gets(e.note);
            fwrite(&e, sizeof(e), 1, fp);
            printf("\nYour record is added...\n");
        }
        printf("\n\tDo you want add another record?...(Y/N) ");
        fflush(stdin);
        scanf("%c", &another);
        if (another == 'Y' || another == 'y')
        {
            goto leveD;
        }
    }
    fclose(fp);
    int n, m;
    printf("\n\n\t IF U WANNA GO BACK TO UR DIARY PRESS 1\n\t Otherwise exit");
    scanf("%d", &n);
    if (n == 1)
    {
        m = 5;
    }
    else
    {
        exit(0);
    }

}

void viewrecord()   // TO VIEW RECORD
{
    FILE* fpte;
    system("cls");
    printf("\n");
    struct record e;
    char time[6], choice, filename[15];
    int ch;
    printf("\n\n\t\t\t_________________________________________________________\n");
    printf("\t\t\t*                      HERE IS THE VIEWING MENU                *");
    printf("\n\t\t\t___________________________________________________________\n\n");
    printf("\t\t\t                 .--.               .---.      .----.\n");
    printf("\t\t\t             .---|--|   .-.     .---. A |  .---.    |  .---.\n");
    printf("\t\t\t          |##|NT2|no|===| |~~|##| C |---|  |_|~|CATS|  |___|-.\n");
    printf("\t\t\t          |  |   |wt|   |_|__|  | I |___|  | | |    |  |___| |\n");
    printf("\t\t\t          |~~|===|--|===|~|~~|##|~~~|---|::|=|~|----|==|---|=|\n");
    printf("\t\t\t          ^--^---'--^---^-^--^--^---'--^---^-^-^-==-^--^---^-'\n");
    choice = 0;
    if (choice != 0)
    {
        return;
    }
    do
    {
        printf("\n\tEnter the date of the record to be viewed:[yyyy-mm-dd]:");
        fflush(stdin);
        getchar();
        gets(filename);
        fpte = fopen(filename, "r+");
        if (fpte == NULL)
        {
            puts("\nOops. There is no record for that date...\n");
            printf("\nPress any key to continue...");
            getch();
            return;
        }
        system("cls");
        printf("\n\t\t___________________________________________________________");
        printf("\n\t\t\tRecord of the mentioned date");
        printf("\n\t\t___________________________________________________________\n\n");
        printf("\n\t\tPress any key to continue\n\n");
        getch();
        printf("\n");
        ch = 1;
        switch (ch)
        {
        case 1:
            printf("\n");
            printf("\nThe record for day %s is:", filename);
            while (fread(&e, sizeof(e), 1, fpte) == 1)
            {
                printf("\n");
                printf("\nTitle: %s", e.name);
                printf("\nEntry: %s", e.note);
                printf("\n\n");
                printf("\nPress any key to continue...");
                getch();
            }
            break;
        default:
            printf("\nYou typed something new...\n");
            break;
        }
        printf("\n\nWould you like to continue viewing records?...(Y/N):");
        printf("\n\n Press 'Y' for yes and 'N' for no:\t");
        fflush(stdin);
        scanf("%c", &choice);
    } while (choice == 'Y' || choice == 'y');
    fclose(fpte);

    printf("\n\n Are you looking for something else?\n Press 1 to go to main menu:\t");

    scanf("%d", &z);
    if (z == 1) {
        r = 1;
    }

}

void editrecord()  // To edit password
{
    system("cls");
    system("color 3A");
    FILE* fpte;
    struct record COSMAS;
    char time[6], choice, filename[14];
    int num, count = 0;
    printf("\n\n\t\t*******************************\n");
    printf("\t\t* WELCOME TO THE EDITING MENU *");
    printf("\n\t\t*******************************\n\n\n\n");
    printf("\t\t\t        __..._   _...__\n");
    printf("\t\t\t  _..-'      `Y`      '-._\n");
    printf("\t\t\t  \\ Once upon |            /\n");
    printf("\t\t\t  \\\\  a time..|           //\n");
    printf("\t\t\t  \\\\\\         |          ///\n");
    printf("\t\t\t  \\\\\\ _..---. |.---..   ///\n");
    printf("\t\t\t    \\\\`_..---.Y.---.._`//\n");
    printf("\t\t\t     '`               `'\n");

    do
    {
        printf("\n\tENTER THE DATE OF RECORD TO BE EDITED:[yyyy-mm-dd]:");
        fflush(stdin);
        gets(filename);
        printf("\n\tENTER TIME:[hh:mm]:");
        gets(time);
        fpte = fopen(filename, "rb+");
        if (fpte == NULL)
        {
            printf("\nRECORD DOES NOT EXISTS:");
            printf("\nPRESS ANY KEY TO GO BACK");
            getch();
            return;
        }
        while (fread(&COSMAS, sizeof(COSMAS), 1, fpte) == 1)
        {
            if (strcmp(COSMAS.time, time) == 0)
            {
                printf("\nYOUR OLD RECORD WAS AS:");
                printf("\nTIME: %s", COSMAS.time);
                printf("\nNOTE: %s", COSMAS.note);
                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");
                printf("\n1.TIME.");
                printf("\n2.NOTE.");
                printf("\n3.WHOLE RECORD.");
                printf("\n4.GO BACK TO MAIN MENU.");
                do
                {
                    printf("\n\tENTER YOUR CHOICE:");
                    fflush(stdin);
                    scanf("%d", &num);
                    fflush(stdin);
                    switch (num)
                    {
                    case 1:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nNEW TIME:[hh:mm]:");
                        gets(COSMAS.time);
                        break;
                    case 2:
                        printf("ENTER THE NEW DATA:");
                        printf("\nNOTE:");
                        gets(COSMAS.note);
                        break;
                    case 3:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nNEW TIME:[hh:mm]:");
                        gets(COSMAS.time);
                        printf("\nNOTE:");
                        gets(COSMAS.note);
                        break;
                    case 7:
                        printf("\nPRESS ANY KEY TO GO BACK...\n");
                        //   goto main();
                        break;
                    default:
                        printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");
                        break;
                    }
                } while (num < 1 || num>8);
                fseek(fpte, sizeof(COSMAS), SEEK_CUR);
                fwrite(&COSMAS, sizeof(COSMAS), 1, fpte);
                fseek(fpte, sizeof(COSMAS), SEEK_CUR);
                fread(&COSMAS, sizeof(COSMAS), 1, fpte);
                choice = 5;
                break;
            }
        }
        if (choice == 5)
        {
            system("cls");
            printf("\n\t\tEDITING COMPLETED...\n");
            printf("--------------------\n");
            printf("THE NEW RECORD IS:\n");
            printf("--------------------\n");
            printf("\nTIME: %s", COSMAS.time);
            printf("\nNOTE: %s", COSMAS.note);
            fclose(fpte);
            count++;
        }
        else
        {
            printf("\nTHE RECORD DOES NOT EXIST::\n");
            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
            scanf("%c", &choice);
        }
    } while (choice == 'Y' || choice == 'y');
    fclose(fpte);

    printf("\tPRESS 1 TO EXIT EDITING MENU.");
    scanf("%d", &i);
    if (i == 1)
    {
        C = 1;
    }

}

void GAME()
{
    system("cls");
    system("color 0B");
    int num, guess;
    srand(time(0));

    printf("\n\n\t\t\t ::::::::::   WELLCOME TO THE GAME :::::::: \n\n\t\t");
    printf("\t\t\t\t\t| _______ |\n");
    printf("\t\t\t\t\t||,-----.||\n");
    printf("\t\t\t\t\t|||     |||\n");
    printf("\t\t\t\t\t|||_____|||\n");
    printf("\t\t\t\t\t|`-------'|\n");
    printf("\t\t\t\t\t| +     O |\n");
    printf("\t\t\t\t\t|      O  |\n");
    printf("\t\t\t\t\t| / /  ##,'\n");
    printf("\t\t\t\t\t`---------'\n");
REPLAYGAME:
    system("cls");
    int score = 200;
    num = rand() % 100 + 1;
    printf("\n\t\t\t :Guess a number between 1 to 100: (ง'̀-'́)ง  ");
    printf("\nThe max score is 200 and you will be charged 5 points for each wrong choice:\n");
    printf("Enter your guess:\n");
AGAIN:
    scanf("%d", &guess);
    if (guess > num)
    {
        printf("\nThe number is lower!\n");
        printf("Guess again!\n");
        score -= 5;
        goto AGAIN;
    }
    else if (guess < num)
    {
        printf("\nThe number is higher!\n");
        printf("Guess again!\n");
        score -= 5;
        goto AGAIN;
    }
    else
    {
        printf("\n  You have guessed correct  ＼(＾O＾)／ \n");

        printf("Your score is %d\n", score);
    }
    if (score == 200)
    {
        printf("Genius! Your brain functions like that of a computer.  ヽ( ͝ ° ͜ʖ͡° )ﾉ \n");
    }
    else if (score < 200 && score>150)
    {
        printf("You've got some sherlock genes I think.  (⌐■_■) \n");
    }
    else if (score < 150 && score>100)
    {
        printf("Hmmm...Avergae.\n");
    }
    else if (score < 100 && score>0)
    {
        printf("Ever thought of using your brain?  ಠ_ಠ \n");
    }
    else if (score <= 0)
    {
        printf("You are a lost cause....huh... (゜￢゜) \n");
    }

    int a;
    printf("\n\n\t Well, if you wanna play again (ง •̀_•́)ง press \t 1:");
    printf("\n\t If you want to go back to your journal then, \n \t enter 2:");
    scanf("%d", &a);
    if (a == 1)
    {
        goto     REPLAYGAME;
    }
    else if (a == 2)
    {
        C = 1;
    }
    else
    {
        exit(0);
    }
}
// THE END
