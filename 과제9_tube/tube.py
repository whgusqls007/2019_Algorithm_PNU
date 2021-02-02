def Fin():  # 입력 부분
    inp = open("sampleData/3.inp")
    L_temp, K_temp, l_temp = int(inp.readline()), int(inp.readline()), list(map(int, inp.readline().split()))
    inp.close()
    return L_temp, K_temp, l_temp


def Fout(answer):  # 출력 부분
    out = open("4.out", "w")
    print(answer)
    out.write("%d" % answer)
    out.close()
    return


def least_tube():  # 최소 개수 계산부분
    num_of_tube = [100001] * (L + 1)  # 만들 길이만큼의 리스트 선언해주고 최대값이 100000 이므로 100001 으로 초기화 시킨다.
    num_of_tube[0] = 0  # 0으로는 만들수 있는 파이프가 없으므로 0으로 초기화 시켜준다.
    for i in range(K):  # 튜브의 개수만큼 for문을 돈다.
        for j in range(tube[i], len(num_of_tube)):  # tube[i] 의 원소 부터 만들 길이 까지 for문을 돈다.
            num_of_tube[j] = min(num_of_tube[j], num_of_tube[j-tube[i]] + 1)
            # [j] 에 [j]의 현재 값과 [j-tube[i]] + 1] 값중 작은 값을 넣는다.
            # [j-tube[i]]에는 tube[i]를 더하기 이전의 파이프 개수이다.
    return num_of_tube[-1] if num_of_tube[-1] != 100001 else 0
    # 만약 마지막 원소가 100001이 아니라면 최소값이 있다는 뜻이므로 마지막 원소 리턴
    # 100001이면 최소값을 구할수 없다는 뜻이므로 0을 리턴


if __name__ == "__main__":
    L, K, tube = Fin()
    Fout(least_tube())
