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

void inverseMatrix(int matrix[3][3])
{
  int det = determinant(matrix,3);
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
      {
        matrix[i][j] = ((matrix[(j+1)%3][(i+1)%3] *         matrix[(j+2)%3][(i+2)%3]) - (matrix[(j+1)%3]        [(i+2)%3] * matrix[(j+2)%3][(i+1)%3]))/det;

        matrix[i][j] %= 26;
      }
  }
}

int main() 
{
  int keyVec[3][3];
  int wordVec[3][1];

  //Accepting Input Word
  for(int i=0; i<3; i++)
    {
      for(int j=0; j<1; j++)
        {
          cin>>wordVec[i][j];
        }
    }

  //Accepting Decryption Key
  for(int i=0; i<3; i++)
    {
      for(int j=0; j<3; j++)
        {
          cin>>keyVec[i][j];
        }
    }

  int det = determinant(keyVec, 3);
  //Proceeding if Decryption Key is Non Singular
  if(det != 0)
  {
    inverseMatrix(keyVec);
    int resVec[3][1];

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

    //Printing Decoded Text
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
}
