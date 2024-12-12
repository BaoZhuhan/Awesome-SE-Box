userInput = str(input())

userChar = userInput[-1]
userNum = int(userInput[:-1])

if userNum < 1 or userNum > 17 or (not userChar in "ABCDEF") :
    print("输入错误")
elif userChar in "AF":
    print("窗口")
elif userChar in "CD":
    print("过道")