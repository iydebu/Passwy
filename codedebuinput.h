#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

long int_input()
{
    long num;
    int size = sizeof(long) * 8;
    char buff[size];
    _Bool success = 0;
    do
    {
        printf("Enter the number: ");
        if (!fgets(buff, size, stdin))
        {
            //reading input failed
            return 1;
        }
        char *endptr;
        errno = 0;
        num = strtol(buff, &endptr, 10);
        if (errno == ERANGE)
        {
            printf("Sorry, this number is too small or too large.\n");
        }
        else if (endptr == buff)
        {
            //no character was read
            success = 0;
        }
        else if (*endptr != '\0' && *endptr != '\n')
        {
            // *endptr is neither end of string nor newline,
            // so we didn't convert the *whole* input
            success = 0;
        }
        else
        {
            success = 1;
        }
    } while (!success); // repeat until we got a valid number
    return num;
}

short int shortint_input()
{
    short int num;
    int size = sizeof(short int) * 8;
    char buff[size];
    _Bool success = 0;
    do
    {
        printf("Enter the number: ");
        if (!fgets(buff, size, stdin))
        {
            return 1;
        }
        char *endptr;
        errno = 0;
        num = strtol(buff, &endptr, 10);
        if (errno == ERANGE)
        {
            printf("Sorry, this number is too small or too large.\n");
        }
        else if (endptr == buff)
        {
            success = 0;
        }
        else if (*endptr != '\0' && *endptr != '\n')
        {
            success = 0;
        }
        else
        {
            success = 1;
        }
    } while (!success);
    return num;
}

long long longlong_input()
{
    long long num;
    int size = sizeof(long long) * 8;
    char buff[size];
    _Bool success = 0;
    do
    {
        printf("Enter the number: ");
        if (!fgets(buff, size, stdin))
        {
            return 1;
        }
        char *endptr;
        errno = 0;
        num = strtoll(buff, &endptr, 10);
        if (errno == ERANGE)
        {
            printf("Sorry, this number is too small or too large.\n");
        }
        else if (endptr == buff)
        {
            success = 0;
        }
        else if (*endptr != '\0' && *endptr != '\n')
        {
            success = 0;
        }
        else
        {
            success = 1;
        }
    } while (!success);
    return num;
}

float float_input()
{
    float num;
    int size = sizeof(float) * 8;
    char buff[size];
    _Bool success = 0;
    do
    {
        printf("Enter the number: ");
        if (!fgets(buff, size, stdin))
        {
            return 1;
        }
        char *endptr;
        errno = 0;
        num = strtof(buff, &endptr);
        if (errno == ERANGE)
        {
            printf("Sorry, this number is too small or too large.\n");
        }
        else if (endptr == buff)
        {
            success = 0;
        }
        else if (*endptr != '\0' && *endptr != '\n')
        {
            success = 0;
        }
        else
        {
            success = 1;
        }
    } while (!success);
    return num;
}

double double_input()
{
    double num;
    int size = sizeof(double) * 8;
    char buff[size];
    _Bool success = 0;
    do
    {
        printf("Enter the number: ");
        if (!fgets(buff, size, stdin))
        {
            return 1;
        }
        char *endptr;
        errno = 0;
        num = strtod(buff, &endptr);
        if (errno == ERANGE)
        {
            printf("Sorry, this number is too small or too large.\n");
        }
        else if (endptr == buff)
        {
            success = 0;
        }
        else if (*endptr != '\0' && *endptr != '\n')
        {
            success = 0;
        }
        else
        {
            success = 1;
        }
    } while (!success);
    return num;
}