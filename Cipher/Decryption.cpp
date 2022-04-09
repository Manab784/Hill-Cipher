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

//Change to float
void inverseMatrix(int matrix[3][3])
{
  int det = determinant(matrix,3);
  int resMat[3][3];
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
      {
        resMat[i][j] = ((matrix[(j+1)%3][(i+1)%3] *         matrix[(j+2)%3][(i+2)%3]) - (matrix[(j+1)%3]        [(i+2)%3] * matrix[(j+2)%3][(i+1)%3]))/det;

        resMat[i][j] %= 26;
        cout<<resMat[i][j]<<" ";
      }
  }
  cout<<"\n"<<"\n";

  for(int i=0; i<3; i++)
    {
      for(int j=0; j<3; j++)
        {
          matrix[i][j] = resMat[i][j];
        }
    }
}

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

  //Calculating Decryption Key
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

  int det = determinant(keyVec, 3);

  //Temporary
  cout<<"\n";
  for(int i=0; i<3; i++)
    {
      for(int j=0; j<1; j++)
        {
          cout<<wordVec[i][j];
        }
      cout<<"\n";
    }

  cout<<endl;

  for(int i=0; i<3; i++)
    {
      for(int j=0; j<3; j++)
        {
          cout<<keyVec[i][j]<<" ";
        }
      cout<<endl;
    }

  cout<<"\n";
  //End of Temporary
  
  //Proceeding if Decryption Key is Non Singular
  if(det != 0)
  {
    inverseMatrix(keyVec);
    //Temporary
    for(int i=0; i<3; i++)
      {
        for(int j=0; j<3; j++)
          {
            cout<<keyVec[i][j];
          }
        cout<<"\n";
      }
    cout<<"\n";
    //End of Temporary
    
    int resVec[3][1];

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
                //resVec[i][j] %= 26;
              }
          }
      }

  //Temporary
    for(int i=0; i<3; i++)
      {
        for(int j=0; j<1; j++)
          {
            cout<<resVec[i][j];
          }
        cout<<"\n";
      }
  //End of Temporary
    
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
