def check(year, month, day):
    birth = list(str(year * 10000 + month * 100 + day))
    return len(birth) == len(set(birth))

def main(year, month, day):
    while True:
        if check(year, month, day):
            print("小明的生日是{:.0f}年{:02}月{:02}日".format(year, month, day))
            break
        
        day -= 1
        if day == 0:
            month -= 1
            if month == 0:
                month = 12
                year -= 1
            day = 31  

        if year == 1000:
            break

main(2024, 8, 28)