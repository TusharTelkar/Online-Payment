#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Bank
{
    char u_pass[25];
    char name[25];
    char ph_no[20];
    int Deposit;
    char Acc[12];
} bank;
bank crt, check, check1, tra1, dep;
void acc();
void view();
void deposit();
void transact();
void balance();
void acc()
{
    int z;

    char IFSC[9];
    FILE *a;
    system("cls");
aa:
    a = fopen("record.txt", "a+");
    printf("\n\n\n");
    printf("=================================== Create Bank Account ==================================\n\n");
    printf("\n\t\t\tEnter the last 3 digit account number:");
    scanf("%s", check.Acc);
    if (strlen(check.Acc) == 3)
    {
        char account[13] = "10000000";
        // account = strcat(IFSC, check.Acc);
        strcat(account, check.Acc);
        // printf("%s", account);
        z = strlen(account);
        while (fscanf(a, "%s %s %s %s %d\n", &crt.Acc, &crt.u_pass, &crt.name, &crt.ph_no, &crt.Deposit) != EOF)
        {
            if (z == 11)
            {
                if (strcmp(account, crt.Acc) == 0)
                {
                    printf("\n==================================================================================\n");
                    printf("\t\t\tAccount no. already in use!\n");
                    printf("\t\t\tPress any key...\n");
                    printf("\n==================================================================================\n");
                    getch();
                    fclose(a);
                    goto aa;
                }
            }
            else
            {
                printf("\n\n\t\t\tEnter valid Account number");
                goto aa;
            }
        }
        // crt.Acc = check.Acc;
        strcpy(crt.Acc, account);
        printf("\n\n\t\t\tUPI : ");
        scanf("%s", crt.u_pass);
        printf("\n\t\t\tName :");
        scanf("%s", crt.name);
        printf("\n\t\t\tPhone number : ");
        scanf("%s", crt.ph_no);
    cc:
        printf("\n\t\t\tAmt to Deposit : ");
        scanf("%d", &crt.Deposit);
        if (crt.Deposit >= 500 && crt.Deposit <= 25000)
        {
            fprintf(a, "%s %s %s %s %d\n", crt.Acc, crt.u_pass, crt.name, crt.ph_no, crt.Deposit);
        }
        else
        {
            printf("\n==================================================================================\n");
            printf("\t\t\tInvalid Amount\n");
            printf("\n\t\t\tEnter Deposit Amount with in range Rs:500 to Rs:25000");
            printf("\n\t\t\tPress any key...\n");
            printf("\n==================================================================================\n");
            getch();
            goto cc;
        }

        printf("\n================================== Account Created ==================================\n");
        fclose(a);
    }
    else
    {
        printf("\n\n\t\t\t\tInvalid input");
        getch();
        fclose(a);
        goto aa;
    }
}
void view()
{
    FILE *a;
    int test = 0;
    int b = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
aa:
    a = fopen("record.txt", "r");
    system("cls");
    printf("\n\n\n");
    printf("\n================================== My Account ==================================\n");
    printf("\n\t\t\tEnter the account number : ");
    scanf("%s", check.Acc);
    printf("\n\t\t\tEnter the UPI : ");
    int i = 0;
    while (i < 10)
    {
        pword[i] = getch();
        c = pword[i];
        if (c == 13)
            break;
        else
            printf("*");
        i++;
    }
    pword[i] = '\0';
    while (fscanf(a, "%s %s %s %s %d\n", &crt.Acc, &crt.u_pass, &crt.name, &crt.ph_no, &crt.Deposit) != EOF)
    {
        if (strcmp(check.Acc, crt.Acc) == 0 && strcmp(pword, crt.u_pass) == 0)
        {
            test = 1;
            printf("\n\n-----------------------------------------------------------------------------------");
            printf("\n\t\t\t-->Name : %s", crt.name);
            printf("\n\t\t\t-->Phone number : %s", crt.ph_no);
            printf("\n\t\t\t-->Total Balance : $%d", crt.Deposit);
            printf("\n-----------------------------------------------------------------------------------");
            printf("\n\t\t\tPress any key...\n");
            break;
        }
    }
    if (test != 1)
    {
        printf("\n\n\t\t\tInvalid Account Number");
        printf("\n\n\t\t\tPress any key...\n");
        getch();
        goto aa;
    }
    fclose(a);
}
void deposit()
{
    FILE *a, *b;
    int test = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    system("cls");
aa:
    a = fopen("record.txt", "r");
    b = fopen("new_record.txt", "w");
    system("cls");
    printf("\n\n\n");
    printf("\n================================== DEPOSIT ==================================\n");
    printf("\n\t\t\tEnter the account number:");
    scanf("%s", check.Acc);
    printf("\n\t\t\tEnter the UPI : ");
    int i = 0;
    while (i < 10)
    {
        pword[i] = getch();
        c = pword[i];
        if (c == 13)
            break;
        else
            printf("*");
        i++;
    }
    pword[i] = '\0';
    while (fscanf(a, "%s %s %s %s %d\n", &crt.Acc, &crt.u_pass, &crt.name, &crt.ph_no, &crt.Deposit) != EOF)
    {
        if (strcmp(check.Acc, crt.Acc) == 0 && strcmp(pword, crt.u_pass) == 0)
        {
            test = 1;
            printf("\n\n\t\t\tEnter amount to Deposit : ");
            scanf("%d", &dep.Deposit);
            if (dep.Deposit >= 100 && dep.Deposit <= 25000)
            {
                crt.Deposit += dep.Deposit;
                printf("\n\n\t\t\tYour Amount is successfully deposited ");
                printf("\n\n\t\t\tPress any key to go to MAIN MENU..... ");
                fprintf(b, "%s %s %s %s %d\n", crt.Acc, crt.u_pass, crt.name, crt.ph_no, crt.Deposit);
            }
            else
            {
                printf("\n\t\t\tEnter Deposit amount with in range Rs:100 to Rs:25000");
                printf("\n\t\t\tTransaction failed");
                getch();
                fclose(a);
                fclose(b);
                goto aa;
            }
        }
        else
        {
            fprintf(b, "%s %s %s %s %d\n", crt.Acc, crt.u_pass, crt.name, crt.ph_no, crt.Deposit);
        }
    }
    if (test != 1)
    {
        printf("\n\n\t\t\tInvalid Account Number");
        printf("\n\n\t\t\tPress any key to go to MAIN MENU..... ");
        getch();
        fclose(a);
        fclose(b);
        goto aa;
    }
    fclose(a);
    fclose(b);
    remove("record.txt");
    rename("new_record.txt", "record.txt");
}
void transact()
{
    FILE *a, *b, *c, *d;
    int test = 0, test2 = 0, test3 = 0;
    long int amt;
    char ch;
    char uname[10], e = ' ';
    char pword[10], code[10];

aa:
    a = fopen("record.txt", "r");
    b = fopen("new_record.txt", "w");
    system("cls");
    printf("\n\n\n");
    printf("\n================================== My Account ==================================\n");
    printf("\n\t\t\tEnter the Sender account number:");
    scanf("%s", check.Acc);
    printf("\n\n\t\t\tEnter the UPI : ");
    int i = 0;
    while (i < 10)
    {
        pword[i] = getch();
        e = pword[i];
        if (e == 13)
            break;
        else
            printf("*");
        i++;
    }
    pword[i] = '\0';
    printf("\n\n\n\t\t\tEnter amount to transact : ");
    scanf("%ld", &amt);
    if (amt >= 1 && amt <= 25000)
    {
        while (fscanf(a, "%s %s %s %s %d\n", &crt.Acc, &crt.u_pass, &crt.name, &crt.ph_no, &crt.Deposit) != EOF)
        {
            if (strcmp(check.Acc, crt.Acc) == 0 && strcmp(pword, crt.u_pass) == 0)
            {
                test = 1;
                if (amt > crt.Deposit)
                {
                    test3 = 1;
                    printf("\n\n\t\t\tBalance Amt : %d\n", crt.Deposit);
                    printf("\n\n\t\t--------------------------------------------------------------");
                    printf("\n\n\t\t\tInsufficient Balance?\n");
                    printf("\n\n\t\t\tTransaction Failed");
                    printf("\n\n\t\t--------------------------------------------------------------");
                    printf("\n\n\t\t\tPress any key...... ");
                    fprintf(b, "%s %s %s %s %d\n", crt.Acc, crt.u_pass, crt.name, crt.ph_no, crt.Deposit);
                    getch();
                    //fclose(a);
                    //fclose(b);
                    //break;
                }
                else
                {
                    crt.Deposit -= amt;
                    fprintf(b, "%s %s %s %s %d\n", crt.Acc, crt.u_pass, crt.name, crt.ph_no, crt.Deposit);
                }
            }
            else
            {
                fprintf(b, "%s %s %s %s %d\n", crt.Acc, crt.u_pass, crt.name, crt.ph_no, crt.Deposit);
            }
        }
    }
    else
    {
        printf("\n\t\t\tEnter Amount with in range Rs:1 to Rs:25000");
        printf("\n\t\t\tTransaction failed");
        getch();
        fclose(a);
        fclose(b);
        goto aa;
    }
    if (test != 1)
    {
        printf("\n\n\t\t\tInvalid Account Number");
        printf("\n\n\t\t\tPress any key...... ");
        getch();
        fclose(a);
        fclose(b);
        goto aa;
    }
    fclose(a);
    fclose(b);
    remove("record.txt");
    rename("new_record.txt", "record.txt");
    if (test3 != 1)
    {
    bb:
        c = fopen("record.txt", "r");
        d = fopen("new_record.txt", "w");
        printf("\n\n\t\t\tEnter the Reciver account number:");
        scanf("%s", check1.Acc);
        while (fscanf(c, "%s %s %s %s %d\n", &tra1.Acc, &tra1.u_pass, &tra1.name, &tra1.ph_no, &tra1.Deposit) != EOF)
        {
            if (strcmp(check1.Acc, tra1.Acc) == 0)
            {
                test2 = 1;
                tra1.Deposit += amt;
                fprintf(d, "%s %s %s %s %d\n", tra1.Acc, tra1.u_pass, tra1.name, tra1.ph_no, tra1.Deposit);
            }
            else
            {
                fprintf(d, "%s %s %s %s %d\n", tra1.Acc, tra1.u_pass, tra1.name, tra1.ph_no, tra1.Deposit);
            }
        }
        if (test2 != 1)
        {
            printf("\n\n\t\t\tInvalid Account Number");
            printf("\n\n\t\t\tPress any key...... ");
            getch();
            fclose(c);
            fclose(d);
            goto bb;
        }
        printf("\n\n\t\t\tAmount successufully Transfered");
        printf("\n\n\t\t\tPress any key...... ");
        fclose(c);
        fclose(d);
        remove("record.txt");
        rename("new_record.txt", "record.txt");
    }
}

int main()
{
    int num, i;
    do
    {
        //system("cls");
        printf("\n\n\n");
        printf("====================================== BANK MANAGEMENT SYSTEM ======================================\n\n\n");
        printf("\t\t\t\t\t[1] : Creating Account\n");
        printf("\n");
        printf("\t\t\t\t\t[2] : Deposit\n");
        printf("\n");
        printf("\t\t\t\t\t[3] : view Balance\n");
        printf("\n");
        printf("\t\t\t\t\t[4] : Transaction\n");
        printf("\n");
        printf("\t\t\t\t\t[5] : Exit\n\n");
        printf("===============================================================================================================\n\n");
        printf("\t\t\tEnter Your Choice:: ");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            acc();
            break;
        case 2:
            deposit();
            break;
        case 3:
            view();
            break;
        case 4:
            transact();
            break;
        case 5:
            exit(0);
        }
        getch();
    } while (num != 5);
    return 0;
}
