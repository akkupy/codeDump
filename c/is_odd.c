
#include <stdio.h>
#include <stdbool.h>
/**
 * @file
 * @brief Checks if int is even or odd.
 * [Explanation](https://www.geeksforgeeks.org/check-if-a-number-is-odd-or-even-using-bitwise-operators/)
 * @author [XenoxJeager] (https://github.com/XenoxJeager)
 * @details
 * Checks if int is even or odd depending on its LSB(1 or 0).
 */

/**
 * @brief performs bitwise and with i and 1 and returns result.
 * 
 * @param i int
 * @return true 
 * @return false 
 */
bool isodd(int i){
    return i & 1;
}

int main(){
    // returns 0 since 42 is even
    printf("%d \n",isodd(42));

}


