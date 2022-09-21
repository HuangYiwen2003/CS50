#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    string plaintext = get_string("plaintext: ");
    int k = atoi(argv[1]);
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            printf("%c", (plaintext[i] + k - 97) % 26 + 97);
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            printf("%c", (plaintext[i] + k - 65) % 26 + 65);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
