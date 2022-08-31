#include <bits/stdc++.h>

using namespace std;

string encryption(string message, int key)
{
      string cipher = message;
      for(int i=0;i<message.length();i++)
      {
            if(message[i] >= 'A' && message[i] <= 'Z'){

                  cipher[i] = (message[i] - 'A' + key) % 26 +  'A';

            }
            if(message[i] >= 'a' && message[i] <= 'z'){


                  cipher[i] = ((message[i] - 'a') + key) % 26 + 'a';
            }

      }
      return cipher;
}

string decryption(string cipher, int key)
{
      string decryptedText = cipher;
      for(int i=0;i<cipher.length();i++)
      {
            if(cipher[i] >= 'A' && cipher[i] <= 'Z'){

                  decryptedText[i] = ((cipher[i] - 'A'+26) - key) % 26 +  'A';

            }
            if(cipher[i] >= 'a' && cipher[i] <= 'z'){

                  decryptedText[i] = ((cipher[i] - 'a'+26) - key) % 26 + 'a';
            }

      }
      return decryptedText;
}




int main()
{
      string message;
      int key;
      string cipherText;
      getline(cin,message);
      cout<<"Enter Key: ";
      cin>>key;


      cipherText = encryption(message,key);

      cout<<"Cipher Text: ";
      cout<<cipherText<<endl;
      cout<<endl;


      string decryptedText;

      decryptedText = decryption(cipherText, key);
      cout<<"Decrypted Text: ";
      cout<<decryptedText<<endl;

}
