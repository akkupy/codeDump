#include <stdio.h>
/**
 * @file c/power2_mod.c
 * @brief Returns the mod of an unsigned int, the modulo number supplied needs to be 2^n and n >=0 = and n < 31 . 
 * @author [XenoxJeager] (https://github.com/XenoxJeager)
 */

/**
 * @brief returns the square root of powers of 2 from 0 to 2^31.
 * 
 * @param d has to be a power of 2 otherwise the function is not precise.
 * @return unsigned int pow which discribes the n in 2^n.
 */
unsigned int square_root(unsigned int d){
    int pow = 0;
    while ( !(2147483648&d)){
        d = d<<1;
        pow++;
    }
    return 31-pow;

} 

/**
 * @brief 
 * 
 * @param number any number n ranging from n=0 to n=2^32-1.
 * @param mod has to be a power of 2.
 * @return unsigned int which represents the mod.
 */
unsigned int mod_power2(unsigned int number, unsigned int mod){
    int mask = 0;
    for (int i = 0; i < square_root(mod) ;i++ ){
        mask |=1 << i;
    }
    
    return number& mask;
}
int main (){
    printf("mod: %u \n",mod_power2(32,16));
}