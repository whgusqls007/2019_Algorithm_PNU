def inputData():
    inp = open("detroit.inp")
    N = int(inp.readline())
    arr = [[[] for _ in range(N)] for _ in range(N)]
    for i in range(N):
        temp = list(map(int, "".join(inp.readline().split())))
        for j in range(N):
            if temp[j] == 0:
                arr[i][j] = []
            else:
                arr[i][j] = [temp[j]]
    inp.close()
    for i in range(N):
        for j in range(N):
            if not arr[i][j]:
                temp = [i + 1 for i in range(N)]
                for k in range(N):
                    if arr[i][k] and len(arr[i][k]) == 1:
                        if arr[i][k][0] in temp:
                            temp.remove(arr[i][k][0])
                    if arr[k][j] and len(arr[k][j]) == 1:
                        if arr[k][j][0] in temp:
                            temp.remove(arr[k][j][0])
                arr[i][j] = temp
    return arr


def outputData(answer):
    out = open("detroit.out", "w")
    out.write("%d" % answer)
    out.close()
    return


def put_topping(pizza, number, a, b):
    if b == len(pizza):
        a += 1
        b = 0
    if a == len(pizza) and b == 0:
        return number + 1
    if len(pizza[a][b]) == 1:
        number = put_topping(pizza, number, a, b + 1)

    temp = pizza[a][b].copy()
    temp2 = temp.copy()
    while 1:
        if not temp:
            pizza[a][b] = temp2
            return number
        for i in range(len(pizza)):
            if len(pizza[a][i]) == 1:
                if pizza[a][i][0] in temp:
                    temp.remove(pizza[a][i][0])
            if len(pizza[i][b]) == 1:
                if pizza[i][b][0] in temp:
                    temp.remove(pizza[i][b][0])
        for i in range(len(temp)):
            pizza[a][b] = [temp[i]]
            number = put_topping(pizza, number, a, b + 1)
        temp = []


if __name__ == "__main__":
    outputData(put_topping(inputData(), 0, 0, 0))