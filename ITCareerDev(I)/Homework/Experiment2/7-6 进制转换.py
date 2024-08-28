num = ["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F","G"]

def getSign(a):
    return "-" if str(a)[0] == "-" else ""

def getString(absA, b):
    if absA == 0:
        return "0"
    res = ""
    while absA != 0:
        res = num[absA % b ] + res
        absA //= b
    return res

a = int(input())
b = int(input())
mark = getSign(a)
bitString = getString(abs(a), b)
print(mark + bitString)