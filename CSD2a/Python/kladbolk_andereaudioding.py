from pydub import AudioSegment
from pydub.playback import play
import time

song = AudioSegment.from_wav("samples_drumstel/kick.wav")

# boost volume by 6dB
louder_song = song + 6

# reduce volume by 3dB
quieter_song = song - 3

#Play song
play(louder_song)
time.sleep(1)
play(quieter_song)
