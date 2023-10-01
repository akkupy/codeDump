def generate_pascals_triangle(num_rows):
    triangle = []
    for i in range(num_rows):
        row = []
        for j in range(i + 1):
            if j == 0 or j == i:
                row.append(1)
            else:
                prev_row = triangle[i - 1]
                row.append(prev_row[j - 1] + prev_row[j])
        triangle.append(row)
    return triangle

def print_pascals_triangle(triangle):
    for row in triangle:
        print(" ".join(map(str, row)).center(len(triangle[-1]) * 3))

if __name__ == "__main__":
    num_rows = int(input("Enter the number of rows for Pascal's Triangle: "))
    if num_rows <= 0:
        print("Please enter a positive integer.")
    else:
        pascals_triangle = generate_pascals_triangle(num_rows)
        print_pascals_triangle(pascals_triangle)
