#include <EEPROM.h>
#include "Sun.h"
#include "Utils.h"


String formatMinutes(uint16_t minutes) {
    uint8_t hour = minutes / 60;
    uint8_t min = minutes % 60;
    return ((hour < 10) ? "0" : "") + String(hour) + ":" + ((min < 10) ? "0" : "") + String(min);
}

// Set CET, set isSummer=true if there is CET to detract an hour
void setupTime(DS3231 rtc, const char* date, const char* time, bool isSummer) {
    rtc.setDateTime(date, time); 
    RTCDateTime dt = rtc.getDateTime();
    // set CET
    if ( isSummer ) {
        dt.hour -= 1;
    }
    // correction for the time until compiled and uploaded
    dt.second += 8;
    rtc.setDateTime(dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second);
}

// Print to serial for verification,
// can be read on Linux using: busybox microcom -s 9600 /dev/ttyUSB0
// with timestamp: busybox microcom -s 9600 /dev/ttyUSB0 | xargs -IL date +"%H:%M:%S L"
void printTime(DS3231 rtc) {
    RTCDateTime dateTime = rtc.getDateTime();
   
    Serial.println("CET:  " + String(rtc.dateFormat("Y-m-d H:i:s z", dateTime)) + ". day");
    dateTime.hour += 1;
    Serial.println("CEST: " + String(rtc.dateFormat("Y-m-d H:i:s z", dateTime)) + ". day");
    dateTime.hour -= 1;
    
    /*
    dateTime = correctDateTime(rtc, dateTime); 
    Serial.println("CET  (corrected): " + String(rtc.dateFormat("Y-m-d H:i:s z", dateTime)) + ". day");
    dateTime.hour += 1;
    Serial.println("CEST (corrected): " + String(rtc.dateFormat("Y-m-d H:i:s z", dateTime)) + ". day");
    */
}

// The RTC module DS3231 is slow! Tried everything: checking OSF / Aging Offset registers,
// remove battery, less frequent time reading - still the same constant delay   
// PC       Arduino 
// 07:55:26 CEST: 2018-06-29 07:55:24 179. day -> delay=-2s
// 11:27:33 CEST: 2018-07-04 11:16:51 184. day -> delay=-642s
// Delay 640s / 123.53 h = 640s / 5.147 days = 5.18079 s/h = 2.07231 minutes/day

// The new module they quickly sent me, works fine.
/*
RTCDateTime correctDateTime(DS3231 rtc, RTCDateTime dt) {
    uint16_t dayOfYear = rtc.dayInYear(dt.year, dt.month, dt.day);
    uint16_t days = ((dt.year-2000)*365 + dayOfYear) - (18*365+179);
    uint16_t minutesDelay = days * 2.07231;
    //Serial.println("Correct minutesDelay = " + String(minutesDelay));
    uint8_t minutesTotal = dt.minute + minutesDelay;
    dt.hour += minutesTotal / 60;
    dt.minute = minutesTotal  % 60;
    return dt;
}
*/

bool getIsDay(DS3231 rtc) {
    RTCDateTime dateTime = rtc.getDateTime();
    //dateTime = correctDateTime(rtc, dateTime);
    
    uint16_t dayOfYear = rtc.dayInYear(dateTime.year, dateTime.month, dateTime.day);
    //Serial.print(dayOfYear);
    uint16_t begin = pgm_read_word(&(TWILIGHT[dayOfYear-1][0]));
    uint16_t end = pgm_read_word(&(TWILIGHT[dayOfYear-1][1]));
    //Serial.println("minutes = " + String(minutes) + " " + formatMinutes(minutes));    
    //Serial.println(String(begin) + " " + String(end));
    Serial.println("twilight CET:  " + formatMinutes(begin) + " - " + formatMinutes(end));
    Serial.println("twilight CEST: " + formatMinutes(begin+60) + " - " + formatMinutes(end+60));
    uint16_t minutes = dateTime.hour * 60 + dateTime.minute;
    uint16_t begin_delay = begin + MORNING_DELAY;
    uint16_t end_delay = end + EVENING_DELAY;
    Serial.println("twilight + delay CET:  " + formatMinutes(begin_delay) + " - " + formatMinutes(end_delay));
    Serial.println("twilight + delay CEST: " + formatMinutes(begin_delay+60) + " - " + formatMinutes(end_delay+60));
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


