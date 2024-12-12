garbage = ["垃圾","陷阱","山寨","内幕","盗版"]
userInput = str(input())

for i in garbage:
    loc = userInput.find(i)
    while(not loc == -1):
        userInput = userInput[0:loc] + "*" + userInput[loc+len(i):-1]
        loc = userInput.find(i)


print(userInput)