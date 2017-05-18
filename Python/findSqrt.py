
def findSqrt(n):
    eps = 10^-14
    x = n;     # Initial guess

    for i in range(100):
        z = n / x
        
        if abs(x - z) < eps:
            break

        x = 0.5 * (x + z)
    
    return x
    
if __name__ == "__main__":
    print findSqrt(9)
    