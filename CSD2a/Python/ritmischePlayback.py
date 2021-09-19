import asyncio 
import time
import simpleaudio as sa
import keyboard
import random

kick = sa.WaveObject.from_wave_file("samples/kick.wav")
schreeuw = sa.WaveObject.from_wave_file("samples/schreeuw.wav")

print("=================")
print("kies een sample!")
print("-----------------")
print("kies uit:")
print("    - schreeuw")
print("    - kick")
print("-----------------")
welkeSampleInput = input("")
if welkeSampleInput == "kick":
    welkeSample = kick
if welkeSampleInput == "schreeuw":
    welkeSample = schreeuw


print("--------------------------------------")
print("hoeveel keer wil je de sample spelen?")
print("--------------------------------------")
hoeveelKeerSpelen = input("")
hoeveelKeerSpelen = int(hoeveelKeerSpelen)

print("---------------------")
print("wat voor BPM kies je?")
print("---------------------")
BPMinput = input("")
BPMinput = int(BPMinput)
BPM = 60 / BPMinput

sample = []
print("------------------------")
print("Hoelang duurt je noot?")
print("Wil je dat zelf kiezen?")
print("typ ja of nee!")
print("------------------------")
zelfKiezen = input("")

if zelfKiezen == "ja":
    print("------------------------------")
    print("Kies uit:")
    print("kwart (4)| half (2) | heel (1)")
    print("------------------------------")
    i = 1
    while i < (1 + hoeveelKeerSpelen):
        print ("sample", i)
        keuze = input("")
        keuze = int(keuze)

        if(keuze == 4):
            sample.append(4)
        if(keuze == 2):
            sample.append(2)
        if(keuze == 1):
            sample.append(1)
        i += 1

if zelfKiezen == "nee":
    a = 1
    while a < (1 + hoeveelKeerSpelen):
        sample.append(random.randint(1,5))
        a += 1

async def seq():
    i = 1
    while i < (1 + hoeveelKeerSpelen):
        for i in sample:
            asyncio.create_task(asyncio.sleep(1))
            
            if welkeSampleInput == "kick":
                print("kick")
            if welkeSampleInput == "schreeuw":
                print("schreeuw")
                
            welkeSample.play()
            await asyncio.sleep(BPM/i)
            
        if i == (hoeveelKeerSpelen + 1): 
            welkeSample.wait_done()
        i += 1

asyncio.run(seq()) 




 

