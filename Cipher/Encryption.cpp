#include <iostream>
#include <math.h>
#include <stdio.h>
#include<fstream>
#include <string.h>
#include <time.h>

using namespace std;

int determinant(int matrix[3][3], int n) 
{
  int det = 0;
  int submatrix[3][3];
  if (n == 2)
  {
    return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
  }
  else 
  {
    for (int x = 0; x < n; x++) 
    {
      int subi = 0;
      for (int i = 1; i < n; i++) 
      {
        int subj = 0;
        for (int j = 0; j < n; j++) 
        {
          if (j == x)
            continue;
          submatrix[subi][subj] = matrix[i][j];
          subj++;
        }
        subi++;
      }
      det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
    }
  }
  return det;
}

int main() 
{
  char text[100];
  char word[26];
  int wordVec[26][1];

  cout<<"\n";

  cin >> text;

  //Add code to split input text into pairs of 3 letters 
  strcpy(word,text);

  int l = strlen(word);

  if (l == 3) 
  {
    //Encrpyts the text input in pairs of 3 letters
    //Generating Word Vector
    for (int i = 0; i < l; i++) 
    {
      for (int j = 0; j < 1; j++) 
      {
        if (int(word[i]) >= 65 && int(word[i]) <= 91) 
        {
          wordVec[i][j] = int(word[i]) - 65;
        } 
        else if (int(word[i]) >= 97 && int(word[i]) <= 122) 
        {
          wordVec[i][j] = int(word[i]) - 97;
        }
      }
    }

<<<<<<< HEAD:Cipher/Encryption/EncryptFunc.cpp
void encryptArray(int encryptWordVec[3][1], int keyVec[3][3], int wordVec[26][1], int l)
{
=======
    int keyVec[3][3];
    int encryptWordVec[3][1];

    // Generating Encryption Key Array - No word split up as l <=3
    srand(time(0));
    do 
    {
      for (int i = 0; i < l; i++) 
      {
        for (int j = 0; j < l; j++) 
        {
          keyVec[i][j] = ((rand() % 100) + 1) % 26;
        }
      }
    } 
    while (determinant(keyVec, 3) == 0);

    // Encryption Array
>>>>>>> parent of 41f0475 (Structured Files):Cipher/Encryption.cpp
    for (int i = 0; i < l; i++) 
    {
      for (int j = 0; j < 1; j++) 
      {
        encryptWordVec[i][j] = 0;
      }
    }

    for (int i = 0; i < l; i++) 
    {
      for (int j = 0; j < 1; j++) 
      {
        for (int k = 0; k < 3; k++) 
        {
          encryptWordVec[i][j] += keyVec[i][k] * wordVec[k][j];
        }
        encryptWordVec[i][j] %= 26;
      }
    }

<<<<<<< HEAD:Cipher/Encryption/EncryptFunc.cpp
void displayKey(int keyVec[3][3])
{
<<<<<<< HEAD:Cipher/Encryption.cpp
=======
    // Encryption Key
    cout << "\n"
         << "Encryption Key: / ";
>>>>>>> parent of 41f0475 (Structured Files):Cipher/Encryption.cpp
=======
    cout << "\n"
         << "Encryption Key: / ";
>>>>>>> parent of f08b29d (Updates):Cipher/Encryption/EncryptFunc.cpp
    for (int i = 0; i < 3; i++) 
    {
      for (int j = 0; j < 3; j++) 
      {
        cout << char(keyVec[i][j] + 65) << " ";
      }
      cout << "/ ";
    }
<<<<<<< HEAD:Cipher/Encryption.cpp
<<<<<<< HEAD:Cipher/Encryption/EncryptFunc.cpp
=======

>>>>>>> parent of f08b29d (Updates):Cipher/Encryption/EncryptFunc.cpp
}

void displayWord(int encryptWordVec[3][1])
{
<<<<<<< HEAD:Cipher/Encryption.cpp
=======

    // Encrypted Word
    cout << "\n"
         << "Encrypted Word: ";
>>>>>>> parent of 41f0475 (Structured Files):Cipher/Encryption.cpp
=======
    cout << "\n"
         << "Encrypted Word: ";
>>>>>>> parent of f08b29d (Updates):Cipher/Encryption/EncryptFunc.cpp
    for (int i = 0; i < 3; i++) 
    {
      for (int j = 0; j < 1; j++) 
      {
        cout << char(encryptWordVec[i][j] + 65) << " ";
      }
    }
<<<<<<< HEAD:Cipher/Encryption.cpp
<<<<<<< HEAD:Cipher/Encryption/EncryptFunc.cpp
    cout<<" ";
=======

    cout << "\n" <<"\n";
  } 
>>>>>>> parent of 41f0475 (Structured Files):Cipher/Encryption.cpp
=======
    cout << "\n" <<"\n";
>>>>>>> parent of f08b29d (Updates):Cipher/Encryption/EncryptFunc.cpp
}
