#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int i;
    for (i = 0; argv[1][i] != '\0'; i++)
    {
        if ((tolower(argv[1][i]) < 'a' || tolower(argv[1][i]) > 'z'))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    if (i != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (i = 0; argv[1][i] != '\0'; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    int index;
    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            index = plaintext[i] - 97;
            printf("%c", tolower(argv[1][index]));
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            index = plaintext[i] - 65;
            printf("%c", toupper(argv[1][index]));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}