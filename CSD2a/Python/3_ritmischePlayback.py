# importeer functies die ik nodig ga hebben voor de opdracht
import asyncio 
import time
import simpleaudio as sa
import keyboard
import random


# importeer samples en geef de samples namen
kick = sa.WaveObject.from_wave_file("samples/kick.wav")
schreeuw = sa.WaveObject.from_wave_file("samples/schreeuw.wav")


# als eerst kies ik een sample die in de sequencer gaat.
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


# kies nu hoeveel noten er in de sequenser zitten
print("--------------------------------------")
print("hoeveel keer wil je de sample spelen?")
print("--------------------------------------")
hoeveelKeerSpelen = input("")
hoeveelKeerSpelen = int(hoeveelKeerSpelen)

# kies een BPM
print("---------------------")
print("wat voor BPM kies je?")
print("---------------------")
BPMinput = input("")
BPMinput = int(BPMinput)
BPM = 60 / BPMinput

# dit is de input voor het kiezen tussen een random nootduur of nootduur die je zelf kiest
sample = []
print("------------------------")
print("Hoelang duurt je noot?")
print("Wil je dat zelf kiezen?")
print("typ ja of nee!")
print("------------------------")
zelfKiezen = input("")

# hier maakt python de keuze
# bij JA zul je voor elke stap in de sequence een nootduur
# bij NEE zal de nootduur random zijn
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

# de loop waar de sequence zich afspeeld
# de loop zal hoeveelKeerSpelen vaak loopen
# elke loop zal ((BPM/sample) sample = duratie van de noot) zo lang vertraagd worden voor de volgende loop

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




 

