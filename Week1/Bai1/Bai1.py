
# Chia a cho b lấy kết qủa là phần nguyên 
# Xong 
def divide1( a, b):

    if(( a < 0 and b < 0 ) or (a > 0 and b > 0)):
        sign = 1
    else:
        sign = -1
    
    if(b == 0):
        print("Ban nhap sai , b phai khac 0")
        return 

    quotient = 0

    a = abs(a)
    b = abs(b)

    while ( a >= b):
        a = a - b
        quotient = quotient + 1
    
    print(sign*quotient)

def divide2(a, b):

    sign = 1
    if(( a < 0 and b < 0 ) or (a > 0 and b > 0)):
        sign = 1
    else:
        sign = -1
    
    if(b == 0):
        print("Ban nhap sai , b phai khac 0")
        return 


    mask = 1
    quotient = 0

    a =  abs(a)
    b = abs(b)

    while ( b <= a):
        b = b << 1
        mask = mask << 1

    while ( mask > 1):
        b = b >> 1
        mask = mask >> 1

        if ( a > b):
            a = a - b
            quotient = quotient | mask
		

    print(sign * quotient)
	

divide1(10, 3)
divide2(-10, 3)
divide1(0, 3)
divide2(0, 3)
divide1(1, 2)
divide2(3, 0)