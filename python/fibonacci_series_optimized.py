class FibonacciSeries:
    def __init__(self, n):
        self.n = n
        self.fib_series = []

    def generate(self):
        if self.n <= 0:
            return []

        self.fib_series = [0, 1]

        if self.n == 1:
            return [0]

        while len(self.fib_series) < self.n:
            next_fib = self.fib_series[-1] + self.fib_series[-2]
            self.fib_series.append(next_fib)

        return self.fib_series

    def get_series(self):
        if not self.fib_series:
            self.generate()
        return self.fib_series



n = 100  # Change this value to generate the Fibonacci series up to a different number
fibonacci_sequence = FibonacciSeries(n)
result = fibonacci_sequence.get_series()
print(result)
