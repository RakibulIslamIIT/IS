#include <bits/stdc++.h>

using namespace std;

string encryption(string plainText, string key)
{
    string cipherText = plainText;

    for(int i=0;i<plainText.length();i++)
    {
        if(plainText[i] == ' ')
            continue;
        if(plainText[i] >= 'A' && plainText[i] <= 'Z')
            cipherText[i] =  'A' + (((plainText[i] - 'A') + (key[i]- 'a')) %26);

        if(plainText[i] >= 'a' && plainText[i] <= 'z')
            cipherText[i] =  'a' + (((plainText[i] - 'a') + (key[i]- 'a')) %26);

    }

    return cipherText;
}


string decryption(string cipherText, string key)
{
    string decryptedText = cipherText;

    for(int i=0;i<cipherText.length();i++)
    {
        if(cipherText[i] == ' ')
            continue;
        if(cipherText[i] >= 'A' && cipherText[i] <= 'Z')
            decryptedText[i] =  'A' + (((cipherText[i] - 'A') - (key[i]- 'a') + 26) %26);

        if(cipherText[i] >= 'a' && cipherText[i] <= 'z')
            decryptedText[i] =  'a' + (((cipherText[i] - 'a') - (key[i]- 'a') + 26) %26);

    }

    return decryptedText;
}

string resizeKey(string key, int length)
{
    string resizedKey(length, 'a');

    key.erase( remove(key.begin(), key.end(), ' '), key.end() );
    for(int i=0;i<length;i++)
    {
        resizedKey[i] = tolower( key[ (i %key.length())]  );
    }

    return resizedKey;
}


int main(void)
{
    int length;
    string plainText;
    string cipherText;
    string decryptedText;

    cout<<"Enter Plain Text: ";
    getline(cin, plainText);
    length = plainText.length();


    string key;
    cout<<"\nEnter Key: " ;
    getline(cin,key);
    key = resizeKey(key, length);


    cipherText = encryption(plainText, key);
    cout<<"\nCipher Text: "<<cipherText<<endl;


    decryptedText = decryption(cipherText, key);
    cout<<"\nDecrypted Text: "<<decryptedText<<endl;



    return 0;
}
