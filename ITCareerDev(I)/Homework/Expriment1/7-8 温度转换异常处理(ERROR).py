try:
    def main():
        userInput = input()
        flag = userInput[-1]
        
        if (flag not in "CcFf") :
            print("输入错误，末位只能是'C','c','F','f'")
            exit()
        
        num = float(userInput[0:-1])
        
        if flag in "cC":
            print("{:.2f}F".format(num*1.8+32))
        else :
            print("{:.2f}C".format((num-32)/1.8))
    main()            


except NameError:
    print("试图访问的变量名不存在")
except SyntaxError:
    print("存在语法错误")
except Exception as e:
    print(e)