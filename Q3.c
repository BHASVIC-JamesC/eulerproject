import math
number = 6857
root = math.floor(math.sqrt(number))

if number%2 ==0:
    print("Not prime")

for i in range(root):
    if i%2==1:
        if number%i==0:
            print("Not prime")

#1=x
#71= :)
#839
#1471
#6857
#59569=x
#104441=x
#486847=x
#1234169=x
#5753023=x
#10086647=x
#87625999=x
#408464633=x
#716151937=x
#8462696833 = x