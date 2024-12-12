gpaList = ["A" , "A-" , "B+" , "B" , "B-" , "C+" , "C" , "C-" , "D" , "D-" , "F"]
sorceList = [4.0,3.7,3.3,3.0,2.7,2.3,2.0,1.5,1.3,1.0,0]

def debug():
    print(len(gpaList) , len(sorceList))

def main():
    userInput = input()
    userScore = userWeight = 0
        
    while(userInput != "-1"):
        weight = int(input())
        userWeight += weight
        
        if userInput not in gpaList :
            print("data error")
            exit()
        else:
            userScore += sorceList[gpaList.index(userInput)] * weight

        userInput = input()

    print("{:.2f}".format(userScore/userWeight))
    

main()