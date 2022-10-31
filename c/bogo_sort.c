
/**
 * @file
 * @brief Bogosort the random sorting algorithem.
 * @author [XenoxJeager] (https://github.com/XenoxJeager)
 * @details
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_sorted(int c[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (c[i] > c[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void bogo_sort(int c[], int size)
{
    int x;
    int r;
    for (int i = 0; i < size; i++)
    {
        x = c[i];
        r = rand()%size;
        c[i] = c[r];
        c[r] = x;
    }
}

int main()
{
    int init[5]={23,4,800,33,90};
    while(!is_sorted(init,sizeof(init)/4)){
        bogo_sort(init,sizeof(init)/4);

    }


}