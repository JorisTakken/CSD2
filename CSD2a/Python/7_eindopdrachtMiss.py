# TODO 
# kijken naar multi treading

#IDEE

# de Kick heeft 2 plekken
# Kick      1  |  0           
#           0  |  1       
#           1  |  1

# snare heeft 3 plekken over de tijd van de 2 plekken van de Kick
# snare     50% | 25% | 50%

# Hat heeft 5 plekken over de tijd vand de 2 pekken van de kick
# hat       1 | 50% | 75% | 50% | 1

import simpleaudio as sa
import time
import random

hat = sa.WaveObject.from_wave_file("samples_drumstel/hat.wav") 
snare = sa.WaveObject.from_wave_file("samples_drumstel/snare.wav")
kick = sa.WaveObject.from_wave_file("samples_drumstel/kick.wav")
bongo1 = sa.WaveObject.from_wave_file("samples_drumstel/bongo1.wav")
bongo2 = sa.WaveObject.from_wave_file("samples_drumstel/bongo2.wav")

# kies een BPM
print("---------------------")
print("wat voor BPM kies je?")
print("---------------------")
BPMinput = float(input())

BPMHeel = (60.0 / BPMinput) * 2  #= 1 hele noot  
BPMTwee = BPMHeel / 2            #= 1/2 noot  
BPMDrie = BPMHeel / 3            #= 1/3 noot  
BPMVier = BPMHeel / 4            #= 1/5 noot
BPMAcht = BPMHeel / 8            #= 1/8 noot

def event_instrument(instrument,stamps):
    return{
        "instrument" : instrument,
        "timestamps" : stamps    
    }

def event_stamps(welkBlok,plek):
    return{
        "welkBlok" : welkBlok,
        "plek" : plek,   
    }

# arrays voor de timestamps van de groepen 
stempelsTweeVier = []

def tweeVier():
    # tweetje
    # ------------------------------------------------
    # for i in plekTweetje:
    rand = random.randint(1,100)
    rand1 = random.randint(1,100)
        # dus hij zal vaker op de 1 een beat geven dan op de 2
        # en er is 50% kans dat ie na de 1 ook op de 2 speelt
    if (rand <= 80):
        stempelsTweeVier.append(event_stamps("twee",1))
        if (rand1 <= 50):
            stempelsTweeVier.append(event_stamps("twee",2))
    else:
        stempelsTweeVier.append(event_stamps("twee",2))
    # ------------------------------------------------

    # Drietje (snare)
    # ------------------------------------------------
    plekkenDrie = [1,2,3]
    kansDrie = [50,25,40]
    # snare op 1 = 50 % kans
    # snare op 2 = 25 % kans
    # snare op 3 = 50 % kans
    for index, item in enumerate(kansDrie):
        rand10 = random.randint(1,100)
        if (rand10 <= item):
            stempelsTweeVier.append(event_stamps("drie",index + 1))        
    # ------------------------------------------------

    # vijfje (hat)
    # ------------------------------------------------
    plekkenVier = [1,2,3,4]
    # kansvanhat|      70% | 50% | 75% | 50% |
    kansVier = [85,50,85,50]
    for index, item in enumerate(kansVier):
        rand20 = random.randint(1,100)
        if (rand20 <= item):
            stempelsTweeVier.append(event_stamps("vijf",index+1))
    # ------------------------------------------------

    # achtje (bongo)
    # ------------------------------------------------
    # array voor bongo, voor welke plekken er beschikbaar zijn 
    plekAchtje = [1,2,3,4,5,6,7,8]
    for i in plekAchtje:
        rand3 = random.randint(1,100)
        if (rand3 <= 60):
            stempelsTweeVier.append(event_stamps("acht",i))
    # ------------------------------------------------



# de timestamps van alle instrumenten / lengtesworden in 1 lijst gestopt samen met de instrument Naam
alleStamps = []

# hierin worden de plekken van de timestamps geconverteerd naar MS
def bijElkaar():
    tweeVier()
    samples = ['kick','snare','hat','bongo1','bongo2'] 
    for i in stempelsTweeVier:
        rand4 = random.randint(1,100)
        if i['welkBlok'] == "twee":
            alleStamps.append(event_instrument(samples[0],i['plek']*BPMTwee))
        if i['welkBlok'] == "drie":
            alleStamps.append(event_instrument(samples[1],i['plek']*BPMDrie))
        if i['welkBlok'] == "vijf":
            alleStamps.append(event_instrument(samples[2],i['plek']*BPMVier))
        
        if i['welkBlok'] == "acht":
            if (rand4 <= 50):
                alleStamps.append(event_instrument(samples[3],i['plek']*BPMAcht))
            else:
                alleStamps.append(event_instrument(samples[4],i['plek']*BPMAcht))

    # als ie alle timestamps heeft gemaakt mag de lijst gecleard worden voor een nieuwe reeks
    # stempelsTweeVier.clear()


# roep voor de eerste keer de functie aan
bijElkaar()

# maak een 0 tijd 


copieVstampels = alleStamps.copy()



# print("hoeveel keer wil je de sequencer loopen?")
# hoeveelKeerLoopen = int(input())

while True:
    # nu is de tijd die begint bij 0 oplopend
    
    tijdBegin = time.time()
    nu = time.time() - tijdBegin
    counter = 0 

    while counter < 4:
        
        for i in alleStamps:
        # als het geluid van de kick matcht met de timestamp op dat moment speelt er een kick en zo voort
            if (nu >= i['timestamps']): 
                if i["instrument"] == 'kick':
                    kick.play()
                    print("                      |          ʕ•ᴥ•ʔ")
                if i["instrument"] == 'snare':
                    snare.play()
                    print("                      |                    (▀̿Ĺ̯▀̿ ̿)")
                if i["instrument"] == 'hat':
                    hat.play()
                    print("                      |                             (͡• ͜ʖ ͡•)")
                if i["instrument"] == 'bongo1':
                    bongo1.play()
                    print("         (；☉_☉)")
                if i["instrument"] == 'bongo2':
                    bongo2.play()
                    print("(☉_☉ ；)")

                # elke keer als er een geluid is gespeeld moet er 1 geluid weg
                # alleStamps.remove(i)

                # elke keer als de lijst leeg is zal er een nieuwe begin tijd komen
                # de lijst zal ook elke keer weer gevult worden
                if alleStamps:
                    print("--------------------------------------------------------------------------")
                    print("")
                    print("༼ ºل͟º ༼ ºل͟º ༼ ºل͟º ༽ ºل͟º ༽ ºل͟º ༽   ༼ ºل͟º ༼ ºل͟º ༼ ºل͟º ༽ ºل͟º ༽ ºل͟º ༽")
                    print("--------------------------------------------------------------------------")
                    tijdBegin = time.time()
                    nu = time.time() - tijdBegin
                    counter = counter + 1
                    alleStemmpels = copieVstampels  
                    copieVstampels = alleStemmpels.copy()
                    
                    print(counter)
    time.sleep(0.5)




                
                
                
                