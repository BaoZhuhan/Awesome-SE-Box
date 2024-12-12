from datetime import datetime
someday = datetime(2022,10,1)


def main():
    id = input()
    yy = int(id[6:10])
    mm = int(id[10:12])
    dd = int(id[12:14])
    
    age = someday.year - yy
    
    xb = "男" if int(id[16])%2 == 1 else "女"
    
    print("你出生于{:04}年{:02}月{:02}日".format(yy,mm,dd))
    print("你今年{}周岁".format(age))
    print("你的性别为{}".format(xb))

main()
    