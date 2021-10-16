import random



list1 = [1,2,3,4,5,6,7,8]
list2 = ["p","o","e","p","s","o","e","p"]

# for index, item in enumerate(list1):
#     # print(list1[index])
#     # print(list2[index])


def event_stamps(welkBlok,plek):
    return{
        "welkBlok" : welkBlok,
        "plek" : plek,   
    }

stempels = []
plekkenHat = [1,2,3,4,5,6]
    # kansvanhat|      70% | 50% | 75% | 50% | 70% | 100%
kansHat = [70,50,75,50,70,100]
for index, item in enumerate(kansHat):
    # print(item)
    rand20 = random.randint(1,100)
    if (rand20 <= item):
        stempels.append(event_stamps("vijf",index+1))
print(stempels)