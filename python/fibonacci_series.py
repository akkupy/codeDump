def f(n):
  if n in F:
    return F[n]
  k = n // 2
  if n % 2 == 0:  # n=2*k
    F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % M
  else:  # n=2*k+1
    F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % M
  return F[n]

F = {0: 1, 1: 1}
M = 1000000007

while True:
  n = int(input("enter the number "))
  if n == 0:
    break
  print(f(n - 1))
