import math
a, b = int(input()), int(input())
angle = round(math.degrees(math.atan(a/b)))
degree_sign = u"\u00b0"
print(f'{angle}{degree_sign}')
