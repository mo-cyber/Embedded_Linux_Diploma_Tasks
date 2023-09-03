test1 = [1,2,3,3,5]
test2 = [1,2,3,4,5]
test3 = [1,2,3,4,4]

count = 0
for i in test1:
    if(i == 4):
        count+=1
    else:
        continue
print("Number of occurence = ",count)