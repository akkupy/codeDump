def clear_rightmost_set_bit(n):
    """Clear rightmost set bit of n and return it."""
    return n & (n - 1)
 
 
n = int(input('Number: '))
ans = clear_rightmost_set_bit(n)
print('n with its rightmost set bit cleared equals:', ans)
