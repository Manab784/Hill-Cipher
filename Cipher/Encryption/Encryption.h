#ifndef ENCRYPTION_H
#define ENCRYPTION_H

int determinant(int matrix[3][3], int n);
void wordGen(int wordVec[26][1], char word[26], int l);
void encryptArray(int encryptWordVec[3][1], int keyVec[3][3], int wordVec[26][1], int l);
void displayKey(int keyVec[3][3]);
void displayWord(int encryptWordVec[3][1]);

#endif
