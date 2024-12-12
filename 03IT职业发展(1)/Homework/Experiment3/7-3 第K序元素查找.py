try :
    def main():
        l = eval(input())
        n = int(input())
        
        l.sort(reverse = True)
        
        print(l[n-1])
        
    main()
    
except:
    exit()