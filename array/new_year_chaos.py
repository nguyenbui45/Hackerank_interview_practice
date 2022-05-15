

def minimumBribes(q):
    min_bribe = 0
    for i in range(0,len(q)):
        # print(q[i] - (i +1))
        if (q[i] - (i +1)) > 2:
            return "Too chaotic"
        for j in q[max(q[i]-2,0):i]:
            if j > q[i]:
                min_bribe +=1
        
    return min_bribe

