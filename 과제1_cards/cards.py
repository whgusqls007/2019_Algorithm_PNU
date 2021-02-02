'''def cal(inp_f):
    n = int(inp_f.readline()) - 2
    a = int(((n + 2) * (n + 3)) / 2)
    b = c = 1
    for i in range(1, n + 3):
        b = b * i
        if i < n + 1:
            card = int(inp_f.readline())
            a = a - card
            c = c * card
    return a, b, c


def result(a, b, c):
    out_f = open("cards.out", 'w')
    for num in range(1, int(a / 2) + 1):
        if num * (a - num) * c == b:
            out_f.write("%d\n" % num)
            out_f.write("%d" % (a - num))
            break
    out_f.close()


if __name__ == "__main__":
    inp_f = open("cards.inp", 'r')
    Sum, All_mul, Mul = cal(inp_f)
    inp_f.close()
    result(Sum, All_mul, Mul)'''

Inp_f = open("sampledata/2.inp", "r")
A = int((Inp_f.readline()).splitlines()[0])
print(A)
B = [0 for _ in range(A-2)]
for i in range(A-2):
    B[i] = int((Inp_f.readline()).splitlines()[0])
B.sort()
print(B)