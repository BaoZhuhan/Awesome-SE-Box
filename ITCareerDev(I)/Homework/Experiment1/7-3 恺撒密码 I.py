userInput = list(input())

for i in range(len(userInput)):
    if 'a' <= userInput[i] <= 'z':
        userInput[i] = chr((ord(userInput[i]) - ord('a') + 3 )%26 + ord('a'))
        
print("".join(userInput)) 