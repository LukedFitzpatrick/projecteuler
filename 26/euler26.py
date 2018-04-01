from decimal import *
import re

biggest = 0
biggestI = 0
    

getcontext().prec = 10000
for i in range(2, 1000):
    result = str(Decimal(1)/Decimal(i))
    decimalPart = re.search(r'\.(.*)', result).group(1)

    # detect cycles of length n

    numIterationsToCheck = 3

    
    for cycleLength in range(1, 10000):
        stillGoing = True
        for iteration in range(0, numIterationsToCheck):
            stillGoing = decimalPart[iteration*cycleLength:(iteration+1)*cycleLength] == decimalPart[(iteration+1)*cycleLength:(iteration+2)*cycleLength]
            if not stillGoing: break

        if stillGoing:
            #print cycleLength, i, result

            if(int(cycleLength) > int(biggest)):
                biggest = cycleLength
                biggestI = i
                print "biggest: ", biggest
                print "biggesti: ", biggestI
            break

