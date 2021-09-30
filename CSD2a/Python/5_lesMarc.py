import simpleaudio as sa

hat = sa.WaveObject.from_wave_file("samples_drumstel/hat.wav") 
snare = sa.WaveObject.from_wave_file("samples_drumstel/snare.wav")

me = {
    "naam" : "joris",
    "leeftijd" : "19"
}

# print(me["naam"])

hat_event = {
    "timestamp" : 10200,
    "instrumentnaam" : "hat",
    "instrument" : hat,
    "naam" : "hat",
    "duratie" : 500  
}

snare_event = {
    "timestamp" : 10000,
    "instrumentnaam" : "snare",
    "instrument" : snare,
    "naam" : "snare",
    "duratie" : 200
}




def event_maneger(event):
    # print(hat_event)
    event['instrument'].play()

event_maneger(hat_event)
# event_maneger(snare_event)

while True:
    print("a")