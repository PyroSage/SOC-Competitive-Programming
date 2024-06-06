class solution:
    def bin_expo(self, a, b, mod):
        ans = 1
        while b > 0:
            if b & 1:
                ans = (ans * a) % mod 
            a = (a * a) % mod 
            b = b // 2
        return ans
    def fermat(self, n, r, p):
        p = 1000003
        # Code here
        if n < r:
            return 0
        if r == 0 or n == r:
            return 1
        if r == n-1 or r == 1:
            return n
        num = den = 1
        if r > n - r:
            r = n - r
        for i in range(r):
            num = ((num % p) * ((n - i) % p)) % p
            den = ((den % p) * ((i + 1) % p)) % p
        return (num * self.bin_expo(den, p - 2, p)) % p
        
    def lucas(self, n, r, p):
        if r == 0:
            return 1
        ni = n % p
        ri = r % p
        return (self.lucas(n//p, r//p, p) * self.fermat(ni, ri, p)) % p

    def nCr(self, n, r):
        p = 1000003
        return self.lucas(n, r, p)