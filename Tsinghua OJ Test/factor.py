import math
def getFactors(x, factorsCollection):
    amt = 2
    for i in range(2, x):
        if x%i == 0:
            amt+=1
    factorsCollection.append(amt)
            #factorsCollection.add(i)

# def getMedian(factorsCollectionSet):
#     factorsCollection = list(factorsCollectionSet)
#     midIndex = len(factorsCollection)//2
#     if(len(factorsCollection) % 2):
#         print(factorsCollection[midIndex])
#     else:
#         print((factorsCollection[midIndex]+factorsCollection[midIndex-1])/2)

factorsCollection = []
num = [int(i) for i in input().split()]
for i in range(3):
    getFactors(num[i], factorsCollection)
factorsCollection.sort()
print(factorsCollection[1])
#getMedian(factorsCollection)

