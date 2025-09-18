import sys
print = sys.stdout.write

x = "100000 99996\n"

for i in range(0, 99996, 4):
    x += f'1 {i} {i + 2}\n'
    x += f'1 {i + 2} {i + 1}\n'
    x += f'1 {i + 1} {i + 4}\n'
    x += f'0 {i + 3} {i + 3}\n'

print(x)