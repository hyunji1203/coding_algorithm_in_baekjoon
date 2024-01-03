N=int(input())
han = 99

if N < 100:
    han = N
else:
    for i in range(100, N+1):
        a=list(map(int,str(i)))
        if a[0]-a[1] == a[1]-a[2]:
            han+=1
            
print(han)        