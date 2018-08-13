#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>
#include <DS3231.h>

// Format minutes of day
String formatMinutes(uint16_t minutes);

void EEPROMWriteLong(int address, long value);
long EEPROMReadLong(long address);

// Delay in minutes, may be negative
// Pozorovano:
// 6.7. 5:30 lezou hned
// 7.7. otevreno 5:00, lezou 5:10 
// 8.7. 20:45 zalezle
// Zacatkem cervence bylo vyhovujici MORNING_DELAY = +45, EVENING_DELAY = -30
// a asi by se vecer dalo jeste zkratit, ale v pulce srpna bylo jiz vecer brzy a rano pozde
// -> nulove delay / srpen
static const int MORNING_DELAY = +0;
static const int EVENING_DELAY = -0;
void setupTime(DS3231 rtc, const char* date, const char* time, bool isSummer);
void printTime(DS3231 rtc);

//RTCDateTime correctDateTime(DS3231 rtc, RTCDateTime dt);
bool getIsDay(DS3231 rtc);

// Arduino UNO has 1k EEPROM, write is guaranteed 100000x
// static const int MEMORY_OPEN_COUNT_ADDRESS = 0;
static const int MEMORY_OPEN_ADDRESS = 0;
// long EEPROMReadOpenCount();
void EEPROMWriteOpen(short value);
short EEPROMReadOpen();

#endif
