def main():
    userInput = list(input())
    lowLetter = CapLetter = num = blank = other = 0
    for i in userInput:
        if 'a' <= i <= 'z' : lowLetter += 1
        elif 'A' <= i <= 'Z' : CapLetter += 1
        elif '0' <= i <= '9' : num += 1
        elif i == ' ' : blank += 1
        else: other += 1
    
    print(lowLetter,CapLetter,num,blank,other)
    
main()
    