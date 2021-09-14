# import simpleaudio.functionchecks as fc

# fc.LeftRightCheck.run()

import simpleaudio as sa

filename = 'schreeuw.wav'
wave_obj = sa.WaveObject.from_wave_file(filename)

print("wil jij geluid horen?")
input = ("")
print("oke komt ie!")
play_obj = wave_obj.play()
play_obj.wait_done()

