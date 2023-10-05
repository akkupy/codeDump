import math
import os
import random
import re
import sys

# Read the number of rows and columns
first_multiple_input = input().rstrip().split()
n = int(first_multiple_input[0])
m = int(first_multiple_input[1])

# Read the matrix script lines
matrix = []
for _ in range(n):
    matrix_item = input()
    matrix.append(matrix_item)

# Combine the characters from each column into a single string
decoded_script = ''.join(matrix[j][i] for i in range(m) for j in range(n))

# Use regular expressions to split the decoded script at non-alphanumeric characters
decoded_script = re.sub(r'(?<=\w)([^\w\d]+)(?=\w)', ' ', decoded_script)

# Print the decoded script
print(decoded_script)
