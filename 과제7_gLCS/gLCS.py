def fileopen_getstring():
    inp = open("sampleData/1.inp")
    s1, s2 = "".join(input().split()), "".join(input().split())
    inp.close()
    return s1, s2


def fileopen_putstring(answer):
    out = open("gLCS.out", "w")
    #out.write("%s" % answer)
    print(answer)
    out.close()
    return


def LCS():

    def maketable():
        return [[0 for _ in range(len(string2) + 2)] for _ in range(len(string1) + 2)]

    def fill_table(a, b):
        return max(table[a - 1][b - 1], table[a - 2][b - 2], table[a - 1][b - 2], table[a - 2][b - 1]) + 1 \
                if string1[a - 2] == string2[b - 2] else 0

    def makeGLCS(a, b):
        if a < 2 or b < 2 or table[a][b] == 0: return ""
        temp_list = []
        for i in range(1, 3):
            for j in range(1, 3):
                if string1[a - 2] == string2[b - 2] and table[a][b] == table[a - i][b - j] + 1: temp_list.append(makeGLCS(a - i, b - j))
        return min(temp_list) + string1[a - 2] if temp_list else None

    table, string_list, tup, num = maketable(), [], [], 0
    for i in range(2, len(string1) + 2):
        for j in range(2, len(string2) + 2):
            table[i][j] = fill_table(i, j)
            if num < table[i][j]: num, tup = table[i][j], []
            if num == table[i][j]: tup.append((i, j))

    for i in range(len(tup)): string_list.append(makeGLCS(tup[i][0], tup[i][1]))
    return min(string_list) if string_list else None


if __name__ == "__main__":
    string1, string2 = fileopen_getstring()
    fileopen_putstring(LCS())