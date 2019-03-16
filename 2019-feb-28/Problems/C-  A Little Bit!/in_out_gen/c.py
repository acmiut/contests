n = input()
z = [n.find('0'),0][n.find('0') == -1]
print(n[0:z] + n[z+1::])
