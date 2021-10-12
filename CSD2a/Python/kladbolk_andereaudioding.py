from pydub import AudioSegment
from pydub.playback import play
from pydub.utils import make_chunks

# Load into PyDub
loop = AudioSegment.from_wav("samples_drumstel/snare.wav")

# Repeat 2 times
loop2 = loop

# Get length in milliseconds
length = len(loop2)
luidheid = loop.dBFS

# # Set fade time
# fade_time = int(length * 0.5)

# # Fade in and out
# faded = loop2.fade_in(fade_time).fade_out(fade_time)

# # Play the faded loop
print(length)
print(luidheid)

play(loop2)



