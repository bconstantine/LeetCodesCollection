amountTest = int(input())
for _ in range(amountTest):
    amountNumber = int(input())
    NumCollections = {}
    maxDuplicate = 0
    maxDuplicateKey = -1
    inNumArr = list(map(int, input().split()))
    
    if(amountNumber < 2):
        print("0 0")
        continue
    for inNum in inNumArr:
        if inNum in NumCollections:
            NumCollections[inNum]+=1
        else:
            NumCollections[inNum]=1
        
        if(maxDuplicate < NumCollections[inNum]):
            maxDuplicate = NumCollections[inNum]
            maxDuplicateKey = inNum
        elif(maxDuplicate == NumCollections[inNum] and inNum > maxDuplicateKey):
            maxDuplicateKey = inNum

    if maxDuplicate > len(NumCollections):
        ans1 = len(NumCollections)
    elif maxDuplicate < len(NumCollections):
        ans1 = maxDuplicate
        NumCollections.pop(maxDuplicateKey)
    else:
        ans1 = maxDuplicate - 1
    ans2 = ans1*maxDuplicateKey
    
    keys = sorted(NumCollections.keys(), reverse=True)
    for rep in range(ans1):
        ans2 += keys[rep]

    print(f"{int(ans1)} {int(ans2)}")