def km(x,y):
    sizex=len(str(x))
    if len(str(x))==2:
        a=(str(x))[0];b=(str(x))[1];c=(str(y))[0];d=(str(y))[1]
        a=int(a);b=int(b);c=int(c);d=int(d)
        result=100*(a*c)+10*(a*d+b*c)+b*d
        return result
    else:
        #Devide x,y to two
        #create new x,y
        xa=(str(x))[0:sizex/2]
        xb=(str(x))[sizex/2:sizex]
        yc=(str(y))[0:sizex/2]
        yd=(str(y))[sizex/2:sizex]
        print xa,xb,yc,yd
        xa=int(xa);xb=int(xb);yc=int(yc);yd=int(yd)
        return 10**sizex*km(xa,yc)+10**((sizex)/2)*(km(xa,yd)+km(xb,yc))+km(xb,yd)
##x=input() 02884197169399375105820974944592
##y=input() 62497757247093699959574966967627
   
x=3141592653589793238462643383279502884197169399375105820974944592
y=2718281828459045235360287471352662497757247093699959574966967627
final_result=km(x,y)
print final_result