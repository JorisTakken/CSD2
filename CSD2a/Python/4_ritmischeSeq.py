# importeer functies die ik nodig ga hebben voor de opdracht
import time
import simpleaudio as sa

# importeer samples en geef de samples namen
kick = sa.WaveObject.from_wave_file("samples/kick.wav")

# kies nu hoeveel noten er in de sequenser zitten
print("--------------------------------------")
print("hoeveel keer wil je de sample spelen?")
print("--------------------------------------")
hoeveelKeerSpelen = int(input())

# kies een BPM
print("---------------------")
print("wat voor BPM kies je?")
print("---------------------")
BPMinput = float(input())
BPM = 60.0 / BPMinput # in ms

# dit is de input voor het kiezen tussen een random nootduur of nootduur die je zelf kiest
print("------------------------------")
print("Kies uit:")
print("kwart (4)| half (2) | heel (1)")
print("------------------------------")
duratieNoot = []
for i in range(hoeveelKeerSpelen):
    print ("duratie", i)
    keuze = (float(input("")))
    if(keuze == 4):
        duratieNoot.append(0.25)
    if(keuze == 2):
        duratieNoot.append(0.5)
    if(keuze == 1):
        duratieNoot.append(1)



# je begint bij 0 en elke value heeft een eigen waarde bij de array
tijd16eNoten = []
laatsteVal = 0
for i in (duratieNoot):
    tijd16eNoten.append(laatsteVal)
    if i == 0.25:
        laatsteVal += 1
    elif i == 0.50: 
        laatsteVal += 2
    elif i == 1:
        laatsteVal += 4

# hier convert je de 16e stappen weer naar tijds intervallen
tijdStempels = []
tijdVan1Zestiende = BPM 
for i in tijd16eNoten:
    tijdStempels.append(float(i * tijdVan1Zestiende))



if tijdStempels:
    ts = tijdStempels.pop(0)
stopTijd = tijdStempels[-1]

tijdBegin = time.time()

# tijdlijn met de heletijd + 0.001 time sleep
# speeld sample de heletijd op de timestamps
while True:       
    # maak tijd 0 (hierbij komt de heletijd + 0.001)
    now = time.time() - tijdBegin
    # als de timestamp zelfde = als de tijd, speel af!
    if (now >= ts):
        kick.play()
        print(ts)
        # als ie is gespeeld haal hem eruit
        if tijdStempels:
            ts = tijdStempels.pop(0)
        # als alle dingen uit array zijn stop maar!
        else:
            break
    time.sleep(0.001)
time.sleep(stopTijd)




  