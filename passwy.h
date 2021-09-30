#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include "codedebuinput.h"
HANDLE wHnd; // Handle to write to the console.
HANDLE rHnd; // Handle to read from the console
void windows_size(int l, int b)
{
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleTitle("Passwy");
    SMALL_RECT windowSize = {0, 0, l, b};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    COORD bufferSize = {10, 10};
    SetConsoleScreenBufferSize(wHnd, bufferSize);
}
void logo()
{
    printf("      .--------.\n ");
    printf("    / .------. \\ \n ");
    printf("   / /        \\ \\ \n ");
    printf("   | |        | |\n ");
    printf("  _| |________| |_\n ");
    printf(".' |_|        |_| '.\n ");
    printf("'._____ ____ _____.'\n ");
    printf("|     .'____'.     |\n ");
    printf("'.__.'.'    '.'.__.'\n ");
    printf("'.__  | DEBU |  __.'\n ");
    printf("|   '.'.____.'.'   |\n ");
    printf("'.____'.____.'____.'\n ");
    printf("'.________________.'\n ");
}
void passwy_logo()
{
    printf(" ______   ______     ______     ______     __     __     __  __    \n");
    printf("/\\  == \\ /\\  __ \\   /\\  ___\\   /\\  ___\\   /\\ \\  _ \\ \\   /\\ \\_\\ \\   \n");
    printf("\\ \\  _-/ \\ \\  __ \\  \\ \\___  \\  \\ \\___  \\  \\ \\ \\/ \".\\ \\  \\ \\____ \\  \n");
    printf(" \\ \\_\\    \\ \\_\\ \\_\\  \\/\\_____\\  \\/\\_____\\  \\ \\__/\".~\\_\\  \\/\\_____\\ \n");
    printf("  \\/_/     \\/_/\\/_/   \\/_____/   \\/_____/   \\/_/   \\/_/   \\/_____/ \n");
    printf("                                                                                             \n");
}
void key_logo()
{
    printf("     .--.\n");
    printf("    /.-. '----------.\n");
    printf("    \\'-' .--\"--\"\"-\"-'\n");
    printf("     '--'\n");
}

void password_generator()
{
    printf("  ____                                     _                                   _             \n");
    printf(" |  _ \\ __ _ ___ _____      _____  _ __ __| |   __ _  ___ _ __   ___ _ __ __ _| |_ ___  _ __ \n");
    printf(" | |_) / _` / __/ __\\ \\ /\\ / / _ \\| '__/ _` |  / _` |/ _ \\ '_ \\ / _ \\ '__/ _` | __/ _ \\| '__|\n");
    printf(" |  __/ (_| \\__ \\__ \\\\ V  V / (_) | | | (_| | | (_| |  __/ | | |  __/ | | (_| | || (_) | |   \n");
    printf(" |_|   \\__,_|___/___/ \\_/\\_/ \\___/|_|  \\__,_|  \\__, |\\___|_| |_|\\___|_|  \\__,_|\\__\\___/|_|   \n");
    printf("                                               |___/                                         \n");
}

void file_logo()
{
    printf(".----.______\n");
    printf("|Passwords  |\n");
    printf("|    ___________\n");
    printf("|   /          /\n");
    printf("|  /          /\n");
    printf("| /          /\n");
    printf("|/__________/\n\n\n");
}

void option_logo()
{
    printf("      A\n");
    printf(" .---/ \\---.\n");
    printf(" |  /___\\  |\n");
    printf(" |         |\n");
    printf(" |    .------.\n");
    printf(" |DEBU|=====\\|\n");
    printf(" '----|______|\n\n");
}

void copy_logo()
{
    printf(".-------.\n");
    printf("| -----.-----.\n");
    printf("| -----| ----|\\\n");
    printf("| -----| ----- |\n");
    printf("| -----| ----- |\n");
    printf("'------| ----- |\n");
    printf("Backup '-------'\n");
}

void list_logo()
{
    printf("\\|/\n");
    printf("-o------.\n");
    printf("/|\\     |\\\n");
    printf(" |      '-|\n");
    printf(" |        |\n");
    printf(" |        |\n");
    printf(" |        |\n");
    printf(" |        |\n");
    printf(" |    List|\n");
    printf(" '--------'\n\n");
}
void search_logo()
{
    printf("  /$$$$$$                                          /$$      \n");
    printf(" /$$__  $$                                        | $$      \n");
    printf("| $$  \\__/  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$$| $$$$$$$ \n");
    printf("|  $$$$$$  /$$__  $$ |____  $$ /$$__  $$ /$$_____/| $$__  $$\n");
    printf(" \\____  $$| $$$$$$$$  /$$$$$$$| $$  \\__/| $$      | $$  \\ $$\n");
    printf(" /$$  \\ $$| $$_____/ /$$__  $$| $$      | $$      | $$  | $$\n");
    printf("|  $$$$$$/|  $$$$$$$|  $$$$$$$| $$      |  $$$$$$$| $$  | $$\n");
    printf(" \\______/  \\_______/ \\_______/|__/       \\_______/|__/  |__/\n\n");
}
void clip(const char *output)
{
    const size_t len = strlen(output) + 1;
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
}
void tolower_str(char *buffer)
{
    for (int i = 0; i < strlen(buffer); i++)
    {
        if (isalpha(buffer[i]))
            buffer[i] = tolower(buffer[i]);
    }
}
int search(int key)
{
    FILE *fp;
    size_t buffsize = 100;
    unsigned char *website = (unsigned char *)malloc(buffsize * sizeof(unsigned char));
    unsigned char *buffer = (unsigned char *)malloc(buffsize * sizeof(unsigned char));
    int counting = 1;
    search_logo();
    printf("\nEnter the website: ");
    fgets(buffer, buffsize, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    tolower_str(buffer);
    fp = fopen("data.txt", "r");
    unsigned char c;
    bool found = false;
    if (fp == NULL)
    {
        printf("\nError in opening the file\n");
        return -1;
    }
    while ((c = fgetc(fp)) != '`')
        ;
    while (1)
    {
        while (((c = fgetc(fp)) ^ key) != ' ')
            ;
        int i = 0;
        while (((c = fgetc(fp)) ^ key) != '\n')
        {
            website[i++] = c ^ key;
        }
        website[i] = '\0';
        system("cls");
        search_logo();
        printf("\nSearching: %d\n", counting++);
        if (strcmp(website, buffer) == 0)
        {
            found = true;
            long int pos;
            unsigned char *password = (unsigned char *)malloc(buffsize * sizeof(unsigned char));
            int i, ch;
            printf("\nFound it!\n");
            pos = ftell(fp);
            printf("\nWebsite: %s\n", buffer);
            for (int i = 0; i < 4; i++)
            {
                while (((c = fgetc(fp)) ^ key) != '\n')
                    fputc(c ^ key, stdout);
                printf("\n");
            }
            rewind(fp);
            fseek(fp, pos, SEEK_SET);
            do
            {
                printf("\nChoose the option\n1.Copy the password to clipboard\n2.Delete the website information\n");
                i=0;
                ch = int_input();
                if (ch == 1)
                {
                    while (((c = fgetc(fp)) ^ key) != '\n')
                        ;
                    while (((c = fgetc(fp)) ^ key) != '\n')
                        ;
                    while (((c = fgetc(fp)) ^ key) != ' ')
                        ;
                    while (((c = fgetc(fp)) ^ key) != '\n')
                    {
                        password[i++] = c ^ key;
                    }
                    password[i] = '\0';
                    clip(password);
                    printf("\nPassword copied successfully!\n");
                }
                else if (ch == 2)
                {
                    long int temp_pos = pos;
                    temp_pos -= (10 + strlen(website));
                    rewind(fp);
                    long int cur_pos = ftell(fp);
                    FILE *tp;
                    unsigned char c;
                    tp = fopen("tem.txt", "w");
                    if (tp == NULL)
                    {
                        printf("\nError in opening the file\n");
                        return -1;
                    }
                    while (cur_pos < temp_pos)
                    {
                        c = fgetc(fp);
                        fputc(c, tp);
                        cur_pos = ftell(fp);
                    }
                    for (int i = 0; i < 5; i++)
                        while (((c = fgetc(fp)) ^ key) != '\n')
                            ;

                    while (1)
                    {
                        c = fgetc(fp);
                        if (!(feof(fp)))
                            fputc(c, tp);
                        else
                            break;
                    }
                    fclose(fp);
                    fclose(tp);
                    tp = fopen("tem.txt", "r");
                    if (fp == NULL)
                    {
                        printf("\nError in opening the file\nFile not found\n");
                        return -1;
                    }
                    fp = fopen("data.txt", "w");
                    if (tp == NULL)
                    {
                        printf("\nError in opening the file\n");
                        return -1;
                    }
                    while (1)
                    {
                        c = fgetc(tp);
                        if (!(feof(tp)))
                            fputc(c, fp);
                        else
                            break;
                    }
                    fclose(tp);
                    remove("tem.txt");
                    printf("\nwebsite data is successfully deleted!");
                    fclose(fp);
                    fp = fopen("data.txt", "r");
                }
                else
                {
                    printf("\nWrong option!\n");
                    system("pause");
                    system("cls");
                    search_logo();
                    printf("\nWebsite: %s\n", buffer);
                    for (int i = 0; i < 4; i++)
                    {
                        while (((c = fgetc(fp)) ^ key) != '\n')
                            fputc(c ^ key, stdout);
                        printf("\n");
                    }
                    rewind(fp);
                    fseek(fp, pos, SEEK_SET);
                }
            } while (!(ch == 1 || ch == 2));
            break;
        }
        else
        {
            for (int i = 0; i < 4; i++)
                while (((c = fgetc(fp)) ^ key) != '\n')
                    ;
            c = fgetc(fp);
            if (feof(fp) != 0)
                break;
        }
    }
    if (found == false)
        printf("\nSorry website not found!\n");
    system("pause");
    free(website);
    free(buffer);
    fclose(fp);
}
int show_list(const char *file_name, int key)
{
    FILE *fp;
    fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("\nError in opening the file\n");
        return -1;
    }
    unsigned char c;
    while ((c = fgetc(fp)) != '`')
        ;
    while (1)
    {
        c = fgetc(fp);
        c ^= key;
        if (!(feof(fp)))
            fputc(c, stdout);
        else
            break;
    }
    printf("\n\n");
    system("pause");
    fclose(fp);
}
int copy_file(const char *source, const char *destination)
{
    FILE *tp;
    FILE *fp;
    unsigned char c;
    fp = fopen(source, "r");
    if (fp == NULL)
    {
        printf("\nError in opening the file\nFile not found\n");
        return -1;
    }
    tp = fopen(destination, "w");
    if (tp == NULL)
    {
        printf("\nError in opening the file\n");
        return -1;
    }
    while (1)
    {
        c = fgetc(fp);
        if (!(feof(fp)))
            fputc(c, tp);
        else
            break;
    }
    fclose(fp);
    fclose(tp);
}

int password_choice()
{
    short int ch = 0;
    int size;
    do
    {
        system("cls");
        password_generator();
        printf("\nPassword Length\n1.Small\n2.Medium\n3.Long\n");
        ch = int_input();
        switch (ch)
        {
        case 1:
            size = rand() % (15 - 10 + 1) + 10;
            break;
        case 2:
            size = rand() % (20 - 15 + 1) + 15;
            break;
        case 3:
            size = rand() % (25 - 20 + 1) + 20;
            break;
        default:
        {
            printf("\nWrong option number entered\n");
            system("pause");
            break;
        }
        }
    } while (!(ch == 1 || ch == 2 || ch == 3));
    return size;
}
int randnum()
{
    int num = rand() % 10;
    char c = 48 + num;
    return c;
}
char randchar()
{
    int num = rand() % 26;
    char c = 97 + num;
    if (rand() % 2)
        return c - 32;
    else
        return c;
}
char randspec()
{
    char c = '!';
    switch (rand() % 8)
    {
    case 0:
        c = '!';
        break;
    case 1:
        c = '@';
        break;
    case 2:
        c = '#';
        break;
    case 3:
        c = '$';
        break;
    case 4:
        c = '%';
        break;
    case 5:
        c = '&';
        break;
    case 6:
        c = '*';
        break;
    case 7:
        c = '^';
        break;
    }
    return c;
}
void encrpt(unsigned char *ch, int key)
{
    int count = 0;
    while (ch[count] != '\0')
    {
        ch[count] ^= key;
        count++;
    }
}
void randpass(char *buffer, int size)
{

    int i, ran;
    for (i = 0; i < size; i++)
    {
        ran = rand() % 10;
        if (ran >= 0 && ran <= 3)
            buffer[i] = randchar();
        else if (ran >= 4 && ran <= 6)
            buffer[i] = randnum();
        else
            buffer[i] = randspec();
    }
    buffer[i] = '\0';
}