#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ciphermethods.h"
#include "ciphermethods.c"
#define TRACE_ORG_DEC

int main()
{
    char text[500];
    char passcode[8] = "cmpe252";
    char input[8];
    int cipher_type;
    
    printf("**You are about to enter a very secret crytopgraphy**\n");
    printf("**service called CMPE252 C-Secret-Coded System\n");
    printf("Enter your text:\n");
    scanf("%[^\n]", text);
    printf("***********\n");
    printf("1) Ceaser Cipher\n");
    printf("1) Vigenere Cipher\n");
    printf("***********\n");
    printf("Please enter the cipher type: ");
    scanf("%d", &cipher_type);
    //system("CLEAR");
    
    char* decText = (char*)malloc((strlen(text))* sizeof(char));
    char* encText = (char*)malloc((strlen(text)) * sizeof(char));
    
    if(cipher_type == 1)
    {
        encText = encryptCaeser(text);
    }

    else if(cipher_type == 2)
    {
        encText = encryptVigenere(text);
    }

    int result = 0;
    int counter = 0;
    printf("In order to see the encrypted message, enter your passcode:\n");
    //scanf("%s", input);
    //result = strcmp(passcode, input);
    if(result == 0)
    {
        printf("Cipher: ");
        printf("%s\n", encText);
        printf("\nWould you like to convert the cipher to original text (Y/N)?\n");
        char answer;
        scanf(" %c",&answer);
        if(answer == 'Y' || answer == 'y')
        {
            if(cipher_type == 1)
            {
                decText = decryptCaesar(encText);
            }

            else if(cipher_type == 2)
            {
                decText = decryptVigenere(encText);
            }

            printf("%s\n", decText);

            #ifdef TRACE_ORG_DEC
            
            if(strcmp(text, decText) == 0)
            {
                printf("Original text and the decrypted text match.\n\n");
            }

            else
            {
                printf("There is something wrong. Original text and the decrypted text do not match.\n\n");
            }
            
            #endif //TRACE_ORG_DEC
            
        }
    }
    
    else
    {
        while(counter < 2)
        {
            counter++;
            printf("Wrong passcode. Enter again:\n");
            scanf("%s", input);
            result = strcmp(passcode, input);
            if(result == 0)
            {
                printf("Cipher: ");
                printf("%s\n", encText);
                printf("\nWould you like to convert the cipher to original text (Y/N)?\n");
                char answer;
                scanf(" %c",&answer);
                if(answer == 'Y' || answer == 'y')
        {

                if(cipher_type == 1)
                {
                    decText = decryptCaesar(encText);
                }

                else if(cipher_type == 2)
                {
                    decText = decryptVigenere(encText);
                }

                printf("%s\n", decText);
                #ifdef TRACE_ORG_DEC
            
                if(strcmp(text, decText) == 0)
                {
                    printf("Original text and the decrypted text match.\n\n");
                }
                
                else
                {
                    printf("There is something wrong. Original text and the decrypted text do not match.\n\n");
                }
            
                #endif //TRACE_ORG_DEC
        } 

                return 0;
            }
        }

        printf("Number of allowed attemps has been reached without succesful entry!\n");
        printf("You IP has been blacklisted by us. Good luck!!\n");
    }

    return 0;
}
