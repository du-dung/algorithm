'''
9095. 1,2,3 더하기 Silver 3
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램
https://www.acmicpc.net/problem/9095
-> DP
v01: 18.09.26
'''

#
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
