def updateOrGetVector(mem, requiredNumber):
    if(len(mem) < requiredNumber):
        #update mem until the required amount
        for nextNumber in range(len(mem)+1, requiredNumber+1):
            maxAmt = 10000000000000000000000000
            if(nextNumber % 2 == 0):
                idx = (nextNumber // 2) - 1
                if(mem[idx] != -1):
                    maxAmt = min(maxAmt, mem[idx]+1)
                
            
            if(nextNumber*2 % 3 == 0):
                idx = (nextNumber*2 // 3) - 1
                if(mem[idx] != -1):
                    maxAmt = min(maxAmt, mem[idx]+1)
                
            
            if(nextNumber*4 % 5 == 0):
                idx = (nextNumber*4 // 5) - 1
                if(mem[idx] != -1):
                    maxAmt = min(maxAmt, mem[idx]+1)
                
            
            if(nextNumber*6 % 7 == 0):
                idx = (nextNumber*6 // 7) - 1
                if(mem[idx] != -1):
                    maxAmt = min(maxAmt, mem[idx]+1)
                
            
            if(maxAmt == 10000000000000000000000000):
                maxAmt = -1
            
            mem.append(maxAmt)
        
    return mem[requiredNumber - 1]

def getAnsWithoutMemoization(ans):
    if(ans < 1):
        return -1
    count = 0
    if ans == 1:
        return count
    while(ans > 1):
        if ans % 2 == 0:
            ans //= 2
        elif ans % 3 == 0:
            ans //= 3
            count +=1
        elif ans % 5 == 0:
            ans //= 5
            count += 2
        elif ans % 7 == 0:
            ans //= 7
            count += 3
        else:
            return -1
        count += 1

    if ans == 1:
        return count
    else:
        return -1
    #return count

testAmt = int(input())
for _ in range(testAmt):
    interestNumber = int(input())
    print(getAnsWithoutMemoization(interestNumber), end="\n")
    
    