

# iteratively calculate fibonacci
lastLastNumber = 0
lastNumber = 1

index = 2
while(True):
    currNumber = lastLastNumber + lastNumber

    stringForm = str(currNumber)
    print index, "len=", len(stringForm)

    lastLastNumber = lastNumber
    lastNumber = currNumber
    index += 1
