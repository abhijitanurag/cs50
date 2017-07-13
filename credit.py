number=int(input("Number: "))

number1=number

length=0
d1=0
sum1=0
sum2=0
while True:
    d2=d1
    d1=number1%10
    number1=number1//10
    length=length+1
    if(length%2==0):
        sum3=0
        digit=2*d1
        while True:
            sum3=sum3+digit%10
            digit=digit//10
            if digit==0:
                break
        sum1=sum1+sum3
    else:
        sum2=sum2+d1
    
    if number1==0:
        break

d=d1*10+d2
if (sum1+sum2)%10==0:
    if (d==51 or d==52 or d==53 or d==54 or d==55):
        if length==16:
            print("MASTERCARD")
        else:
            print("INVALID")
       
    if (d==40 or d==41 or d==42 or d==43 or d==44 or d==45 or d==46 or d==47 or d==48 or d==49):
        if length==16 or length==13:
            print("VISA")
        else:
            print("INVALID")
        
    if d==34 or d==37:
        if length==15:
            print("AMEX")
        else:
            print("INVALID")
        
    else:
        print("INVALID")
else:
    print("INVALID")

    
        
    
