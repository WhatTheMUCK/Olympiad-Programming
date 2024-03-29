n, k, d = map(int, input().split())
remain = 0
end = True

for i in range(d):
    j = 0
    while j < 10 and (n * 10 + j) % k != 0:
        j += 1
    if j == 10:
        print("-1")
        exit()
    n = n * 10 + j
    if j == 0:
        remain = (d - 1) - i
        end = False
        break

if end:
    print(n)
else:
    print(n, end="")
    for i in range(remain):
        print("0", end="")
        
