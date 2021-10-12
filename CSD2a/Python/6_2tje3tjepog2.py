import simpleaudio as sa
import time
import json
import random

hat = sa.WaveObject.from_wave_file("samples_drumstel/hat.wav") 
snare = sa.WaveObject.from_wave_file("samples_drumstel/snare.wav")
kick = sa.WaveObject.from_wave_file("samples_drumstel/kick.wav")
bongo1 = sa.WaveObject.from_wave_file("samples_drumstel/bongo1.wav")
bongo2 = sa.WaveObject.from_wave_file("samples_drumstel/bongo2.wav")

BPMinput = 120
BPMHeel = (60.0 / BPMinput) *2   #= 1 hele noot  
BPMHalf = BPMHeel / 2            #= 1/2 noot  
BPMDrie = BPMHeel / 3            #= 1/3 noot  
BPMVijf = BPMHeel / 5            #= 1/5 noot
BPMAcht = BPMHeel / 8            #= 1/8 noot

def event_instrument(instrument,stamps):
    return{
        "instrument" : instrument,
        "timestamps" : stamps    
    }

def event_stamps(welkBlok,plek,BPM):
    return{
        "instrument" : welkBlok,
        "plek" : plek,
        "BPM" : BPM    
    }

# arrays voor welke plekken er beschikbaar zijn in de groepen
plekTweetje = [1,2]
plekDrietje = [1,2,3]
plekVijftje = [1,2,3,4,5]
plekAchtje = [1,2,3,4,5,6,7,8]

# arrays voor de timestamps van de groepen 
stempels = []

def tweetje():
    for i in plekTweetje:
        rand = random.randint(1,100)
        # dus hij zal vaker op de 1 een beat geven dan op de 2
        if (rand <= 80):
            stempels.append(event_stamps("twee",i))

def drietje():
    for i in plekDrietje:
        rand1 = random.randint(1,100)
         # dus hij zal vaker op de 1 een beat geven dan op de 2
        if (rand1 <= 50):
            stempels.append(event_stamps("drie",i,BPMDrie))

def vijfje():
    for i in plekVijftje:
        rand2 = random.randint(1,100)
        # dus hij zal vaker op de 1 een beat geven dan op de 2
        if (rand2 <= 70):
            stempels.append(event_stamps("vijf",i,BPMVijf))

def achtje():
    for i in plekAchtje:
        rand3 = random.randint(1,100)
        # dus hij zal vaker op de 1 een beat geven dan op de 2
        if (rand3 <= 70):
            stempels.append(event_stamps("acht",i,BPMAcht))

# de timestamps van alle instrumenten / lengtesworden in 1 lijst gestopt samen met de instrument Naam
alleStamps = []
 
def bijElkaar():
    tweetje()
    drietje()
    vijfje()
    achtje()
    # stempels['plek'].sort()
    samples = ['kick','snare','hat','bongo1','bongo2']
    for i in stempels:
        if i['instrument'] == "kick":
            alleStamps.append(event_instrument(samples[0],i['twee']))
        


bijElkaar()
print(alleStamps)
    
# roep de eerste timestamps aan, later worden deze verwijderd en vernieuwd

# maak een 0 tijd 
tijdBegin = time.time()

while True:
    # nu is de tijd die begint bij 0 oplopend
    nu = time.time() - tijdBegin
    for i in alleStamps:
        # als het geluid van de kick matcht met de timestamp op dat moment speelt er een kick en zo voort
        if (nu >= i['timestamps']): 
            print("-=-")
            if i["instrument"] == 'kick':
                kick.play()
            # if i["instrument"] == 'snare':
            #     snare.play()
            # if i["instrument"] == 'hat':
            #     hat.play()
            # if i["instrument"] == 'bongo1':
            #     bongo1.play()
            # if i["instrument"] == 'bongo2':
            #     bongo2.play()
                
            # elke keer als er een geluid is gespeeld moet er 1 geluid weg
            alleStamps.remove(i)

            # elke keer als de lijst leeg is zal er een nieuwe begin tijd komen
            # de lijst zal ook elke keer weer gevult worden
            if alleStamps == []:
             
                print("-=-=-=-=-=-=-=-=-=-=-=-=-")
                tijdBegin = time.time()
                nu = time.time() - tijdBegin
                bijElkaar()
                
                
                
                
                