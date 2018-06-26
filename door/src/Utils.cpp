#include <EEPROM.h>
#include "Sun.h"
#include "Utils.h"


String formatMinutes(uint16_t minutes) {
    uint8_t hour = minutes / 60;
    uint8_t min = minutes % 60;
    return String(hour) + ":" + ((min < 10) ? "0" : "") + String(min);
}

// Print to serial for verification,
// can be read on Linux using: busybox microcom -t 9600 /dev/ttyUSB0
void printTime(DS3231 rtc) {
    RTCDateTime dateTime = rtc.getDateTime();
    Serial.println(rtc.dateFormat("Y-m-d H:i:s z", dateTime));
}

bool getIsDay(DS3231 rtc) {
    RTCDateTime dateTime = rtc.getDateTime();
    uint16_t dayOfYear = rtc.dayInYear(dateTime.year, dateTime.month, dateTime.day);
    //Serial.print(dayOfYear);
    uint16_t begin = pgm_read_word(&(TWILIGHT[dayOfYear][0]));
    uint16_t end = pgm_read_word(&(TWILIGHT[dayOfYear][1]));
    //Serial.println(String(begin) + " " + String(end));
    Serial.println("twilight " + formatMinutes(begin) + " " + formatMinutes(end));
    uint16_t minutes = dateTime.hour * 60 + dateTime.minute;
    Serial.println("minutes = " + String(minutes) + " " + formatMinutes(minutes));
    uint16_t begin_delay = begin + MORNING_DELAY;
    uint16_t end_delay = end + EVENING_DELAY;
    Serial.println("with delay " + formatMinutes(begin_delay) + " " + formatMinutes(end_delay));
    bool isDay = minutes > begin_delay && minutes < end_delay;
    //Serial.println("isDay = " + String(isDay));
    
    // Debug, switch every 10 minutes
    //int tens = dateTime.minute/10;
    //isDay = tens % 2;
    
    return isDay;
}

// From https://playground.arduino.cc/Code/EEPROMReadWriteLong
void EEPROMWriteLong(int address, long value) {
    //Decomposition from a long to 4 bytes by using bitshift.
    //One = Most significant -> Four = Least significant byte
    byte four = (value & 0xFF);
    byte three = ((value >> 8) & 0xFF);
    byte two = ((value >> 16) & 0xFF);
    byte one = ((value >> 24) & 0xFF);

    //Write the 4 bytes into the eeprom memory.
    EEPROM.write(address, four);
    EEPROM.write(address + 1, three);
    EEPROM.write(address + 2, two);
    EEPROM.write(address + 3, one);
}

long EEPROMReadLong(long address) {
    //Read the 4 bytes from the eeprom memory.
    long four = EEPROM.read(address);
    long three = EEPROM.read(address + 1);
    long two = EEPROM.read(address + 2);
    long one = EEPROM.read(address + 3);

    //Return the recomposed long by using bitshift.
    return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + ((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
}

/*
long EEPROMReadOpenCount() {
    return EEPROMReadLong(MEMORY_OPEN_COUNT_ADDRESS);
}
*/

void EEPROMWriteOpen(short value) {
    // We keep track of how may times we wrote the value
    //long count = EEPROMReadOpenCount();
    // The initial factory values are 0xFF = -1, we can count from -1
    //EEPROMWriteLong(MEMORY_OPEN_COUNT_ADDRESS, count++);
    EEPROM.write(MEMORY_OPEN_ADDRESS, value);
}

short EEPROMReadOpen() {
    return EEPROM.read(MEMORY_OPEN_ADDRESS);
}


