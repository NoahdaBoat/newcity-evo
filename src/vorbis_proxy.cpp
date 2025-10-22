#include "vorbis_proxy.hpp"

// Suppress warnings for external STB Vorbis library (v1.22)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-function"
#include "stb_vorbis.c"
#pragma GCC diagnostic pop

int loadOgg(const char *filename, int *channels,
    int *sample_rate, short **output) {
  return stb_vorbis_decode_filename(filename, channels, sample_rate, output);
}

VorbisStream* startOggStream(int* error, const char* filename) {
  return (VorbisStream*) stb_vorbis_open_filename(filename, error, NULL);
}

int getNextOggFrame(VorbisStream* stream, short *buffer, int num_shorts) {
  return stb_vorbis_get_frame_short_interleaved(
      (stb_vorbis*)stream, stream->channels, buffer, num_shorts);
}

void stopOggStream(VorbisStream* stream) {
  stb_vorbis_close((stb_vorbis*)stream);
}

