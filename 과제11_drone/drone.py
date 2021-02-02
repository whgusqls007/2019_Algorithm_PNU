import random as r
f = open("sampleData/6.inp", "w")
f.write("%d\n" % 20)
a = [0 for i in range(20)]
b = [[0 for _ in range(101)] for _ in range(101)]
while 1:
    h = r.randint(1, 20)
    if a[h - 1] == 1:
        continue
    else:
        a[h - 1] = 1
        if h == 1:
            w = 0
        else:
            w = r.randint(0, 10)
        while 1:
            x = r.randint(1, 100)
            y = r.randint(1, 100)
            if b[x][y] != 1:
                b[x][y] = 1
                break
        f.write("%d %d %d %d\n" % (h, w, x, y))
    if 0 in a:
        continue
    else:
        break
