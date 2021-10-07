# lijst vullen 

# een functie die het op basis van 3tje in combi met 3tjes doent 
# een functie die het met 3tjes doet 
# een functie die het met 2tjes doet

# hij hihat word random 2tjes en 3tjes
# snare word in 3tjes met zelfde tijd als 2tje van kick
# kick word 2tjes

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

# arrays voor welke plekken er beschikbaar zijn in de groepen
plekTweetje = [1,2]
plekDrietje = [1,2,3]
plekVijftje = [1,2,3,4,5]
plekAchtje = [1,2,3,4,5,6,7,8]

# arrays voor de timestamps van de groepen 
eenTweeArray = []
eenDrieArray = []
eenVijfArray = []
eenAchtArray = []



def tweetje():
    for i in plekTweetje:
        rand = random.randint(1,100)
        # dus hij zal vaker op de 1 een beat geven dan op de 2
        if (rand <= 80):
            eenTweeArray.append(i)

def drietje():
    for i in plekDrietje:
        rand1 = random.randint(1,100)
         # dus hij zal vaker op de 1 een beat geven dan op de 2
        if (rand1 <= 50):
            eenDrieArray.append(i)

def vijfje():
    for i in plekVijftje:
        rand2 = random.randint(1,100)
        # dus hij zal vaker op de 1 een beat geven dan op de 2
        if (rand2 <= 70):
            eenVijfArray.append(i)

def achtje():
    for i in plekAchtje:
        rand3 = random.randint(1,100)
        # dus hij zal vaker op de 1 een beat geven dan op de 2
        if (rand3 <= 70):
            eenAchtArray.append(i)

# de timestamps van alle instrumenten / lengtesworden in 1 lijst gestopt samen met de instrument Naam
alleStamps = []

def tweetjeStamps():
    tweetje()
    eenTweeArray.sort()
    for i in eenTweeArray:
        alleStamps.append(event_instrument('kick',BPMHalf * i))
        eenTweeArray.remove(i)
    
def drietjeStamps():
    drietje()
    eenDrieArray.sort()
    for i in eenDrieArray:
        alleStamps.append(event_instrument('snare',BPMDrie * i))
        eenDrieArray.remove(i)

def vijfjeStamps():
    vijfje()
    eenVijfArray.sort()
    for i in eenVijfArray:
        alleStamps.append(event_instrument('hat',BPMVijf * i))
        eenVijfArray.remove(i)

def achtjeStamps():
    achtje()
    eenAchtArray.sort()
    for i in eenAchtArray:
        rand4 = random.randint(1,100)
        if (rand4 <= 50):
            alleStamps.append(event_instrument('bongo1',BPMVijf * i))
            eenAchtArray.remove(i)   
        else:
            alleStamps.append(event_instrument('bongo2',BPMVijf * i))
            eenAchtArray.remove(i)   


        
    
# roep de eerste timestamps aan, later worden deze verwijderd en vernieuwd
tweetjeStamps()   
drietjeStamps()
vijfjeStamps()
achtjeStamps()
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
            if i["instrument"] == 'snare':
                snare.play()
            if i["instrument"] == 'hat':
                hat.play()
            if i["instrument"] == 'bongo1':
                bongo1.play()
            if i["instrument"] == 'bongo2':
                bongo2.play()
                
            # elke keer als er een geluid is gespeeld moet er 1 geluid weg
            alleStamps.remove(i)

            # elke keer als de lijst leeg is zal er een nieuwe begin tijd komen
            # de lijst zal ook elke keer weer gevult worden
            if alleStamps == []:
                achtjeStamps()
                tweetjeStamps()   
                drietjeStamps()
                vijfjeStamps()
                print("-=-=-=-=-=-=-=-=-=-=-=-=-")
                tijdBegin = time.time()
                nu = time.time() - tijdBegin
                
                
                
                
                