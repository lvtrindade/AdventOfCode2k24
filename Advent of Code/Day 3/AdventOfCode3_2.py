from re import findall
d = "do()" + open(r"C:\Users\Lucas\Documents\Advent of Code\Day 3\input.txt").read().replace('\n',' ') + "don't()"
for _ in 1, 2:
    print(sum(int(x)*int(y) for x,y in findall(r"mul\((\d+),(\d+)\)", d)))
    d = "".join(findall(r"do\(\)(.*?)don't\(\)", d))