#include <stdio.h>
#include <random>
#include "my_array.h"

void PrintArray(int const* pArr, size_t const len)
{
    printf ("\n");
    for (size_t i = 0; i < len; i++)
    {
        printf("%4d ", pArr[i]);
        if (i && (i + 1) % 10 == 0) printf("\n");
    }
    
    printf("\n---------------------------------------------------\n");
}

void FreeMemory(int** pArr)
{
    delete[] *pArr;
    *pArr = nullptr;
}

void AllocatedMemory(int** pArr, size_t const len)
{
    *pArr = new int[len];
}

void InitArrayRandomely(int* pArr, size_t const len, int const left, int const right)
{
    int dispersion = right - left + 1;
    for (size_t i = 0; i < len; i++)
    {
        pArr[i] = left + rand() % dispersion;
    }
}

void PushFront(int** pArr, int* len, int const e)
{
    int len_new = *len + 1;
    int* p_new = new int[len_new];
    p_new[0] = e;
    for (size_t i = 0; i < *len; i++)
    {
        p_new[i + 1] = (*pArr)[i];
    }
    FreeMemory(pArr);
    *pArr = p_new;
    *len = len_new;
}

void PushBack(int** pArr,  int* len, int const e)
{
    int len_new = *len + 1;
    int* p_new = new int[len_new];
    p_new[len_new - 1] = e;
    for (size_t i = 0; i < *len; i++)
    {
        p_new[i] = (*pArr)[i];
    }
    FreeMemory(pArr);
    *pArr = p_new;
    *len = len_new;
}

void Insert(int** pArr,    int* len, size_t pos, int const e)
{
    int len_new = *len + 1;
    int* p_new = new int[len_new];
    p_new[len_new - 1] = e;
    for (size_t i = 0; i < len_new; i++)
    {
        if (i < pos)
        {
            p_new[i] = (*pArr)[i];
        }
        else if (i == pos)
        {
            p_new[i] = e;
        }
        else
        {
            p_new[i] = (*pArr)[i - 1];
        }
    }
    FreeMemory(pArr);
    *pArr = p_new;
    *len = len_new;
}

void RemoveFront(int** pArr, int* len)
{
    int len_new = *len - 1;
    for (size_t i = 0; i < len_new; i++)
    {
        (*pArr)[i] = (*pArr)[i + 1];
    }
    *len = len_new;
}

void RemoveBack(int** pArr, int* len)
{
    int len_new = *len - 1;
    *len = len_new;
}

void Erase(int** pArr, size_t pos, int* len)
{
    int len_new = *len - 1;
    for (size_t i = pos; i < len_new; i++)
    {
        (*pArr)[i] = (*pArr)[i + 1];
    }
 
    *len = len_new;
}

void Get_Min_Max_Sum_Product_From_Array(int* pArr, size_t const len, int* min, int* max, int* sum, long* product)
{
    *min = pArr[0];
    *max = pArr[0];
    *sum = 0;
    * product = 1;
    for (size_t i = 0; i < len; i++)
    {
        *sum += pArr[i];
        *product *= pArr[i];

        if (pArr[i] < *min)
        {
            *min = pArr[i];
        }

        if (pArr[i] > *max)
        {
            *max = pArr[i];
        }
    }
    
}