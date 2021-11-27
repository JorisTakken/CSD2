#include "speaker.h"


int main()
{
    Speaker speaker_right;
    Speaker speaker_left;

    speaker_left.make_sound(400.0);
    speaker_left.filter_freq=402.4;
    speaker_left.make_sound(400.0);
}