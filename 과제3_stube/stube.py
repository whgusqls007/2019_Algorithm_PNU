#과제 2번 예시코드를 사용하였습니다.

import math as m
import random
import sys
sys.setrecursionlimit(10 ** 8)

class Coordinate:
    x = y = z = 0

    def __init__(self, inp):
        self.x, self.y, self.z = map(int, inp.readline().split())


def dist(x1, y1, z1, x2, y2, z2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2 + (z1 - z2) ** 2) ** 0.5


def mid(x1, y1, z1, x2, y2, z2, x3, y3, z3):
    sx, sy, sz = (x1 + x2) / 2, (y1 + y2) / 2, (z1 + z2) / 2
    dap = dist(x1, y1, z1, x3, y3, z3)
    dbp = dist(x2, y2, z2, x3, y3, z3)
    if round(dap, 8) == round(dbp, 8):
        return dist(sx, sy, sz, x3, y3, z3)
    elif dap > dbp:
        return mid(sx, sy, sz, x2, y2, z2, x3, y3, z3)
    elif dap < dbp:
        return mid(x1, y1, z1, sx, sy, sz, x3, y3, z3)


def pickSP(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4):
    i = l = px = py = pz = 0
    arr = []
    least = 10000000
    while i < 1.01:
        tpx, tpy, tpz = i * x1 + (1 - i) * x2, i * y1 + (1 - i) * y2, i * z1 + (1 - i) * z2
        d = mid(x3, y3, z3, x4, y4, z4, tpx, tpy, tpz)
        arr.append(d)
        if least > d:
            least = d
            px, py, pz = tpx, tpy, tpz
            l = i
        i += 0.25
    if min(arr) == 0:
        return 0
    if round(min(arr), 3) == round(max(arr), 3):
        return least
    if l == 1:
        sx, sy, sz = 0.75 * x1 + 0.25 * x2, 0.75 * y1 + 0.25 * y2, 0.75 * z1 + 0.25 * z2
        return pickSP(sx, sy, sz, px, py, pz, x3, y3, z3, x4, y4, z4)
    elif l == 0.75:
        sx, sy, sz = 0.5 * x1 + 0.5 * x2, 0.5 * y1 + 0.5 * y2, 0.5 * z1 + 0.5 * z2
        return pickSP(sx, sy, sz, x1, y1, z1, x3, y3, z3, x4, y4, z4)
    elif l == 0.5:
        sx1, sy1, sz1 = 0.25 * x1 + 0.75 * x2, 0.25 * y1 + 0.75 * y2, 0.25 * z1 + 0.75 * z2
        sx2, sy2, sz2 = 0.75 * x1 + 0.25 * x2, 0.75 * y1 + 0.25 * y2, 0.75 * z1 + 0.25 * z2
        return pickSP(sx1, sy1, sz1, sx2, sy2, sz2, x3, y3, z3, x4, y4, z4)
    elif l == 0.25:
        sx, sy, sz = 0.5 * x1 + 0.5 * x2, 0.5 * y1 + 0.5 * y2, 0.5 * z1 + 0.5 * z2
        return pickSP(x2, y2, z2, sx, sy, sz, x3, y3, z3, x4, y4, z4)
    elif l == 0:
        sx, sy, sz = 0.25 * x1 + 0.75 * x2, 0.25 * y1 + 0.75 * y2, 0.25 * z1 + 0.75 * z2
        return pickSP(px, py, pz, sx, sy, sz, x3, y3, z3, x4, y4, z4)


def Input():
    return open("stube/sampleData/9.inp"), open("stube.out", "w")


#if __name__ == "__main__":
while 1:
    inp1 = open("stube/sampleData/9.inp", "w")
    a = random.sample(range(-10, 10), 3)
    b = random.sample(range(-10, 10), 3)
    c = random.sample(range(-10, 10), 3)
    d = random.sample(range(-10, 10), 3)
    for i in a:
        inp1.write("%d " % i)
    inp1.write("\n")
    for i in b:
        inp1.write("%d " % i)
    inp1.write("\n")
    for i in c:
        inp1.write("%d " % i)
    inp1.write("\n")
    for i in d:
        inp1.write("%d " % i)
    inp1.write("\n")
    inp1.close()
    inp, out = Input()
    A = Coordinate(inp)
    B = Coordinate(inp)
    C = Coordinate(inp)
    D = Coordinate(inp)
    inp.close()
    ab_to_cd = pickSP(C.x, C.y, C.z, D.x, D.y, D.z, A.x, A.y, A.z, B.x, B.y, B.z)
    cd_to_ab = pickSP(A.x, A.y, A.z, B.x, B.y, B.z, C.x, C.y, C.z, D.x, D.y, D.z)
    if ab_to_cd is None or cd_to_ab is None:
        out.write("0")
    print(min(ab_to_cd, cd_to_ab))
    print(m.ceil(min(ab_to_cd, cd_to_ab)))
    if min(ab_to_cd, cd_to_ab) < 0.001:
        print("0")
        break
    else:
        print("%s" % m.ceil(min(ab_to_cd, cd_to_ab)))


'''def distance(x1, y1, z1, x2, y2, z2, x3, y3, z3, l):
    if l >= 1:
        return ((x2 - x3) ** 2 + (y2 - y3) ** 2 + (z2 - z3) ** 2) ** 0.5
    elif 0 < l < 1:
        return ((-1 * (((x1 - x3) * (x2 - x1) + (y1 - y3) * (y2 - y1) + (z1 - z3) * (z2 - z1)) ** 2)
                     / ((x2 - x1) ** 2 + (y2 - y1) ** 2 + (z2 - z1) ** 2))
                    + (x1 - x3) ** 2 + (y1 - y3) ** 2 + (z1 - z3) ** 2) ** 0.5
    elif l <= 0:
        return ((x1 - x3) ** 2 + (y1 - y3) ** 2 + (z1 - z3) ** 2) ** 0.5


def location(x1, y1, z1, x2, y2, z2, x3, y3, z3):
    l = (-1 * (((x1 - x3) * (x2 - x1)) + ((y1 - y3) * (y2 - y1)) + ((z1 - z3) * (z2 - z1)))
             / (((x2 - x1) ** 2) + ((y2 - y1) ** 2) + ((z2 - z1) ** 2)))
    return distance(x1, y1, z1, x2, y2, z2, x3, y3, z3, l)


def dist(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4):
    x5, y5, z5 = 0.5 * x3 + 0.5 * x4, 0.5 * y3 + 0.5 * y4, 0.5 * z3 + 0.5 * z4
    x6, y6, z6 = 0.25 * x3 + 0.75 * x4, 0.25 * y3 + 0.75 * y4, 0.25 * z3 + 0.75 * z4
    x7, y7, z7 = 0.75 * x3 + 0.25 * x4, 0.75 * y3 + 0.25 * y4, 0.75 * z3 + 0.25 * z4
    abc = location(x1, y1, z1, x2, y2, z2, x3, y3, z3)
    abp1 = location(x1, y1, z1, x2, y2, z2, x6, y6, z6)
    abp2 = location(x1, y1, z1, x2, y2, z2, x5, y5, z5)
    abp3 = location(x1, y1, z1, x2, y2, z2, x7, y7, z7)
    abd = location(x1, y1, z1, x2, y2, z2, x4, y4, z4)
    if abc == 0 or abd == 0 or abp1 == 0 or abp2 == 0 or abp3 == 0:
        return 0
    if round(abc, 2) == round(abp1, 2) and round(abc, 2) == round(abd, 2):
        return abp1
    if abc < abp1 and abc < abp2 and abc < abp3 and abc < abd:
        return dist(x1, y1, z1, x2, y2, z2, x7, y7, z7, x3, y3, z3)
    elif abp1 < abc and abp1 < abp2 and abp1 < abp3 and abp1 < abd:
        return dist(x1, y1, z1, x2, y2, z2, x4, y4, z4, x5, y5, z5)
    elif abp2 < abc and abp2 < abp1 and abp2 < abp3 and abp2 < abd:
        return dist(x1, y1, z1, x2, y2, z2, x7, y7, z7, x6, y6, z6)
    elif abp3 < abc and abp3 < abp1 and abp3 < abp2 and abp3 < abd:
        return dist(x1, y1, z1, x2, y2, z2, x5, y5, z5, x3, y3, z3)
    elif abd < abc and abd < abp1 and abd < abp2 and abd < abp3:
        return dist(x1, y1, z1, x2, y2, z2, x4, y4, z4, x6, y6, z6)'''