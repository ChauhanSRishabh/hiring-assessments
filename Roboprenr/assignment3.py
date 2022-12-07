# Assignment 3 - Reverse Every Word

def reverseEveryWord(sentence):
    words = sentence.split(" ") # getting words from the sentence
    newWords = []
    for word in words:
        newWords.append(word[::-1]) # creating a list of new words by reversing each word
    
    result = " ".join(newWords) # joining all the new words to form the desired sentence
    return result
     

sentence = input()
result = reverseEveryWord(sentence)
print(result)