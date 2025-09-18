import sys
print = sys.stdout.write

x = "100000 99999\n"

for i in range(0, 99999, 3):
    x += f'1 {i} {i + 2}\n'
    x += f'1 {i + 2} {i + 1}\n'
    x += f'1 {i + 1} {i + 3}\n'

print(x)