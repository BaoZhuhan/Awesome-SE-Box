def check(l):
    for i in range(len(l)):
        if l[i] in l[i+1::] : 
            return True
    return False

str = input()
l = eval(str)
if check(l) : 
    print("True")
else :
    print("False")
