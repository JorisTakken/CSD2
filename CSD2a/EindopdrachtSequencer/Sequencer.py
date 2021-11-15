import simpleaudio as sa
import time
import random
# MIDI gedeelte geinspireerd op Ciska haar code en van https://pypi.org/project/MIDIUtil/
from midiutil import MIDIFile # 

print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=")
print("welk drumstel kies je?")
print(
"accoustisch [1] \n" +
"electronisch [2] \n" +
"piepkuiken [3] \n" + 
"goeroe [4]")
print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=")
drumstel = int(input())

if drumstel == 1:
    hat = sa.WaveObject.from_wave_file("samples_drumstel/drumstel1/hat1.wav") 
    snare = sa.WaveObject.from_wave_file("samples_drumstel/drumstel1/snare1.wav")
    kick = sa.WaveObject.from_wave_file("samples_drumstel/drumstel1/kick1.wav")
    bongo1 = sa.WaveObject.from_wave_file("samples_drumstel/drumstel1/bongo11.wav")
    bongo2 = sa.WaveObject.from_wave_file("samples_drumstel/drumstel1/bongo21.wav")

if drumstel == 2:
    hat = sa.WaveObject.from_wave_file("samples_drumstel/drumstel2/hat2.wav") 
    snare = sa.WaveObject.from_wave_file("samples_drumstel/drumstel2/snare2.wav")
    kick = sa.WaveObject.from_wave_file("samples_drumstel/drumstel2/kick2.wav")
    bongo1 = sa.WaveObject.from_wave_file("samples_drumstel/drumstel2/geluid2.wav")
    bongo2 = sa.WaveObject.from_wave_file("samples_drumstel/drumstel2/geluid1.wav")

if drumstel == 3:
    hat = sa.WaveObject.from_wave_file("samples_drumstel/drumstel3/een.wav") 
    snare = sa.WaveObject.from_wave_file("samples_drumstel/drumstel3/twee.wav")
    kick = sa.WaveObject.from_wave_file("samples_drumstel/drumstel3/drie.wav")
    bongo1 = sa.WaveObject.from_wave_file("samples_drumstel/drumstel3/vier.wav")
    bongo2 = sa.WaveObject.from_wave_file("samples_drumstel/drumstel3/vijf.wav")

if drumstel == 4:
    hat = sa.WaveObject.from_wave_file("samples_drumstel/drumstel4/hat3.wav") 
    snare = sa.WaveObject.from_wave_file("samples_drumstel/drumstel4/snare3.wav")
    kick = sa.WaveObject.from_wave_file("samples_drumstel/drumstel4/kick3.wav")
    bongo1 = sa.WaveObject.from_wave_file("samples_drumstel/drumstel4/bong1.wav")
    bongo2 = sa.WaveObject.from_wave_file("samples_drumstel/drumstel4/bong2.wav")

# kies een BPM
print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=")
print("wat voor BPM kies je?")
print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=")
# functie voor het maken van een BPM tussen 50 en 250
def foutBPM():
    global BPMinput
    BPMinput = float(input())
    if BPMinput < 50: 
        print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=")
        print("error, lager dan 50 BPM kan niet")
        print("kies een ander BPM!")
        print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=")
        BPMinput = float(input())

    if BPMinput > 250: 
        print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=")
        print("error, hoger dan 250 BPM kan niet")
        print("kies een ander BPM!")
        print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=")
        BPMinput = float(input())
foutBPM()

BPMHeel = (60.0 / BPMinput) * 4  #= 1 hele noot  

print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=")
print("hoevaak wil je de loop afspelen?")
print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=")
# hoevaak wil je de loop afspelen
hoevaakLoop = float(input())

def event_instrument(instrument,stamps,stampsMidi,sample,velocity,midiNoot,midiDur):
    return{
        "instrument" : instrument,
        # ik heb twee lijsten met Timestamps omdat anders 1 van de twee raar doet.
        # de pythonlijst heeft een index + 1 nodig en de MIDI juist index zodat midi niet verschuift ijn logic's grit
        "timestamps" : stamps,
        "timestampsMidi" : stampsMidi,     
        "sample" : sample,
        'velocity': velocity,
        'midinoot': midiNoot,
        'midi_dur': midiDur,
    }

def event_stamps(welkBlok,plek,plekMidi):
    return{
        "welkBlok" : welkBlok,
        "plek" : plek,   
        "plekMidi" : plekMidi
    } 

print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=")
print("welke maatsoort wil je?")
print(
"[4]/4 \n" +
"[5]/4 \n" +
"[7]/8")
print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=")
maatsoort = int(input())

# deze methode van maatsoort maken is geinspireerd op die van ROMAN
if maatsoort == 4: 
    kick_kans = [80,0,40,0]   # kick op 1 is kans van 80% en op 2 kans van 40%  (op de 2 en 4 0% kans)
    kick_omrekeken = BPMHeel / 4 

    snare_kans = [70,0,0,40,0,0,50,0] # de snare word de hele noot opgedeeld in 9 stukken ze kunnen maar op 3 komen dus eigenlijk / 3
    snare_omrekeken = BPMHeel / 9 # dit maakt het algoritme interessanter

    hat_kans = [100,50,100,50,100,100] # kans waarop de hat kan komen
    hat_omrekeken = BPMHeel / 6 

    bongo_kans = [1,2,3,4,5,6,7,8]
    bongo_omrekeken = BPMHeel / 8 

if maatsoort == 5: 
    kick_kans = [80,0,60,0,40] # kick op 1 is kans van 80% en op 2 kans van 60% en op 3 40% 
    kick_omrekeken = BPMHeel / 8 

    snare_kans = [70,0,50,40,20]
    snare_omrekeken = BPMHeel / 6 

    hat_kans = [100,70,50,40,100] 
    hat_omrekeken = BPMHeel / 5

    bongo_kans = [1,2,3,4,5,6,7,8,9,10]
    bongo_omrekeken = BPMHeel / 10 

if maatsoort == 7: 
    kick_kans = [80,0,60,0,40,0,60]
    kick_omrekeken = BPMHeel / 8 

    snare_kans = [70,20,40,0,50,20]  # hier gaat de snare heel gek doen omdat 1 hele noot word opgedeeld in 7 stappen
    snare_omrekeken = BPMHeel / 7 

    hat_kans = [70,0,50,0,75,0,100]
    hat_omrekeken = BPMHeel / 8 

    bongo_kans = [1,2,3,4,5,6,7]
    bongo_omrekeken = BPMHeel / 8 

# arrays voor de timestamps van de groepen met mogelijke plekken 
stempels = []

# in deze fucntie worden de plekken bepaald
def randomD():
    #kick plekken
    for index, item in enumerate(kick_kans):
        rand = random.randint(1,100)
        if (rand <= item):
            stempels.append(event_stamps("kickplek",index+1,index))
    # snare plek
    for index, item in enumerate(snare_kans):
        rand1 = random.randint(1,100)
        if (rand1 <= item):
            stempels.append(event_stamps("snareplek",index+1,index))        
    # hat plek
    for index, item in enumerate(hat_kans):
        rand20 = random.randint(1,100)
        if (rand20 <= item):
            stempels.append(event_stamps("hatplek",index+1,index))
    # bongo plek
    for bongPlek in bongo_kans:
        rand3 = random.randint(1,100)
        if (rand3 <= 60):
            stempels.append(event_stamps("bongplek",bongPlek,bongPlek))
    # ------------------------------------------------

# de timestamps van alle instrumenten / lengtesworden in 1 lijst gestopt samen met de instrument Naam
all_events = []

# hierin worden de plekken geconverteerd naar MS
def bijElkaar():

    # functie voor plekken word gemaakt  
    randomD()

    # lijst met de samples die je kan kiezen
    samples = ['kick','snare','hat','bongo1','bongo2'] 
    for plek in stempels:
        rand4 = random.randint(1,100)
        if plek['welkBlok'] == "kickplek":
            all_events.append(event_instrument(samples[0],plek['plek']*kick_omrekeken,plek['plekMidi']*kick_omrekeken,kick,120,36,0.1))                                                                                                                                                                                                      
        if plek['welkBlok'] == "snareplek":
            all_events.append(event_instrument(samples[1],plek['plek']*snare_omrekeken,plek['plekMidi']*snare_omrekeken,snare,120,38,0.1))
        if plek['welkBlok'] == "hatplek":
            all_events.append(event_instrument(samples[2],plek['plek']*hat_omrekeken,plek['plekMidi']*hat_omrekeken,hat,120,42,0.1))
        
        if plek['welkBlok'] == "bongplek":
            if (rand4 <= 50):
                all_events.append(event_instrument(samples[3],plek['plek']*bongo_omrekeken,plek['plekMidi']*bongo_omrekeken,bongo1,120,46,0.1))
            else:
                all_events.append(event_instrument(samples[4],plek['plek']*bongo_omrekeken,plek['plekMidi']*bongo_omrekeken,bongo2,120,48,0.1))

    # als ie alle timestamps heeft gemaakt mag de lijst gecleard worden voor een nieuwe reeks
    stempels.clear()

# vukl de lijst met timestamps van de instrumenten
bijElkaar()

# maak een copie van de stempels waar ze op gespeeld moeten worden zodat we ze later weer kunnen afspelen.
copieVstampels = all_events.copy()

# maak een 0 tijd 
def speelSequenser(): 
    global opnieuw

    # de counter gaat over hoevaak de loop word afgespeeld. Dit heb je aan het begin gekozen.
    # elke keer als de lijst leeg is is counter + 1 
    counter = 0 
    
    # functie voor het opnieuw afspelen van de sequence
    def opnieuw():
        # ik gebruik de global functies omdat python deze anders niet herkent 
        global copieVstampels
        global all_events
        global tijdBegin
        global nu

        # nieuwe beginteid en nieuwe copys worden gemaakt
        tijdBegin = time.time() 
        nu = time.time() - tijdBegin
        all_events = copieVstampels  
        copieVstampels = all_events.copy()

    opnieuw()

    while counter < hoevaakLoop: 
        # methode van timestamps afspelen geinspireerd op CISKA
        # nu is de tijd die begint bij 0 oplopend
        nu = time.time() - tijdBegin
        for stamps in all_events:
            # als het geluid van de kick matcht met de timestamp op dat moment speelt er een kick en zo voort
            if (nu >= stamps['timestamps']):
                
                stamps["sample"].play()
                

                # bij elke keer dat er 1 sample word gespeeld word hij er gelijk uit gehaald tot de lijst leeg is
                all_events.remove(stamps)
                time.sleep(0.001)
                # elke keer als de lijst leeg is zal er 
                # of een nieuwe zelfde lijst komen tenzij
                # de loop op is (dus al hoevaakLoop) is geweest,
                # in dat geval zal hij vragen "wil je de zelfde loop of een ander?"
                # dan zal dus de lijst opnieuw met de zelfde lijst gevult worden of met een nieuwe
                if all_events == []:
                    print("(͡° ͜ʖ ͡°)")
                    counter += 1
                    if counter < hoevaakLoop + 1: 
                        opnieuw()

# hier maak je een midibestand
def midi():
    print("midi")

    track = 0 
    tijdMidi = 0
    channel = 0

    MyMIDI = MIDIFile(1) 
    MyMIDI.addTempo(track, tijdMidi, BPMinput)

    for midi in copieVstampels:  
        MyMIDI.addNote(track, channel, midi['midinoot'],
                        (midi['timestampsMidi']*2),0.2 , 100)


    with open("MidiFiletje.mid", "wb") as output_file:      
        MyMIDI.writeFile(output_file)

afspelen = True
while afspelen:
    # de hele sequencer staat nu in een functie
    speelSequenser()     

    print("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=")
    maakKeuze = input(
    "[B]ewaren (1) \n" + 
    "[O]pnieuw afspelen (2) \n" +
    "[N]ieuwe sequence (3) \n" +
    "[S]top (4) \n") 
    
    if maakKeuze == "B" or maakKeuze == "b" or maakKeuze == "1":
        midi()
        afspelen = False

    elif maakKeuze == "O" or maakKeuze == "o" or maakKeuze == "2" :
        opnieuw()
    
    elif maakKeuze == "N" or maakKeuze == "n" or maakKeuze == "3" :
        # clear alle lijsten en maak nieuwe
        all_events.clear()
        copieVstampels.clear()
        bijElkaar()
        copieVstampels = all_events.copy()
        opnieuw()

    elif maakKeuze == "S" or maakKeuze == "s" or maakKeuze == "4":
        afspelen = False

    
                
                    

                        
                            
                        




                
                
                
        