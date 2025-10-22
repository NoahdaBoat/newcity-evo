#pragma once

#include "part.hpp"

Part* textSpan(vec2 start, float indent, vec2 size, char* text, vec2* end);
Part* textSpan(vec2 start, float indent, vec2 size, char* text, float* y);
Part* spanCenter(vec2 start, float indent, vec2 size, char* text, vec2* end);
Part* spanCenter(vec2 start, float indent, vec2 size, char* text, float* y);

