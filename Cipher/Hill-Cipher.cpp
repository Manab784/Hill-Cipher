#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>

using namespace std;

int main()
{
    char word[26];
    int wordVec[26][1];

    cout<<"Enter Text: ";
    cin>>word;
    
    int l = strlen(word);
    
    //Generating Word Vector
    for(int i=0; i<l; i++)
    {
        for(int j=0; j<1; j++)
        {
            if(int(word[i]) >= 65 && int(word[i]) <= 91)
            {
                wordVec[i][j] = int(word[i]) - 65;
            }
            else if(int(word[i]) >= 97 && int(word[i]) <= 122)
            {
                wordVec[i][j] = int(word[i]) - 97;
            }
        }
    }

    if(l <= 3)
    {
        int keyVec[3][3];
        int encryptWordVec[3][1];

        //Generating Encryption Key Array - No word split up as l <=3
      srand(time(0));  
      for(int i=0; i<l; i++)
        {
            for(int j=0; j<l; j++)
            {
                keyVec[i][j] = ((rand() % 100) + 1) % 26;
            }
        }

        //Add code to check for singularity of Key Array

        //Encryption Array
       for(int i=0; i<l; i++)
        {
            for(int j=0; j<1; j++)
            {
              encryptWordVec[i][j] = 0;
            }
        }
      
        for(int i=0; i<l; i++)
        {
            for(int j=0; j<1; j++)
            {
                for(int k=0; k<3; k++)
                {
                    encryptWordVec[i][j] += keyVec[i][k] * wordVec[k][j];
                }
              encryptWordVec[i][j] %= 26;
            }
        }

        //Encryption Key
        cout<<"\n"<<"Encryption Key: /";
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cout<<char(keyVec[i][j] + 65)<<" ";
            }
            cout<<"/ ";
        }

        //Encrypted Word
        cout<<"\n"<<"Encrypted Word: ";
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<1; j++)
            {
                cout<<char(encryptWordVec[i][j] + 65)<<" ";
            }
        }

      cout<<endl;
    }
    else
    {
        //Generating Encryption Key Array - Word split up as l > 3
    }

}