#ifndef DECRYPTION_H
#define DECRYPTION_H

int determinant(int matrix[3][3], int n);
int modInverse(int a, int m);
void inverseMatrix(int matrix[3][3]);
void inWord(char word[3], int wordVec[3][1]);
void decryptKey(char key[3][3], int keyVec[3][3]);
void resultVec(int resVec[3][1], int keyVec[3][3], int wordVec[3][1]);
void display(int resVec[3][1]);

#endif
