def cal(num):
    strNum = str(num)
    res = 0
    for i in strNum:
        res += pow(int(i),2)
    return res

def main():
    n = int(input())
    for i in range(100):
        n = cal(n)
        if n == 1: break
        
    if n == 1: print("True")
    else : print("False")
    
main()