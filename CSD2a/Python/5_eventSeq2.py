import simpleaudio as sa
import time
import json
import random

hat = sa.WaveObject.from_wave_file("samples_drumstel/hat.wav") 
snare = sa.WaveObject.from_wave_file("samples_drumstel/snare.wav")
kick = sa.WaveObject.from_wave_file("samples_drumstel/kick.wav")

#  TODO
# ik ga een rij maken van 8 stappen 
# je mag gaan kiezen wanneer de kick snare en Hat komt
# voor nu: 
#   hat     : 0 1 2 3 4 5 6 7
#   snare   :     2       6
#   kick    : 0   2   4   6 
#   
# dus BPM = (60.0 / BPMinput) : 2       = 1/8 noot 
# dus BPM = 60.0 / BPMinput # in ms     = 1 kwart noot 
# dus BPM = 60.0 / BPMinput * 2         = 1 halve noot 


# dus hoeveel keer spelen is 
# hat   8 
# snare 2
# kick  4

hoelangSeq = 8

BPMinput = 120
BPMKwart = (60.0 / BPMinput)      #= 1/4 noot  
BPMAcht = BPMKwart / 2            #= 1/8 noot  

timestamps = []

# maak een event
def event(instrument,stamps):
    return{
        "instrument" : instrument,
        "timestamps" : stamps    
    }

# plekken van waar ze gaan bangen
plekHat = [1,2,3,4,5,6,7,8]
plekSnare = [3,7]
plekKick = [1,3,5,7]

allesBijElkaar = []

# maak een event array waarin alle waardes van instrumenten in zitten.
for i in plekKick:
    allesBijElkaar.append(event('kick',BPMAcht * i))
for i in plekSnare:
    allesBijElkaar.append(event('snare',BPMAcht * i))
for i in plekHat:
    allesBijElkaar.append(event('hat',BPMAcht * i))

# een kopie van de array die ik later dan kan gebruiken om de array weer te vullen
copie = allesBijElkaar.copy()

# maak een 0 tijd 
tijdBegin = time.time()

while True:
    # nu is de tijd die begint bij 0 oplopend
    nu = time.time() - tijdBegin

    for i in allesBijElkaar:
        # als het geluid van de kick matcht met de timestamp op dat moment speelt er een kick en zo voort
        if (nu >= i['timestamps']): 
            print("-=-")
            if i["instrument"] == 'kick':
                kick.play()
            if i["instrument"] == 'snare':
                snare.play()
            if i["instrument"] == 'hat':
                hat.play()
                
            # elke keer als er een geluid is gespeeld moet er 1 geluid weg
            allesBijElkaar.remove(i)

            # elke keer als de lijst leeg is zal er een nieuwe begin tijd komen
            # de lijst zal ook elke keer weer gevult worden
            if allesBijElkaar == []:
                print("-=-=-=-=-=-=-=-=-=-=-=-=-")
                tijdBegin = time.time()
                nu = time.time() - tijdBegin
                allesBijElkaar = copie
                copie = allesBijElkaar.copy()  

    time.sleep(0.001)
   

