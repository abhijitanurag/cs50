import sys
if len(sys.argv)!=2:
    print("please provide proper arguments")
    exit(1)
i=0
j=0
inc=int(sys.argv[1])
plain_text=input("plaintext:")
cipher_text=plain_text
if plain_text!=None:
    while True:
        if (i==len(plain_text)):
            break
        if plain_text[i].isalpha():
            if plain_text[i].isupper():
                character=(ord(plain_text[i])-65+inc)%26+65
                
                plain_text=plain_text.replace(plain_text[i],chr(character),1)
            else:
                character=(ord(plain_text[i])-97+inc)%26+97
                
                plain_text=plain_text.replace(plain_text[i],chr(character),1)
        
        i=i+1
        
print("ciphertext: {}".format(plain_text))
exit(0)
