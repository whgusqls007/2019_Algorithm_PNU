from math import ceil


class Coordinate:
    x = y = z = 0

    def __init__(self):
        self.x, self.y, self.z = map(int, inp.readline().split())


def open_file():
    return open("markingData2/1.inp"), open("1.out", "w")


def distance(x1, y1, z1, x2, y2, z2, x3, y3, z3, t):
    if t >= 1:
        return ((x2 - x3) ** 2 + (y2 - y3) ** 2 + (z2 - z3) ** 2) ** 0.5
    elif 0 < t < 1:
        return ((-1 * (((x1 - x3) * (x2 - x1) + (y1 - y3) * (y2 - y1) + (z1 - z3) * (z2 - z1)) ** 2)
                / ((x2 - x1) ** 2 + (y2 - y1) ** 2 + (z2 - z1) ** 2))
                + (x1 - x3) ** 2 + (y1 - y3) ** 2 + (z1 - z3) ** 2) ** 0.5
    elif t <= 0:
        return ((x1 - x3) ** 2 + (y1 - y3) ** 2 + (z1 - z3) ** 2) ** 0.5


def solve(x1, y1, z1, x2, y2, z2, x3, y3, z3):
    location = (-1 * (((x1 - x3) * (x2 - x1)) + ((y1 - y3) * (y2 - y1)) + ((z1 - z3) * (z2 - z1)))
            / (((x2 - x1) ** 2) + ((y2 - y1) ** 2) + ((z2 - z1) ** 2)))
    return distance(x1, y1, z1, x2, y2, z2, x3, y3, z3, location)


if __name__ == "__main__":
    inp, out = open_file()
    A = Coordinate()
    B = Coordinate()
    P = Coordinate()
    inp.close()
    out.write("%s" %math.ceil(solve(A.x, A.y, A.z, B.x, B.y, B.z, P.x, P.y, P.z)))
    out.close()


'''import math
Inp_f = open("station.inp"); Out_f = open("station.out", 'w')
A_x, A_y, A_z, B_x, B_y, B_z, P_x, P_y, P_z = map(int, Inp_f.read().split())
Out_f.write("%d" %math.ceil((-1 * (((A_x - P_x) * (B_x - A_x) + (A_y - P_y) * (B_y - A_y) + (A_z - P_z) * (B_z - A_z)) ** 2) / ((B_x - A_x) ** 2 + (B_y - A_y) ** 2 + (B_z - A_z) ** 2) + ((A_x - P_x) ** 2 + (A_y - P_y) ** 2 + (A_z - P_z) ** 2)) ** 0.5))
Inp_f.close(); Out_f.close()'''


'''import math
inp = open("markingData2/9.inp")
out = open("9.out", "w")
A_x, A_y, A_z, B_x, B_y, B_z, P_x, P_y, P_z = map(int, inp.read().split())
inp.close()
i = 0
M = 9999999999
Length = 0
while i <= 1:
    S_x, S_y, S_z = i * B_x + (1 - i) * A_x, i * B_y + (1 - i) * A_y, i * B_z + (1 - i) * A_z
    Length = ((P_x - int(S_x)) ** 2 + (P_y - int(S_y)) ** 2 + (P_z - int(S_z)) ** 2) ** 0.5
    #Length = ((P_x - S_x) ** 2 + (P_y - S_y) ** 2 + (P_z - S_z) ** 2) ** 0.5
    if Length == 0:
        M = 0
        break
    if M > Length:
        M = Length

    if Length > M:
        break
    i += 0.001
#out.write("%d" %int(M))
print(math.ceil(M))
out.close()'''


'''def DQ(Start_x: int, Start_y: int, Start_z: int, End_x: int, End_y: int, End_z: int, x: int, y: int, z: int, l, count):
    i = s_x = s_y = s_z = location = flag = answer = length_temp = 0
    length = 100000000
    while i < 1.01:
        s_x_temp, s_y_temp, s_z_temp = i * Start_x + (1 - i) * End_x, i * Start_y + (1 - i) * End_y, i * Start_z + (1 - i) * End_z
        length_temp = ((P_x - int(s_x_temp)) ** 2 + (P_y - int(s_y_temp)) ** 2 + (P_z - int(s_z_temp)) ** 2) ** 0.5
        if length_temp == 0:
            return 0
        if abs(length_temp - length) < 0.01:
            flag = 1
            break
        if length_temp < length:
            length = length_temp
            s_x, s_y, s_z = int(s_x_temp), int(s_y_temp), int(s_z_temp)
            location = i
        if int(l) == int(length):
            count += 1
            if count == 3:
                flag = 1
                break
        if length_temp > length:
            break
        i += 0.25
    if flag == 1:
        if length_temp >= length:
            return length
        elif length_temp < length:
            return length_temp
    if 0.25 <= location <= 0.75:
        start_x = (location + 0.5) * Start_x + (1 - (location + 0.5)) * End_x
        start_y = (location + 0.5) * Start_y + (1 - (location + 0.5)) * End_y
        start_z = (location + 0.5) * Start_z + (1 - (location + 0.5)) * End_z
        end_x = (location - 0.5) * Start_x + (1 - (location - 0.5)) * End_x
        end_y = (location - 0.5) * Start_y + (1 - (location - 0.5)) * End_y
        end_z = (location - 0.5) * Start_z + (1 - (location - 0.5)) * End_z
        answer = DQ(int(end_x), int(end_y), int(end_z), int(start_x), int(start_y), int(start_z), int(s_x), int(s_y), int(s_z), length, count)
    elif location < 0.25:
        start_x = (location + 0.5) * Start_x + (1 - (location + 0.5)) * End_x
        start_y = (location + 0.5) * Start_y + (1 - (location + 0.5)) * End_y
        start_z = (location + 0.5) * Start_z + (1 - (location + 0.5)) * End_z
        end_x = End_x
        end_y = End_y
        end_z = End_z
        answer = DQ(int(end_x), int(end_y), int(end_z), int(start_x), int(start_y), int(start_z), int(s_x), int(s_y), int(s_z), length, count)
    elif location > 0.75:
        start_x = Start_x
        start_y = Start_y
        start_z = Start_z
        end_x = (location - 0.5) * Start_x + (1 - (location - 0.5)) * End_x
        end_y = (location - 0.5) * Start_y + (1 - (location - 0.5)) * End_y
        end_z = (location - 0.5) * Start_z + (1 - (location - 0.5)) * End_z
        answer = DQ(int(end_x), int(end_y), int(end_z), int(start_x), int(start_y), int(start_z), int(s_x), int(s_y), int(s_z), length, count)
    return answer


import math
inp = open("markingData2/3.inp")
out = open("5.out", "w")
A_x, A_y, A_z, B_x, B_y, B_z, P_x, P_y, P_z = map(int, inp.read().split())
inp.close()
print("%s" %math.ceil(DQ(B_x, B_y, B_z, A_x, A_y, A_z, 0, 0, 0, 0, 0)))
out.close()'''