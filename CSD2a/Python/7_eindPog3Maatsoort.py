import simpleaudio as sa
import time
import random

hat = sa.WaveObject.from_wave_file("samples_drumstel/hat.wav") 
snare = sa.WaveObject.from_wave_file("samples_drumstel/snare.wav")
kick = sa.WaveObject.from_wave_file("samples_drumstel/kick.wav")
bongo1 = sa.WaveObject.from_wave_file("samples_drumstel/bongo1.wav")
bongo2 = sa.WaveObject.from_wave_file("samples_drumstel/bongo2.wav")

# kies een BPM
print("wat voor BPM kies je?")
BPMinput = float(input())
BPMHeel = (60.0 / BPMinput) * 4  #= 1 hele noot  

# hoevaak wil je de loop afspelen
print("hoevaak wil je de loop afspelen")
hoevaakLoop = float(input())

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




print("welke maatsoort wil je?")
maatsoort = int(input())
if maatsoort == 4: 
    kick_kans = [80,0,40,0]   # kick op 1 is kans van 80% en op 2 kans van 40%  (op de 2 en 4 0% kans)
    kick_omrekeken = BPMHeel / 4 

    snare_kans = [70,0,0,40,0,0,50,0,0] # de snare word de hele noot opgedeeld in 9 stukken ze kunnen maar op 3 komen dus eigenlijk / 3
    snare_omrekeken = BPMHeel / 9 # dit maakt het algoritme interessanter

    hat_kans = [70,50,75,50,60,100] # kans waarop de hat kan komen
    hat_omrekeken = BPMHeel / 6 

    bongo_kans = [1,2,3,4,5,6,7,8]
    bongo_omrekeken = BPMHeel / 8 

if maatsoort == 5: 
    kick_kans = [80,0,60,0,40] # kick op 1 is kans van 80% en op 2 kans van 60% en op 3 40% 
    kick_omrekeken = BPMHeel / 8 

    snare_kans = [70,0,0,40,0,20,50,0,0,50,0,40]
    snare_omrekeken = BPMHeel / 12 

    hat_kans = [100,100,100,100,100] 
    hat_omrekeken = BPMHeel / 6 

    bongo_kans = [1,2,3,4,5]
    bongo_omrekeken = BPMHeel / 8 

if maatsoort == 7: 
    kick_kans = [80,0,60,0,40,0,60]
    kick_omrekeken = BPMHeel / 8 

    snare_kans = [70,20,40,0,50,20,0]  # hier gaat de snare heel gek doen omdat 1 hele noot word opgedeeld in 7 stappen
    snare_omrekeken = BPMHeel / 7 

    hat_kans = [70,0,50,0,75,0,50,0,60,0,50,0]
    hat_omrekeken = BPMHeel / 12 

    bongo_kans = [1,2,3,4,5,6,7]
    bongo_omrekeken = BPMHeel / 8 


# arrays voor de timestamps van de groepen 
stempels = []

# in deze fucntie worden de plekken bepaald
def randomD():
    #kick plekken
    for index, item in enumerate(kick_kans):
        rand = random.randint(1,100)
        if (rand <= item):
            stempels.append(event_stamps("kickplek",index + 1))

    # snare plek
    for index, item in enumerate(snare_kans):
        rand1 = random.randint(1,100)
        if (rand1 <= item):
            stempels.append(event_stamps("snareplek",index + 1))        
    # hat plek
    for index, item in enumerate(hat_kans):
        rand20 = random.randint(1,100)
        if (rand20 <= item):
            stempels.append(event_stamps("hatplek",index + 1))
    # bongo plek
    for bongPlek in bongo_kans:
        rand3 = random.randint(1,100)
        if (rand3 <= 60):
            stempels.append(event_stamps("bongplek",bongPlek))
    # ------------------------------------------------

# de timestamps van alle instrumenten / lengtesworden in 1 lijst gestopt samen met de instrument Naam
alleStamps = []
randomD()
print(stempels)

# hierin worden de plekken geconverteerd naar MS
def bijElkaar():
    randomD()
    samples = ['kick','snare','hat','bongo1','bongo2'] 
    for plek in stempels:
        rand4 = random.randint(1,100)
        if plek['welkBlok'] == "kickplek":
            alleStamps.append(event_instrument(samples[0],plek['plek']*kick_omrekeken)) # dus nu zijn er 4 plekken beschikbaar en 2 daarvan worden gebruikt bij 4/4                                                                                                                                                     
                                                                                        # dus nu zijn er 5 plekken beschikbaar en 3 daarvan worden gebruikt bij 5/4 
                                                                                        # dus nu zijn er 7 plekken beschikbaar en 3 daarvan worden gebruikt bij 7/8 
        if plek['welkBlok'] == "snareplek":
            alleStamps.append(event_instrument(samples[1],plek['plek']*snare_omrekeken))
        if plek['welkBlok'] == "hatplek":
            alleStamps.append(event_instrument(samples[2],plek['plek']*hat_omrekeken))
        
        if plek['welkBlok'] == "bongplek":
            if (rand4 <= 50):
                alleStamps.append(event_instrument(samples[3],plek['plek']*bongo_omrekeken))
            else:
                alleStamps.append(event_instrument(samples[4],plek['plek']*bongo_omrekeken))

    # als ie alle timestamps heeft gemaakt mag de lijst gecleard worden voor een nieuwe reeks
    stempels.clear()

# vul de lijst met timestamps van de instrumenten
bijElkaar()
print(alleStamps)

# maak een copie van de stempels waar ze op gespeeld moeten worden zodat we ze later weer kunnen afspelen.
# Ik maak er 2 voor het afspelen van steeds de zelfde en voor het einde (wil je hem nog eemn keer horen, dan word de 2e copie gebruikt
copieVstampels = alleStamps.copy()

# maak een 0 tijd 
tijdBegin = time.time()

while True:
    counter = 0 
    while counter < hoevaakLoop: 
        # nu is de tijd die begint bij 0 oplopend
        nu = time.time() - tijdBegin
        for i in alleStamps:
            # als het geluid van de kick matcht met de timestamp op dat moment speelt er een kick en zo voort
            if (nu >= stamp['timestamps']): 
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
                alleStamps.remove(i)

                # elke keer als de lijst leeg is zal er 
                # of een nieuwe zelfde lijst komen tenzij
                # de loop op is (dus al hoevaakLoop) is geweest,
                # in dat geval zal hij vragen "wil je de zelfde loop of een ander?"
                # dan zal dus de lijst opnieuw met de zelfde lijst gevult worden of met een nieuwe
                if alleStamps == []:
                    counter += 1
                    print(counter)
                    if counter < hoevaakLoop: 
                        print("--------------------------------------------------------------------------")
                        print("")
                        print("༼ ºل͟º ༼ ºل͟º ༼ ºل͟º ༽ ºل͟º ༽ ºل͟º ༽   ༼ ºل͟º ༼ ºل͟º ༼ ºل͟º ༽ ºل͟º ༽ ºل͟º ༽")
                        print("--------------------------------------------------------------------------")
                        tijdBegin = time.time()
                        nu = time.time() - tijdBegin
                        alleStamps = copieVstampels  
                        copieVstampels = alleStamps.copy()
                        
                    else: 
                        print("-------------------------------------")
                        print("Wil je nog een keer de zelfde loop?")
                        print("Zelfde Loop == 0")
                        print("Nieuwe Loop == 1")
                        print("-------------------------------------")
                        opnieuw = int(input())
                        if opnieuw == 0: 
                            # speel de oude lijst weer af en begin  weer bij 0
                            tijdBegin = time.time()
                            nu = time.time() - tijdBegin
                            alleStamps = copieVstampels  
                            copieVstampels = alleStamps.copy()

                        if opnieuw == 1: 
                            # maak een nieuwe lijst met timestamps en begin weer bij 0
                            copieVstampels.clear()
                            alleStamps.clear()
                            
                            bijElkaar()
                            copieVstampels = alleStamps.copy()
                            tijdBegin = time.time()
                            nu = time.time() - tijdBegin
                            alleStamps = copieVstampels  
                            copieVstampels = alleStamps.copy()
                            
                
                
                        




                
                
                
        