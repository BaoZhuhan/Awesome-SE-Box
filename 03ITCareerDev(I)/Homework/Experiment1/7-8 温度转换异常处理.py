try:
    a = input()
    if a[-1] in "Ff":
        C = (eval(a[0:-1]) -32)/1.8
        print("{:.2f}C".format(C))
    elif a[-1] in "Cc":
        F = 1.8 * eval(a[0:-1]) + 32
        print("{:.2f}F".format(F))
    else:
        print("输入错误，末位只能是'C','c','F','f'")
except NameError:
    print('试图访问的变量名不存在')
except SyntaxError:
    print('存在语法错误')
except Exception as e:
    print(e)