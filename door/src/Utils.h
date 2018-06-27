#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>
#include <DS3231.h>

// Format minutes of day
String formatMinutes(uint16_t minutes);

void EEPROMWriteLong(int address, long value);
long EEPROMReadLong(long address);

// Delay in minutes, may be negative
static const int MORNING_DELAY = 15;
static const int EVENING_DELAY = 15;
void setupTime(DS3231 rtc, bool isSummer);
void printTime(DS3231 rtc);
bool getIsDay(DS3231 rtc);

// Arduino UNO has 1k EEPROM, write is guaranteed 100000x
// static const int MEMORY_OPEN_COUNT_ADDRESS = 0;
static const int MEMORY_OPEN_ADDRESS = 0;
// long EEPROMReadOpenCount();
void EEPROMWriteOpen(short value);
short EEPROMReadOpen();

#endif
