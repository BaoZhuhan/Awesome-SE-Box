dict1 = {'小明': '13299887777', '特朗普': '814666888', '普京': '522888666', '吴京': '13999887777'}

name = input()
phone = input()

try :
    dict1[name]
    dict1[name] = phone
except :
    print("数据不存在")

for i in dict1.keys():
    print(i,end = ":")
    print(dict1[i])