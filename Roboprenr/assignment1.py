# Assignment 1 - Check Armstrong

def checkArmstrong(num):
    totalDigits = len(str(num))
    temp = num
    sum = 0
    while temp > 0:
        digit = temp % 10
        sum += digit ** totalDigits
        temp //= 10
    
    if num == sum:
        return True
    else:
        return False

num = int(input())
print(checkArmstrong(num))
