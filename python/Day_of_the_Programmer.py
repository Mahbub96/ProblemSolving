def isLeapYear(y):

    if(y >= 1700 and y <= 1917):
        if(y % 4 == 0):
            return True
        return False
    elif((y % 400 == 0) or y % 4 == 0 and y % 100 != 0):
        return True
    return False


def dayOfProgrammer(year):
    if(year == 1918):
        print("12.09."+str(year))
    elif(isLeapYear(year)):
        print("12.09."+str(year))
    else:
        print("13.09."+str(year))


dayOfProgrammer(int(input()))
