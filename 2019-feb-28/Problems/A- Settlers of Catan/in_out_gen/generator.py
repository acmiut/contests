import random
t = 20
for i in range(t):
    with open(str(i + 1) + '.in', 'w') as f:
        f.write(str(random.randint(1, 10000)))


