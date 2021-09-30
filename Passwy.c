#include "passwy.h"
int main()
{
    windows_size(100,30);

    printf("\nWelcome to Passwy\n*************************\n");

    logo();
    system("pause");

    FILE *fp;
    int key;
    long long int cryptbase1 = 44546566853241, cryptbase2 = 54865413264587, inckey;
    bool check = false;
    int turns = 3;
    do
    {
        check = false;

        //First time run
        fp = fopen("data.txt", "r");
        if (fp == NULL)
        {
            fclose(fp);
            do
            {
                system("cls");
                logo();
                printf("\nCreate 4 digit the key: \n");
                key = int_input();
                if (!(key >= 1000 && key <= 9999))
                {
                    printf("\nWrong ping entered\n");
                    system("pause");
                }
            } while (!(key >= 1000 && key <= 9999));
            system("cls");
            fp = fopen("data.txt", "w");
            inckey = (key + cryptbase1) ^ cryptbase2;
            size_t buffsize = sizeof(long long int) * 8;
            unsigned char *buffer = (unsigned char *)malloc(buffsize * sizeof(unsigned char));
            sprintf(buffer, "%lld`", inckey);
            fputs(buffer, fp);
            fclose(fp);
            fp = fopen("settings.txt", "w");
            fputs(buffer, fp);
            fclose(fp);
            free(buffer);
            key_logo();
            printf("\nKey is saved and file was generated pls dont delete ,rename ,edit or move the file\n");
            system("pause");
        }
        else
        {
            printf("\nEnter the key: \n");
            key = int_input();
            system("cls");
            size_t buffsize = sizeof(long long int) * 8;
            unsigned char *buffer = (unsigned char *)malloc(buffsize * sizeof(unsigned char));
            int count = 0;
            copy_file("settings.txt", "data.txt");
            fp = fopen("data.txt", "r");
            while ((buffer[count] = fgetc(fp)) != '`')
                count++;
            sscanf(buffer, "%lld", &inckey);
            free(buffer);
            fclose(fp);
            inckey = (inckey ^ cryptbase2) - cryptbase1;
            if (inckey != key)
            {
                printf("\nWrong key entered.\n%d turn left\n**Note:- Pls dont exit this application from cross ,To exit it forcefully press ctrl + c to exit it**\n\n", turns);
                turns--;
                check = true;
            }
            if (turns < 0)
                exit(0);
        }
    } while (check);
    //choice
    key /= 127;
    do
    {
        check = true;
        int ch;
        system("cls");
        passwy_logo();
        printf("\nChoose the option\n1.Add password\n2.Show password\n3.Backup\n4.Exit\n");
        ch = int_input();
        switch (ch)
        {
        case 1:
        {
            system("cls");
            fp = fopen("data.txt", "a+");
            int ch;
            srand(time(0));
            if (fp == NULL)
            {
                printf("\nError in opening the file\n");
                return -1;
            }
            unsigned char title[12];
            size_t buffsize = 100;
            unsigned char *buffer = (unsigned char *)malloc(buffsize * sizeof(unsigned char));

            key_logo();

            printf("\nEnter the website : ");
            fgets(buffer, buffsize, stdin);
            tolower_str(buffer);
            strcpy(title, "Website: ");
            encrpt(title, key);
            fputs(title, fp);
            encrpt(buffer, key);
            fputs(buffer, fp);

            printf("\nEnter the E-mail ID : ");
            fgets(buffer, buffsize, stdin);
            strcpy(title, "E-Mail: ");
            encrpt(title, key);
            fputs(title, fp);
            encrpt(buffer, key);
            fputs(buffer, fp);

            printf("\nEnter the username : ");
            fgets(buffer, buffsize, stdin);
            strcpy(title, "Username: ");
            encrpt(title, key);
            fputs(title, fp);
            encrpt(buffer, key);
            fputs(buffer, fp);
            do
            {
                int size;
                system("cls");
                option_logo();
                printf("\nGet a Strong Password\n1.Generate the strong password for me\n2.Use my password\n");
                ch = int_input();
                if (ch == 1)
                {
                    size = password_choice();
                    bool Pcheck = false;
                    short int pch;
                    do
                    {
                        system("cls");
                        password_generator();
                        Pcheck = false;
                        randpass(buffer, size);
                        printf("\nPassword generated: %s\n", buffer);
                        printf("\nChoose an option\n1.Regerate the password.\n2.Save the password.\n");
                        pch = shortint_input();
                        if (pch == 1)
                            Pcheck = true;
                        else if (pch == 2)
                        {
                            clip(buffer);
                            printf("\n Password saved successfully! \n Password copied successfully!\n");
                            system("pause");
                        }
                        else
                        {
                            Pcheck = true;
                            printf("\nWrong option! ,Please enter correct option number\n");
                            system("pause");
                        }
                    } while (Pcheck);
                }
                else if (ch == 2)
                {
                    printf("\nEnter the password : ");
                    fgets(buffer, buffsize, stdin);
                }
                else
                {
                    printf("\nWrong option number entered\n");
                    system("pause");
                }
            } while (!(ch == 1 || ch == 2));
            strcpy(title, "Password: ");
            encrpt(title, key);
            fputs(title, fp);
            encrpt(buffer, key);
            fputs(buffer, fp);

            strcpy(title, "\n\n");
            encrpt(title, key);
            fputs(title, fp);
            free(buffer);
            fclose(fp);
            break;
        }
        case 2:
        {
            do
            {
                system("cls");
                short int ch;
                file_logo();
                printf("\nChoose an option\n1.Show the list\n2.Search the password\n3.Back\n");
                ch = shortint_input();
                if (ch == 1)
                {
                    system("cls");
                    list_logo();
                    show_list("data.txt", key);
                }
                else if (ch == 2)
                {
                    system("cls");
                    search(key);
                }
                else if (ch == 3)
                    break;
                else
                {
                    printf("\nWrong option!\n");
                    system("pause");
                }
            } while (1);
            break;
        }
        case 3:
        {
            int ch;
            do
            {
                system("cls");
                copy_logo();
                printf("\n1.Export Backup file\n2.Import Backup file\n3.Back\n");
                ch = int_input();
                if (ch == 1)
                {
                    copy_file("data.txt", "backup.txt");
                }
                else if (ch == 2)
                {
                    copy_file("backup.txt", "data.txt");
                }
                else if (ch == 3)
                    ;
                else
                {
                    printf("\nWrong option selected\n");
                    system("pause");
                }
            } while (!(ch == 1 || ch == 2 || ch == 3));
            break;
        }
        case 4:
        {
            check = false;
            copy_file("data.txt", "settings.txt");
            break;
        }
        default:
        {
            printf("\nWrong option selected\n");
            break;
        }
        }
    } while (check);
    printf("\nThanks for using\n*****DEBU*****\n");
    system("pause");
}