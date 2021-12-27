#pragma once

void InitRandomIntArray(int** pArr, int size, int leftBound, int rightBound);
static void AllocIntArray(int** pArr, int size);
void CleanArray(int** pArr);
void PrintIntArray(int const* pArr, int size);