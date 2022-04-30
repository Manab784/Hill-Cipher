#include <iostream>
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <time.h>
#include"Decryption.h"

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

int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
  return 0;
}

void inverseMatrix(int matrix[3][3])
{
  int det = determinant(matrix,3);
  int modMulInv = modInverse(det,26);
  
  int resMat[3][3];
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
      {
        resMat[i][j] = ((matrix[(j+1)%3][(i+1)%3] * matrix[(j+2)%3][(i+2)%3]) - (matrix[(j+1)%3][(i+2)%3] * matrix[(j+2)%3][(i+1)%3])) * modMulInv;
      }
  }

  for(int i=0; i<3; i++)
    {
      for(int j=0; j<3; j++)
        {
          if(resMat[i][j] < 0)
          {
            matrix[i][j] = 26 - abs(resMat[i][j] % 26);
          }
          else
          {
            matrix[i][j] = (resMat[i][j] % 26);
          }
        }
    }
}

void inWord(char word[3], int wordVec[3][1])
{
    for(int i=0; i<3; i++)
    {
      for(int j=0; j<1; j++)
        {
          if(isupper(word[i]))
          {
            wordVec[i][j] = int(word[i] - 65);
          }
          else
          {
            wordVec[i][j] = int(word[i] - 97);
          }
          
        }
    }
}

void decryptKey(char key[3][3], int keyVec[3][3])
{
    for(int i=0; i<3; i++)
    {
      for(int j=0; j<3; j++)
        {
          if(isupper(key[i][j]))
          {
            keyVec[i][j] = int(key[i][j] - 65);
          }
          else
          {
            keyVec[i][j] = int(key[i][j] - 97);
          }
        }
    }
}

void resultVec(int resVec[3][1], int keyVec[3][3], int wordVec[3][1])
{
    for(int i=0; i<3; i++)
      {
        for(int j=0; j<1; j++)
          {
            resVec[i][j] = 0;
          }
      }
    
    //Producing Result Vector
    for(int i=0; i<3; i++)
      {
        for(int j=0; j<1; j++)
          {
            for(int k=0; k<3; k++)
              {
                resVec[i][j] += keyVec[i][k] * wordVec[k][j];
                resVec[i][j] %= 26;
              }
          }
      }
}

void display(int resVec[3][1])
{
    cout<<"\n"<<"Decoded Text: ";
    for(int i=0; i<3; i++)
      {
        for(int j=0; j<1; j++)
          {
            cout<< char(resVec[i][j] + 65);
          }
      }

    cout<<endl;
}
