import simpleaudio as sa
import time

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

# 3 arrays met timestamps van 3 samples
# die gaan in de events

hoelangSeq = 8

BPMinput = 120
BPMKwart = (60.0 / BPMinput)      #= 1/4 noot  
BPMAcht = BPMKwart /2              #= 1/8 noot  

# plekken van waar ze gaan bangen
plekHat = [0,1,2,3,4,5,6,7]
plekSnare = [2,6]
plekKick= [0,2,4,6]


hat_event = {
    "plek" : plekHat,
    "instrument" : hat,
}

snare_event = {
    "plek" : plekSnare,
    "instrument" : snare,
}

kick_event = {
    "plek" : plekKick,
    "instrument" : kick,
}


# maak met de arrays in de events de timestamps
def timestamps(plek):
    timeStamps = []
    for i in plek['plek']:
        timeStamps.append(float(i * BPMAcht))
    # print(timeStamps)

# maak een event waarmee je de sample speelt
def geluidSpelen(speel):
    speel['instrument'].play() 






