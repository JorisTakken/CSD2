# importeer functies die ik nodig ga hebben voor de opdracht
import time
import simpleaudio as sa



# importeer samples en geef de samples namen
kick = sa.WaveObject.from_wave_file("samples/kick.wav")

# kies nu hoeveel noten er in de sequenser zitten
print("--------------------------------------")
print("hoeveel keer wil je de sample spelen?")
print("--------------------------------------")
hoeveelKeerSpelen = float(input())


# kies een BPM
print("---------------------")
print("wat voor BPM kies je?")
print("---------------------")
BPMinput = float(input())
BPM = 60 / BPMinput # in ms

# dit is de input voor het kiezen tussen een random nootduur of nootduur die je zelf kiest

print("------------------------------")
print("Kies uit:")
print("kwart (4)| half (2) | heel (1)")
print("------------------------------")


duratieNoot = []
i = 1
while i < (1 + hoeveelKeerSpelen):
    print ("duratie", i)
    keuze = float(input(""))
    if(keuze == 4):
        duratieNoot.append(0.25)
    if(keuze == 2):
        duratieNoot.append(0.5)
    if(keuze == 1):
        duratieNoot.append(1)
    i += 1


tijd16eNoten = []
laatsteVal = 0
for i in duratieNoot:
    tijd16eNoten.append(laatsteVal)
    if i == 0.25:
        laatsteVal += 1
    elif i == 0.50:
        laatsteVal += 2
    elif i == 1:
        laatsteVal += 4



tijdStempels = []
tijdVan1Zestiende = BPM/4
for i in tijd16eNoten:
    tijdStempels.append(float(i * tijdVan1Zestiende))


tijdBegin = time.time()


if tijdStempels:
    ts = tijdStempels.pop(0)


while True:
    nu = float(time.time() - tijdBegin)  
    for i in tijdStempels:
        print(ts)
        if (nu >= ts):
            kick.play()
            if tijdStempels:
                ts = tijdStempels.pop(0)
    time.sleep(0.001)
    

  
   
   

    


    


        

