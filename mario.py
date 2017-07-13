

while True:
    height=int(input("Height:"))
    if height>=0 and height<=23:
        break
print("Height {}".format(height))
for i in range(height):
   
    for j in range(height-1,i,-1):
         print(" ",end="")
    for j in range(0,i+1,1):
        
        print("#",end="")
    print("  ",end="")
    for j in range(0,i+1,1):
        print("#",end="")
    print()
         