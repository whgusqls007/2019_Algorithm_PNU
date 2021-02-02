def input_getexpression():
    inp = open('sampleData/sample.inp')
    a = list("".join(inp.readline().split()))
    inp.close()
    return a


def output_answer(answer):
    out = open('mgame.out', 'w')
    print(answer)
    out.write("%d" % answer)
    out.close()
    return


def makeTable(n):
    T = [[[] for _ in range(n + 2)] for _ in range(n + 2)]
    for i in range(0, len(T) - 2, 2):
        T[i + 1][i + 1] = [int(expression[i])]
    i, j = 1, 3
    while 1:
        if expression[i] == '+':
            T[i][j] = [T[i][i][0] + T[j][j][0]]
        if expression[i] == '-':
            T[i][j] = [T[i][i][0] - T[j][j][0]]
        if expression[i] == '*':
            T[i][j] = [T[i][i][0] * T[j][j][0]]
        if len(T[len(expression)-2][len(expression)]) != 0:
            break
        i += 2
        j += 2
    return T


def cal(a, b):
    c = b
    for i in range(b - 2, a - 1, -2):
        if expression[i] == "+":
            for j in range(len(table[a][i])):
                for k in range(len(table[c][b])):
                    table[a][b] = table[a][b] + [table[a][i][j] + table[c][b][k]]
            c = c - 2
        if expression[i] == "-":
            for j in range(len(table[a][i])):
                for k in range(len(table[c][b])):
                    table[a][b] = table[a][b] + [table[a][i][j] - table[c][b][k]]
            c = c - 2
        if expression[i] == "*":
            for j in range(len(table[a][i])):
                for k in range(len(table[c][b])):
                    table[a][b] = table[a][b] + [table[a][i][j] * table[c][b][k]]
            c = c - 2
    table[a][b] = list(set(table[a][b]))
    if len(table[a][b]) > 5:
        plus, minus, zero = [], [], 1
        for i in range(len(table[a][b])):
            if table[a][b][i] > 0:
                plus.append(table[a][b][i])
            if table[a][b][i] < 0:
                minus.append(table[a][b][i])
            if table[a][b][i] == 0:
                zero = 0
        table[a][b] = []
        if len(plus) != 0 and len(plus) > 2:
            table[a][b] = table[a][b] + [max(plus),min(plus)]
        else:
            table[a][b] = table[a][b] + plus
        if len(minus) != 0 and len(minus) > 2:
            table[a][b] = table[a][b] + [max(minus), min(minus)]
        else:
            table[a][b] = table[a][b] + minus
        if zero == 0:
            table[a][b] = table[a][b] + [0]
    list(set(table[a][b]))


def maximum():
    j = 4
    while 1:
        for i in range(1, len(table), 2):
            if i + j >= len(expression) + 2:
                break
            cal(i, i+j)

        j = j + 2
        if len(table[1][len(expression)]) != 0:
            break


if __name__ == "__main__":
    expression = input_getexpression()
    table = []
    table = makeTable(int(len(expression)))
    maximum()
    output_answer(max(table[1][len(expression)]))