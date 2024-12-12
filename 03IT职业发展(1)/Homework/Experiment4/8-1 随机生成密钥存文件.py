import random 

try :
    def newChar():
        key = random.randint(1,3)
        if key == 1 :
            return chr(ord("A") + random.randint(0,25))
        elif key == 2 :
            return chr(ord("a") + random.randint(0,25))
        elif key == 3 :
            return str(random.randint(0,9))
        
    def newPass():
        password = ""
        for i in range(4) :
            for j in range(6):
                password += newChar()
            if i != 3 :
                password += "-"
        
        return password               
    def main():
        f = open("key.txt","w")
        
        n = int(input())
        
        for i in range(n) :
            f.write(newPass())
            f.write("\n")
        
        f.close()
        return
    
    main()

except Exception as error:
    print(error)