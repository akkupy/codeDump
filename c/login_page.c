#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

char set[8];
int c = 0, d = 0, e = 0;

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int suggest()
{
    srand(time(0));
    set[8];
    char i;
    for (i = 0; i < 8; i++)
    {
        if (i != 5)
            set[i] = 33 + (rand() % (126 - 33));
        else
            set[i] = 48 + rand() % 10;
    }
    for (i = 0; i < 8; i++)
    {
        printf("%c", set[i]);
    }
    Sleep(10000);
    return 0;
}

int mannual()
{
    set[8];
    for (int i = 0; i < 8; i++)
        set[i] = getch();
}

int check_special()
{

    for (int i = 0; i < 8; i++)
    {
        for (int j = 33; j <= 47; j++)
        {
            if (((char)set[i]) == j)
                c++;
        }
        for (int j = 58; j <= 64; j++)
        {
            if (((char)set[i]) == j)
                c++;
        }
        for (int j = 91; j <= 94; j++)
        {
            if (((char)set[i]) == j)
                c++;
        }
        for (int j = 123; j <= 125; j++)
        {
            if (((char)set[i]) == j)
                c++;
        }
    }
    return c;
}

int check_number()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 48; j <= 57; j++)
        {
            if (((char)set[i]) == j)
                d++;
        }
    }

    return d;
}

int check_alphabets()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            if (((char)set[i]) == j)
                e++;
        }
        for (int j = 97; j <= 122; j++)
        {
            if (((char)set[i]) == j)
                e++;
        }
    }
    return e;
}

int main()
{
start:
    system("cls");
    srand(time(0));
    int flag = 0, ch;
    printf("WELCOME\n");
    printf("Please set your password before logging in to the portal \nThe password must contain 8 alphanumeric(alphabets+numbers+special characters) characters\n");
    gotoxy(50, 10);
    printf("Set your password\n");
    printf("1.Use suggested strong password\n2.Enter manually \n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        suggest();
        break;
    case 2:
        mannual();
        break;
    default:
        printf("Wrong Input\n\n");
        break;
    }

    if (ch != 1 && ch != 2)
    {
        exit(0);
    }

    int p = check_special();
    int q = check_number();
    int r = check_alphabets();

    if (p > 0 && q > 0 && r > 0)
    {
        system("cls");
        gotoxy(50, 10);
        printf("Password verified\n");
        Sleep(1000);
    }

    else
    {
        system("cls");

        if (p == 0)
        {
            gotoxy(20, 10);
            printf("Your password doesnot contain any special characters please re-enter");
        }

        if (q == 0)
        {
            gotoxy(20, 11);
            printf("Your password doesnot contain any numbers please re-enter");
        }

        if (r == 0)
        {
            gotoxy(20, 12);
            printf("Your password doesnot contain any alphabets please re-enter");
        }

        Sleep(3000);
        system("cls");
        goto start;
    }

    FILE *filePtr;
    filePtr = fopen("password.txt", "w");
    fputs(set, filePtr);
    fclose(filePtr);

    printf("\n You will be automatically generated to login portal after few secs ");
    int i = 1 + rand() % 9;
    Sleep(1000);

    for (i; i >= 0; i--)
    {
        system("cls");
        printf("%d", i % 60);
        Sleep(1000);
    }

    printf("\n Wait generating the portal");
    Sleep(500);

    system("cls");
    gotoxy(10, 10);
    printf("Enter your password \n");
    int get[8];
    for (int i = 0; i < 8; i++)
    {
        get[i] = getche();
        Sleep(1);
        printf("\b*");
    }

    for (int i = 0; i < 8; i++)
    {
        if (set[i] != get[i])
            flag++;
    }

    if (flag == 0)
    {
        system("cls");
        gotoxy(10, 10);
        printf("***************Password is correct***************\n");
        Sleep(1000);
        system("cls");
        gotoxy(30, 10);
        printf("LOGIN SUCCESSFUL\n\n");
    }
    else
    {
        system("cls");
        gotoxy(10, 10);
        printf("***************Password is incorrect***************\n");
        Sleep(1000);
        system("cls");
        gotoxy(10, 10);
        printf("You will be redirected to the START");
        Sleep(1000);
        system("cls");
        goto start;
    }

    return 0;
}