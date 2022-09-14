# Given a date in "YYYYMMDD" format, convert it into "Month name-Day-Year" format, eg : February 17, 2009

def printDate(date):
    # Coverting date in integer to string
    date_string = str(date)
    # Slicing string to get year, month and date
    year = int(date_string[0:4])
    month = int(date_string[4:6])
    day = int(date_string[6:8])

    months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]

    if month in range(1,13):
        # Case for February in a normal year
        if(month == 2 and day <= 28):
            datemonth = months[month-1]
            print( datemonth + " " + str(day) + "," + " " + str(year))
            return
        
        # Case for February in leap year
        elif(month == 2 and day == 29):
            if(year%4 == 0):
                datemonth = months[month-1]
                print( datemonth + " " + str(day) + "," + " " + str(year))
                return
            else:
                print("Invalid Date")
                return

        # Case for August
        elif(month == 8 and day <= 31): 
            datemonth = months[month-1]
            print( datemonth + " " + str(day) + "," + " " + str(year))
            return
        
        # Case for other months
        elif(month%2 == 1 and day <= 31):
            datemonth = months[month-1]
            print( datemonth + " " + str(day) + "," + " " + str(year))
            return
        elif (month%2 == 0 and day <= 30):
            datemonth = months[month-1]
            print( datemonth + " " + str(day) + "," + " " + str(year))
            return
        else:
            print("Invalid Date")
            return
    else:
        print("Invalid Date")
        return


printDate(20200816)
printDate(20200431)
printDate(19860121)
printDate(20210229)
