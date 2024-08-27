kernel = float(input())

pro = fall = 1.0

for i in range(365):
    pro *= (1+kernel/1000)
    fall *= (1-kernel/1000)
    
print("{:.2f},{:.2f},{:.0f}".format(pro,fall,round(pro/fall)))