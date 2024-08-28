dic={"A":4.0,"A-":3.7,"B+":3.3,"B":3.0,"B-":2.7,"C+":2.3,"C":2.0,"C-":1.5,"D":1.3,"D-":1.0,"F":0}
sum=0
cdt=0

while True:
    n=input()
    
    if n=="-1":
        print("{:.2f}".format(sum/cdt))
        exit()
    if n in dic.keys():
        m=eval(input())
        cdt+=m
        sum+=dic[n]*m
    else:
        print("data error")
        exit()   
