#include <iostream>
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <time.h>
#include"Decryption.h"

using namespace std;

int main() 
{
  char word[3];
  char key[3][3];
  
  int keyVec[3][3];
  int wordVec[3][1];

  cout<<"\n";

  cin>>word;
  for(int i=0; i<3; i++)
    {
      for(int j=0; j<3; j++)
        {
          cin>>key[i][j];
        }
    }
  
  //Calculating Input Word
  inWord(word, wordVec);

  //Calculating Decryption Key
  decryptKey(key, keyVec);

  int det = determinant(keyVec, 3);

  //Proceeding if Decryption Key is Non Singular
  if(det != 0)
  {
    inverseMatrix(keyVec);
    
    int resVec[3][1];

    //Producing Result Vector
    resultVec(resVec,keyVec,wordVec);
    
    //Printing Decoded Text
    display(resVec);
  }
  return 0;
}
