def check_id(id):
    if len(id) != 18 : return False
    coef = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
    checklist = list("10X98765432")
    check = sum(int(id[i])*int(coef[i]) for i in range(17))
    
    return id[-1] == checklist[check%11]

id = input()
if check_id(id) :
    print("身份证号码校验为合法号码!")
else:
    print("身份证校验位错误!")