import random

t = 50
for tc in range(t):
    with open(str(tc + 1) + '.in', 'w') as f:
        n = random.randint(1, 1000)
        f.write(str(n) + '\n')
        for i in range(n):
            l = []
            for j in range(4):
                l.append(str(random.randint(0, 100)))
            f.write(' '.join(l) + '\n')

