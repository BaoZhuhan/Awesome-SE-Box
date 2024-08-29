dic1 = {"张三":"123456","李四":"1234567","王五":"password"}

error_time = 0

while error_time < 3:
    username = input()
    userpass = input()

    if username in dic1.keys() and userpass == dic1[username] :
        print("登录成功")
        break
    else :
        print("登录失败")
        error_time += 1
