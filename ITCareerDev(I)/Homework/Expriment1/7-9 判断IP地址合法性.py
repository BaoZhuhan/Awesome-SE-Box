IP = input().split(".")
if len(IP) != 4:
    print("No")
    exit()
for i in IP:
    try:
        if(255 < int(i) or 0 > int(i)):
            print("No")
            exit()
    except:
        print("No")
        exit()
print("Yes")