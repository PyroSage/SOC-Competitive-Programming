import time
n = 10e7
is_prime = [1] * (int(n) + 1)
is_prime[0] = is_prime[1] = 0
prime = []
time1 = time.time()
for i in range(2, int(n)):
    if i * i > n:
        break
    if is_prime[i]:
        for j in range(i * i, int(n) + 1, i):
            is_prime[j] = 0
            
for i in range(2, int(n) + 1):
    if is_prime[i]:
        prime.append(i)

for i in range(1, len(prime), 100):
    print(prime[i-1])
    
time2 = time.time()
print(time2 - time1)