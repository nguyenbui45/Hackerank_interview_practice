def rotLeft(a, d):
    unit_arr = []
    a_prime_arra = []
    for i in range(d):
        unit_arr.append(a[i])
    
    for i in range(d,len(a)):
        a_prime_arra.append(a[i])
    
    for i in unit_arr:
        a_prime_arra.append(i)

    return a_prime_arra
