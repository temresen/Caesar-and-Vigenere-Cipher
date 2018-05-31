#include <stdio.h>
#include <stdlib.h>
#include "ciphermethods.h"
#include "basics.h"

char* encryptCaeser(const char* text)
{
    int i = 0;
    int flag = 0;
    char c = text[i];
    char* encryptedText = (char*)malloc((strlen(text))* sizeof(char));

    while(c != '\0')
    {
        for(int i = 0; i < strlen(CIPHER_SPECIAL_CHARS); i++)
        {
            if(c == CIPHER_SPECIAL_CHARS[i])
            {
                flag = 1;
                break;
            }
        }
        
        if(c >= 48 && c <= 57 && flag == 0)
        {
            encryptedText[i] = (text[i] + CHEASER_SHIFT);
            if(text[i] > 57)
            {
                encryptedText[i] = (text[i] % 57) + 48;
            }
        }
            
        if(c >= 65 && c <= 90 && flag == 0)
        {
            encryptedText[i] = (text[i] + CHEASER_SHIFT);
            if(text[i] > 90)
            {
                encryptedText[i] = (text[i] % 90) + 65;
            }                   
        }
            
        if(c >= 97 && c <= 122 && flag == 0)
        {
            encryptedText[i] = (text[i] + CHEASER_SHIFT);
            if(text[i] > 122)
            {
                encryptedText[i] = (text[i] % 122) + 97;
            }                 
        }

        if(flag == 1)
        {
            encryptedText[i] = text[i];
        }

        flag = 0;
        i++;
        c = text[i];
    }
    
    return encryptedText;
}

char* decryptCaesar(const char* cipher)
{
    int i = 0;
    int flag = 0;
    char c = cipher[i];
    char* decryptedText = (char*)malloc((strlen(cipher))* sizeof(char));

    while(c != '\0')
    {
        for(int i = 0; i < strlen(CIPHER_SPECIAL_CHARS); i++)
        {
            if(c == CIPHER_SPECIAL_CHARS[i])
            {
                flag = 1;
                break;
            }
        }
        
        if(c >= 48 && c <= 57 && flag == 0)
        {
            decryptedText[i] = (cipher[i] - CHEASER_SHIFT);
            if(cipher[i] > 57)
            {
                decryptedText[i] = (cipher[i] % 57) + 48;
            }
        }
        
        if(c >= 65 && c <= 90 && flag == 0)
        {
            decryptedText[i] = (cipher[i] - CHEASER_SHIFT);
            if(cipher[i] > 90)
            {
                decryptedText[i] = (cipher[i] % 90) + 65;
            }                   
        }
        
        if(c >= 97 && c <= 122 && flag == 0)
        {
            decryptedText[i] = (cipher[i] - CHEASER_SHIFT);
            if(cipher[i] > 122)
            {
                decryptedText[i] = (cipher[i] % 122) + 97;
            }                 
        }
        if(flag == 1)
        {
            decryptedText[i] = cipher[i];
        }

        flag = 0;        
        i++;
        c = cipher[i];
    }
    
    return decryptedText;
}

char* encryptVigenere(const char* text)
{   
    char* newGeneratedKey = (char*)malloc((strlen(text) + strlen(VIGENERE_KEY)) * sizeof(char));
    char* encryptedText = (char*)malloc((strlen(text) + strlen(VIGENERE_KEY)) * sizeof(char));

    //GENERATE NEW KEY
    int j = 0;

    for(int i = 0; i < strlen(text); i++)
    {
        if(j == strlen(VIGENERE_KEY))
        {
            j = 0;
        }
        newGeneratedKey[i] = VIGENERE_KEY[j];
        j++;
    }

    //printf("KEY ------>       %s\n",newGeneratedKey);

    for(int i = 0; i < strlen(text); i++)
    {
        encryptedText[i] = ((text[i] + newGeneratedKey[i]) % NUMBER_OF_LETTERS) + 'A';
    }

    return encryptedText;

}
char* decryptVigenere(const char* cipher)
{
    char* newGeneratedKey = (char*)malloc((strlen(cipher) + strlen(VIGENERE_KEY)) * sizeof(char));
    char* decryptedText = (char*)malloc((strlen(cipher)) * sizeof(char));

    //GENERATE NEW KEY
    int j = 0;

    for(int i = 0; i < strlen(cipher); i++)
    {
        if(j == strlen(VIGENERE_KEY))
        {
            j = 0;
        }
        newGeneratedKey[i] = VIGENERE_KEY[j];
        j++;
    }

    //printf("KEY ------>       %s\n",newGeneratedKey);

    for(int i = 0; i < strlen(cipher); i++)
    {
        decryptedText[i] = (((cipher[i] - newGeneratedKey[i]) + NUMBER_OF_LETTERS) % NUMBER_OF_LETTERS) + 'A';
    }
    
    return decryptedText;

}


