# Assignment 2 - Spy Game

def spy_game(list_of_numbers):
    order = [0,0,7]
    for number in list_of_numbers:
        if number == order[0]:
            order.pop(0)
            if len(order) == 0: 
                return True    
    return False


# list_of_numbers = [1,2,4,0,0,7,5]
# list_of_numbers = [1,0,2,4,0,5,7]
list_of_numbers = [1,7,2,0,4,5,0]

print(spy_game(list_of_numbers))