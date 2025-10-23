#pragma once

void parseBinaryMap();
void initErrorHandling();
void cleanupErrorHandling();
void handleSignal(int sig);
void handleError(const char* format, ...);
void clearErrorState();
void logStacktrace();
bool anyErrorDetected();

