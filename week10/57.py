def josephus(n, m):
    children = list(range(1, n+1))
    idx = 0
    while len(children) > 1:
        idx = (idx + m - 1) % len(children)
        children.pop(idx)
    return children[0]

# 读取输入
n, m = map(int, input().split())
result = josephus(n, m)
print(f"The left child is NO {result}.")