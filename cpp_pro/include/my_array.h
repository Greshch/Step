#pragma once

void Get_Min_Max_Sum_Product_From_Array(int* pArr, size_t const len, int* min, int* max, int* sum, long* product);

void AllocatedMemory(int** pArr, size_t const len);
void InitArrayRandomely(int* pArr, size_t const len, int const left, int const right);
void PrintArray(int const* pArr, size_t const len);
void FreeMemory(int** pArr);
void PushFront(int** pArr, int* len, int const e);
void PushBack(int** pArr,  int* len, int const e);
void Insert(int** pArr,    int* len, size_t pos, int const e);
void RemoveFront(int** pArr, int* len);
void RemoveBack(int** pArr, int* len);
void Erase(int** pArr, size_t pos, int* len);