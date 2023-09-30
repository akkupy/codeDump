
# function of fibbonacci series using class 
# by Peters samuel

class Fibonacci:
    def __init__(self, num):
        self.n = num
        self.series = []

    def generate(self):
        a, b = 0, 1
        for _ in range(self.n):
            self.series.append(a)
            a, b = b, a + b

    def get_series(self):
        return self.series

def main ():
    num = int(input("Enter the number of terms in the Fibonacci series: "))

    fibonacci = Fibonacci(num)
    fibonacci.generate()
    fibonacci_series = fibonacci.get_series()

    print("Fibonacci Series:")
    print(fibonacci_series)
    
if __name__ == "__main__":
    main()
