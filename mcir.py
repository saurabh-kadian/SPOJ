t = int(input())
while t != -1:
    dict = {}
    def f(n):
        # print(n)
        if n == 2 or n == 0:
            return 1
        if n in dict:
            return dict[n]
        leftSide = n - 2
        rightSide = 0
        answer = 0
        while rightSide != n:
            answer += f(leftSide) * f(rightSide)
            leftSide -= 2
            rightSide += 2
        dict[n] = answer
        return answer
    print(f(2 * t))
    t = int(input())
