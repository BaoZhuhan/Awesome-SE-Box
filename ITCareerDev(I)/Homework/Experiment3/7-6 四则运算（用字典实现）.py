try:
    def main():
        a = float(input())
        f = input()
        b = float(input())
        res = 0
        
        if f == "+" :
            res = a + b
        elif f == "-" :
            res = a - b
        elif f == "*" :
            res = a * b
        elif f == "/" :
            res = a / b

        print("{:.2f}".format(res))
    main()
except :
    print("divided by zero")