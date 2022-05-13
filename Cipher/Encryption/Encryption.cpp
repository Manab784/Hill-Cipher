#include <iostream>
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <time.h>
#include"Encryption.h"

using namespace std;

int main() 
{
  char text[100];
  char word[26];
  int wordVec[26][1];

  cout<<"\n";

  cin >> text;
  strcpy(word,text);
  int l = strlen(word);

  if (l == 3) 
  {
    //Encrpyts the text input in pairs of 3 letters
    //Generating Word Vector
    wordGen(wordVec, word, l);  

    int keyVec[3][3];
    int encryptWordVec[3][1];

    // Generating Encryption Key Array - No word split up as l <=3
    keyGen(keyVec, l);

    // Encryption Array
    encryptArray(encryptWordVec, keyVec, wordVec, l);

    // Encryption Key
    displayKey(keyVec);

    // Encrypted Word
    displayWord(encryptWordVec);
  }
  return 0;
}
