def roman_to_integer(s):
    roman_map = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    num = 0
    prev_value = 0


    for c in s[::-1]:
        current_value = roman_map[c]

        if current_value < prev_value:
            num -= current_value
        else:
            num += current_value

        prev_value = current_value

    return num


roman_numeral = "MCMXCIV"
result = roman_to_integer(roman_numeral)
print(result)
