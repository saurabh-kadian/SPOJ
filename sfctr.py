t = int(input())
temp = 1
arr = []
for k in range(1,101):
    temp *= k
    arr.append(temp)
for i in range(0,t):
    n = int(input())
    print(arr[n-1])
