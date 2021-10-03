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
BPMAcht = BPMKwart / 2            #= 1/8 noot  

# plekken van waar ze gaan bangen
plekHat = [0,1,2,3,4,5,6,7]
plekSnare = [2,6]
plekKick = [0,2,4,6]

# stampsKick = []
# stampsHat = []
# stampsSnare = []

hat_event = {
    "stampsMS" : [],
    "plek" : plekHat,
    "instrument" : hat,
}

snare_event = {
    "stampsMS" : [],
    "plek" : plekSnare,
    "instrument" : snare,
}

kick_event = {
    "stampsMS" : [],
    "plek" : plekKick,
    "instrument" : kick,
}


# maak met de arrays in de events de timestamps
def timestampsMaken(plek,stamps):
    for i in plek['plek']:
        stamps["stampsMS"].append(float(i * BPMAcht))
    # print(timeStamps)



def stempels(stempel):
    stempel["stampsMS"]




# maak een event waarmee je de sample speelt
def geluidSpelen(speel):
    speel['instrument'].play() 












# tijdBegin = time.time()

# while True:       
#     now = time.time() - tijdBegin
#     if (now >= stampsSnare):
#         print("ja")
#     time.sleep(0.001)
# time.sleep(stopTijd)






