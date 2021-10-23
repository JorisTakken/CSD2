
import simpleaudio as sa
import time
import random
from midiutil import MIDIFile # 

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

def event_instrument(instrument,stamps,sample,velocity,midiNoot,midiDur):
    return{
        "instrument" : instrument,
        "timestamps" : stamps,    
        "sample" : sample,
        'velocity': velocity,
        'midinoot': midiNoot,
        'midi_dur': midiDur,
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

    hat_kans = [100,100,100,100,100,100] # kans waarop de hat kan komen
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

# hierin worden de plekken geconverteerd naar MS
def bijElkaar():
    
    randomD()
    samples = ['kick','snare','hat','bongo1','bongo2'] 
    for plek in stempels:
        rand4 = random.randint(1,100)
        if plek['welkBlok'] == "kickplek":
            alleStamps.append(event_instrument(samples[0],plek['plek']*kick_omrekeken,kick,120,60,0.001)) # dus nu zijn er 4 plekken beschikbaar en 2 daarvan worden gebruikt bij 4/4                                                                                                                                                     
                                                                                        # dus nu zijn er 5 plekken beschikbaar en 3 daarvan worden gebruikt bij 5/4 
                                                                                        # dus nu zijn er 7 plekken beschikbaar en 3 daarvan worden gebruikt bij 7/8 
        if plek['welkBlok'] == "snareplek":
            alleStamps.append(event_instrument(samples[1],plek['plek']*snare_omrekeken,snare,120,61,0.001))
        if plek['welkBlok'] == "hatplek":
            alleStamps.append(event_instrument(samples[2],plek['plek']*hat_omrekeken,hat,120,63,0.001))
        
        if plek['welkBlok'] == "bongplek":
            if (rand4 <= 50):
                alleStamps.append(event_instrument(samples[3],plek['plek']*bongo_omrekeken,bongo1,120,67,0.001))
            else:
                alleStamps.append(event_instrument(samples[4],plek['plek']*bongo_omrekeken,bongo2,120,66,0.001))

    # als ie alle timestamps heeft gemaakt mag de lijst gecleard worden voor een nieuwe reeks
    stempels.clear()


# vukl de lijst met timestamps van de instrumenten
bijElkaar()

# maak een copie van de stempels waar ze op gespeeld moeten worden zodat we ze later weer kunnen afspelen.
copieVstampels = alleStamps.copy()

# maak een 0 tijd 
def speelSequenser(): 
    # global omdat deze lijsten anders niet werden gevonden in de code
    global alleStamps
    global copieVstampels
    # de counter gaat over hoevaak de loop word afgespeeld.
    counter = 0 
    tijdBegin = time.time()
    
    while counter < hoevaakLoop: 
        # nu is de tijd die begint bij 0 oplopend
        nu = time.time() - tijdBegin
        for stamps in alleStamps:
            # als het geluid van de kick matcht met de timestamp op dat moment speelt er een kick en zo voort
            if (nu >= stamps['timestamps']):
                print(nu)
                stamps["sample"].play()
                time.sleep(0.001)

                alleStamps.remove(stamps)
                # elke keer als de lijst leeg is zal er 
                # of een nieuwe zelfde lijst komen tenzij
                # de loop op is (dus al hoevaakLoop) is geweest,
                # in dat geval zal hij vragen "wil je de zelfde loop of een ander?"
                # dan zal dus de lijst opnieuw met de zelfde lijst gevult worden of met een nieuwe
                if alleStamps == []:
                    counter += 1
                    if counter < hoevaakLoop: 
                        print("--------------------------------------------------------------------------")
                        tijdBegin = time.time() 
                        nu = time.time() - tijdBegin
                        alleStamps = copieVstampels  
                        copieVstampels = alleStamps.copy()

def midi():
    print("midi")

    track = 0 
    tijdMidi = 0
    channel = 0


    MyMIDI = MIDIFile(1) # One track, defaults to format 1 (tempo track
                        # automatically created)
    MyMIDI.addTempo(track, tijdMidi, BPMinput)

    for midi in copieVstampels:
        dur = midi['timestamps']    
        MyMIDI.addNote(track, channel, midi['midinoot'],
                        tijdMidi , dur , 100)

        tijdMidi = tijdMidi + dur

    with open("MidiFiletje.mid", "wb") as output_file:      
        MyMIDI.writeFile(output_file)

afspelen = True
while afspelen:
    # de hele sequencer staat nu in een functie
    speelSequenser()     

    maakKeuze = input(
    " Wil je de loop opslaan? (opslaan)(1) \n" + 
    " Wil je hem opnieuw horen? (opnieuw)(2) \n" +
    " Wil je een nieuwe Sequence? (nieuw)(3)\n" + 
    " Wil je helemaal stoppen? (stop)(4) \n") 
    
    if maakKeuze == "opslaan" or maakKeuze == "1":
        print("midi")
        midi()

    elif maakKeuze == "opnieuw" or maakKeuze == "2" :
        tijdBegin = time.time() 
        nu = time.time() - tijdBegin
        alleStamps = copieVstampels  
        copieVstampels = alleStamps.copy()
        
    elif maakKeuze == "nieuw" or maakKeuze == "3":
        copieVstampels.clear()
        alleStamps.clear()                        
        bijElkaar()
        tijdBegin = time.time() 
        nu = time.time() - tijdBegin
        alleStamps = copieVstampels  
        copieVstampels = alleStamps.copy()

    elif maakKeuze == "stop" or maakKeuze == "4":
        afspelen = False

    
                
                    

                        
                            
                        




                
                
                
        