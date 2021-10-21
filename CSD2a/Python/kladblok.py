


# 7/8 = 4/4 + 3/4 

# input = 7/8







# als inpit = 4/4  

# dan BPM 1 hele = gedeeld door 4
# * 4 
import simpleaudio as sa
import random

bongo1 = sa.WaveObject.from_wave_file("samples_drumstel/bongo1.wav")


BPMHeel = (60.0 / 100) * 2  #= 1 hele noot  
BPMAcht = BPMHeel / 8            #= 1/8 noot


# wat voor maatsoort
print("================")
print("wat voor maatsoort wil je?")
maatsoortInput = int(input())








stempels = []

for stapje in (plekAchtje):
    rand3 = random.randint(1,100)
    if (rand3 <= 60):
        stempels.append(stapje)
        


print(stempels)


# plekkenHat = [1,2,3,4,5,6]
#     # kansvanhat|      70% | 50% | 75% | 50% | 70% | 100%
# kansHat = [70,50,75,50,60,100]
# for index, item in enumerate(kansHat):
#     rand20 = random.randint(1,100)
#     if (rand20 <= item):
#         stempels.append()
