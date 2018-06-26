#!/usr/bin/env python3

# Generate civil twilight headr
import datetime, pytz, os
import ephem  

tz = pytz.timezone('CET')

output_path = os.path.dirname(os.path.abspath(__file__)) + '/src/Sun.h'
output = open(output_path, 'w')


output.write('''// DO NOT EDIT, WRITTEN BY sun.py!
#ifndef SUN_H
#define SUN_H
#include <avr/pgmspace.h>
const uint16_t TWILIGHT[][2] PROGMEM = {
''')
observer = ephem.Observer()  
observer.lat='49.9622317'  
observer.long='14.3270214'  
observer.elev = 200
observer.horizon = '-6' # -6 = civil twilight,


# minutes of day
def get_minutes(dt):
    return dt.hour*60 + dt.minute


days = 366
for day_of_year in range(days):
    date = datetime.datetime(2018, 1, 1, 12) + datetime.timedelta(day_of_year)
    observer.date = date
    sun = ephem.Sun()  
    sun.compute()
    cet_delta = datetime.timedelta(hours=1) # CET timezone
    twilight_begin = observer.previous_rising(sun, use_center=True).datetime() + cet_delta
    twilight_end = observer.next_setting(sun, use_center=True).datetime() + cet_delta
    output.write( '%s, %s' % (get_minutes(twilight_begin), get_minutes(twilight_end)))
    if day_of_year < days-1:
        output.write(',')
    output.write( '  // %03d %s %s - %s\n' % (day_of_year, date.strftime('%m-%d'), twilight_begin.strftime('%H:%M'), twilight_end.strftime('%H:%M') ) )

output.write('''};
#endif
''')
