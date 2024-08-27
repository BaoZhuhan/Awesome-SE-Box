userInput = float(input())
total = userInput-3500 if userInput-3500 > 0 else 0

tax = 0
if total > 80000 :
    tax = total*0.45-13505
elif total > 55000 :
    tax = total*0.35-5505
elif total > 35000 :
    tax = total*0.3-2755
elif total > 9000 :
    tax = total*0.25-1005
elif total > 4500 :
    tax = total*0.2-555
elif total > 1500 :
    tax = total*0.1-105
else :tax = total * 0.03

print("应缴税款{:.2f}元，实发工资{:.2f}元。".format(tax,userInput-tax))