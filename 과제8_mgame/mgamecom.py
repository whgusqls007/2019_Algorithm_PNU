import time as t

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


def listadd(l1, l2):
    temp1 = []
    for i in range(len(l2)):
        for j in range(len(l1)):
            temp1.append(l1[j] + l2[i])
    return list(set(temp1))


def listsub(l1, l2):
    temp1 = []
    for i in range(len(l2)):
        for j in range(len(l1)):
            temp1.append(l1[j] - l2[i])
    return list(set(temp1))


def listmul(l1, l2):
    temp1 = []
    for i in range(len(l2)):
        for j in range(len(l1)):
            temp1.append(l1[j] * l2[i])
    return list(set(temp1))

def binaryadd(exp):
    if len(exp) == 1:
        return [int(exp[0])]
    elif len(exp) == 3:
        if exp[1] == "+":
            return [int(exp[0]) + int(exp[2])]
        elif exp[1] == "-":
            return [int(exp[0]) - int(exp[2])]
        elif exp[1] == "*":
            return [int(exp[0]) * int(exp[2])]
    '''elif len(exp) == 5:
        if exp[1] == "+" and exp[3] == "+":
            return [int(exp[0]) + int(exp[2]) + int(exp[4])]
        if exp[1] == "+" and exp[3] == '-':
            return [(int(exp[0]) + int(exp[2])) - int(exp[4]), int(exp[0]) + (int(exp[2]) - int(exp[4]))]
        if exp[1] == "+" and exp[3] == '*':
            return [(int(exp[0]) + int(exp[2])) * int(exp[4]), int(exp[0]) + (int(exp[2]) * int(exp[4]))]
        if exp[1] == "-" and exp[3] == "+":
            return [(int(exp[0]) - int(exp[2])) + int(exp[4]), int(exp[0]) - (int(exp[2]) + int(exp[4]))]
        if exp[1] == "-" and exp[3] == "-":
            return [(int(exp[0]) - int(exp[2])) - int(exp[4]), int(exp[0]) - (int(exp[2]) - int(exp[4]))]
        if exp[1] == "-" and exp[3] == "*":
            return [(int(exp[0]) - int(exp[2])) * int(exp[4]), int(exp[0]) - (int(exp[2]) * int(exp[4]))]
        if exp[1] == "*" and exp[3] == "+":
            return [int(exp[0]) * (int(exp[2]) + int(exp[4])), (int(exp[0]) * int(exp[2])) + int(exp[4])]
        if exp[1] == "*" and exp[3] == "-":
            return [int(exp[0]) * (int(exp[2]) - int(exp[4])), (int(exp[0]) * int(exp[2])) - int(exp[4])]
        if exp[1] == "*" and exp[3] == "*":
            return [int(exp[0]) * int(exp[2]) * int(exp[4])]'''

    temp, cal1, cal2 = [], [], []
    for i in range(1, len(exp),2):
        if len(exp[:i]) == 1:
            cal1 = [int(exp[i - 1])]
        else:
            cal1 = binaryadd(exp[:i])
        if len(exp[i+1:]) == 1:
            cal2 = [int(exp[i + 1])]
        else:
            cal2 = binaryadd(exp[i + 1:])
        if exp[i] == '+':
            temp = temp + listadd(cal1, cal2)
        elif exp[i] == '-':
            temp = temp + listsub(cal1, cal2)
        elif exp[i] == '*':
            temp = temp + listmul(cal1, cal2)
    return list(set(temp))


if __name__ == '__main__':
    output_answer(max(binaryadd(input_getexpression())))