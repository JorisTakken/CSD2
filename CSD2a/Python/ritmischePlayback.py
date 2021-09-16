import asyncio 
import time
import simpleaudio as sa

schreeuw = 'samples/kick.wav'
wave_obj = sa.WaveObject.from_wave_file(schreeuw)


print("hoeveel keer wil je de sample spelen?")
hoeveelKeerSpelen = input("")
hoeveelKeerSpelen = int(hoeveelKeerSpelen)
print("wat voor BPM kies je?")
BPMinput = input("")
BPMinput = int(BPMinput)
BPM = 60 / BPMinput
sample = []

print("Hoelang duurt je noot?")
print("Kies uit:")
print("kwart | half | heel")

i = 1
while i < (1 + hoeveelKeerSpelen):
    print ("sample", i)
    keuze = input("")

    if(keuze == "kwart"):
        sample.append(4)
    if(keuze == "half"):
        sample.append(2)
    if(keuze == "heel"):
        sample.append(1)

   

    i += 1


async def seq():
    i = 1
    while i < (1 + hoeveelKeerSpelen):
        asyncio.create_task(asyncio.sleep(1))
        print('kick')
        play_obj = wave_obj.play()
        await asyncio.sleep(BPM)
        
        i += 1
        if i == hoeveelKeerSpelen + 1: 
            play_obj.wait_done()




print(sample)
asyncio.run(seq()) 

