

def s(food_times, k):
    answer = 0
    
    arr = [[f, idx+1] for idx, f in enumerate(food_times)]
    arr.sort()
    
    b = c = i = 0
    l = len(food_times)
    loop = 0
    
    for idx in range(len(arr)):
        c += (arr[idx][0] - loop) * l
        l -= 1
        loop = arr[idx][0]
        if c > k:
            i = idx
            break
        b = c
        
    n = sorted(arr[i:], key = lambda x: x[1])
    #print(i,n,k,b)
    k -= b
    k %= len(n)
    #print(k)

    return n[k][1]