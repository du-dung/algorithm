#input
t=int(input())
n=list()

for i in range(t):
    tmp=int(input())
    n.append(tmp)

ans=[0,1,2,4]
for i in range(4,11):
    ans.append(ans[i-1]+ans[i-2]+ans[i-3])

#output
for i in n:
    print(ans[i])
