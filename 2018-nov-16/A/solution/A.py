n = int(raw_input())

ans = 0
for i in range(n):
    s = raw_input()
    if s.find('AI') == -1:
        ans += 1
print ans
