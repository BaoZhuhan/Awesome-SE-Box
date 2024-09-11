import math

def distance(x,y,z):
    return math.sqrt(x**2+y**2+z**2)

def main():
    x,y,z = input().split(",")
    d = distance(float(x),float(y),float(z))
    print("{:.2f}".format(d))
    
main()