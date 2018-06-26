// DO NOT EDIT, WRITTEN BY sun.py!
#ifndef SUN_H
#define SUN_H
#include <avr/pgmspace.h>
// Twilight [begin,end] in CET for every day of year
const uint16_t TWILIGHT[][2] PROGMEM = {
441, 1010,  // 000 01-01 07:21 - 16:50
441, 1011,  // 001 01-02 07:21 - 16:51
441, 1012,  // 002 01-03 07:21 - 16:52
441, 1013,  // 003 01-04 07:21 - 16:53
441, 1014,  // 004 01-05 07:21 - 16:54
441, 1015,  // 005 01-06 07:21 - 16:55
441, 1017,  // 006 01-07 07:21 - 16:57
440, 1018,  // 007 01-08 07:20 - 16:58
440, 1019,  // 008 01-09 07:20 - 16:59
440, 1020,  // 009 01-10 07:20 - 17:00
439, 1021,  // 010 01-11 07:19 - 17:01
439, 1023,  // 011 01-12 07:19 - 17:03
438, 1024,  // 012 01-13 07:18 - 17:04
437, 1025,  // 013 01-14 07:17 - 17:05
437, 1027,  // 014 01-15 07:17 - 17:07
436, 1028,  // 015 01-16 07:16 - 17:08
436, 1029,  // 016 01-17 07:16 - 17:09
435, 1031,  // 017 01-18 07:15 - 17:11
434, 1032,  // 018 01-19 07:14 - 17:12
433, 1034,  // 019 01-20 07:13 - 17:14
432, 1035,  // 020 01-21 07:12 - 17:15
431, 1037,  // 021 01-22 07:11 - 17:17
430, 1038,  // 022 01-23 07:10 - 17:18
429, 1040,  // 023 01-24 07:09 - 17:20
428, 1041,  // 024 01-25 07:08 - 17:21
427, 1043,  // 025 01-26 07:07 - 17:23
426, 1044,  // 026 01-27 07:06 - 17:24
425, 1046,  // 027 01-28 07:05 - 17:26
424, 1047,  // 028 01-29 07:04 - 17:27
423, 1049,  // 029 01-30 07:03 - 17:29
421, 1051,  // 030 01-31 07:01 - 17:31
420, 1052,  // 031 02-01 07:00 - 17:32
419, 1054,  // 032 02-02 06:59 - 17:34
417, 1055,  // 033 02-03 06:57 - 17:35
416, 1057,  // 034 02-04 06:56 - 17:37
415, 1059,  // 035 02-05 06:55 - 17:39
413, 1060,  // 036 02-06 06:53 - 17:40
412, 1062,  // 037 02-07 06:52 - 17:42
410, 1063,  // 038 02-08 06:50 - 17:43
408, 1065,  // 039 02-09 06:48 - 17:45
407, 1067,  // 040 02-10 06:47 - 17:47
405, 1068,  // 041 02-11 06:45 - 17:48
404, 1070,  // 042 02-12 06:44 - 17:50
402, 1071,  // 043 02-13 06:42 - 17:51
400, 1073,  // 044 02-14 06:40 - 17:53
399, 1075,  // 045 02-15 06:39 - 17:55
397, 1076,  // 046 02-16 06:37 - 17:56
395, 1078,  // 047 02-17 06:35 - 17:58
393, 1080,  // 048 02-18 06:33 - 18:00
392, 1081,  // 049 02-19 06:32 - 18:01
390, 1083,  // 050 02-20 06:30 - 18:03
388, 1084,  // 051 02-21 06:28 - 18:04
386, 1086,  // 052 02-22 06:26 - 18:06
384, 1088,  // 053 02-23 06:24 - 18:08
382, 1089,  // 054 02-24 06:22 - 18:09
380, 1091,  // 055 02-25 06:20 - 18:11
378, 1093,  // 056 02-26 06:18 - 18:13
376, 1094,  // 057 02-27 06:16 - 18:14
375, 1096,  // 058 02-28 06:15 - 18:16
373, 1097,  // 059 03-01 06:13 - 18:17
371, 1099,  // 060 03-02 06:11 - 18:19
368, 1101,  // 061 03-03 06:08 - 18:21
366, 1102,  // 062 03-04 06:06 - 18:22
364, 1104,  // 063 03-05 06:04 - 18:24
362, 1105,  // 064 03-06 06:02 - 18:25
360, 1107,  // 065 03-07 06:00 - 18:27
358, 1109,  // 066 03-08 05:58 - 18:29
356, 1110,  // 067 03-09 05:56 - 18:30
354, 1112,  // 068 03-10 05:54 - 18:32
352, 1114,  // 069 03-11 05:52 - 18:34
350, 1115,  // 070 03-12 05:50 - 18:35
348, 1117,  // 071 03-13 05:48 - 18:37
345, 1118,  // 072 03-14 05:45 - 18:38
343, 1120,  // 073 03-15 05:43 - 18:40
341, 1122,  // 074 03-16 05:41 - 18:42
339, 1123,  // 075 03-17 05:39 - 18:43
337, 1125,  // 076 03-18 05:37 - 18:45
335, 1126,  // 077 03-19 05:35 - 18:46
332, 1128,  // 078 03-20 05:32 - 18:48
330, 1130,  // 079 03-21 05:30 - 18:50
328, 1131,  // 080 03-22 05:28 - 18:51
326, 1133,  // 081 03-23 05:26 - 18:53
324, 1135,  // 082 03-24 05:24 - 18:55
321, 1136,  // 083 03-25 05:21 - 18:56
319, 1138,  // 084 03-26 05:19 - 18:58
317, 1139,  // 085 03-27 05:17 - 18:59
315, 1141,  // 086 03-28 05:15 - 19:01
312, 1143,  // 087 03-29 05:12 - 19:03
310, 1144,  // 088 03-30 05:10 - 19:04
308, 1146,  // 089 03-31 05:08 - 19:06
306, 1148,  // 090 04-01 05:06 - 19:08
304, 1149,  // 091 04-02 05:04 - 19:09
301, 1151,  // 092 04-03 05:01 - 19:11
299, 1152,  // 093 04-04 04:59 - 19:12
297, 1154,  // 094 04-05 04:57 - 19:14
295, 1156,  // 095 04-06 04:55 - 19:16
292, 1157,  // 096 04-07 04:52 - 19:17
290, 1159,  // 097 04-08 04:50 - 19:19
288, 1161,  // 098 04-09 04:48 - 19:21
286, 1162,  // 099 04-10 04:46 - 19:22
284, 1164,  // 100 04-11 04:44 - 19:24
281, 1166,  // 101 04-12 04:41 - 19:26
279, 1168,  // 102 04-13 04:39 - 19:28
277, 1169,  // 103 04-14 04:37 - 19:29
275, 1171,  // 104 04-15 04:35 - 19:31
273, 1173,  // 105 04-16 04:33 - 19:33
270, 1174,  // 106 04-17 04:30 - 19:34
268, 1176,  // 107 04-18 04:28 - 19:36
266, 1178,  // 108 04-19 04:26 - 19:38
264, 1179,  // 109 04-20 04:24 - 19:39
262, 1181,  // 110 04-21 04:22 - 19:41
260, 1183,  // 111 04-22 04:20 - 19:43
258, 1185,  // 112 04-23 04:18 - 19:45
256, 1186,  // 113 04-24 04:16 - 19:46
254, 1188,  // 114 04-25 04:14 - 19:48
251, 1190,  // 115 04-26 04:11 - 19:50
249, 1191,  // 116 04-27 04:09 - 19:51
247, 1193,  // 117 04-28 04:07 - 19:53
245, 1195,  // 118 04-29 04:05 - 19:55
243, 1197,  // 119 04-30 04:03 - 19:57
241, 1198,  // 120 05-01 04:01 - 19:58
240, 1200,  // 121 05-02 04:00 - 20:00
238, 1202,  // 122 05-03 03:58 - 20:02
236, 1203,  // 123 05-04 03:56 - 20:03
234, 1205,  // 124 05-05 03:54 - 20:05
232, 1207,  // 125 05-06 03:52 - 20:07
230, 1209,  // 126 05-07 03:50 - 20:09
228, 1210,  // 127 05-08 03:48 - 20:10
226, 1212,  // 128 05-09 03:46 - 20:12
225, 1214,  // 129 05-10 03:45 - 20:14
223, 1215,  // 130 05-11 03:43 - 20:15
221, 1217,  // 131 05-12 03:41 - 20:17
220, 1219,  // 132 05-13 03:40 - 20:19
218, 1220,  // 133 05-14 03:38 - 20:20
216, 1222,  // 134 05-15 03:36 - 20:22
215, 1224,  // 135 05-16 03:35 - 20:24
213, 1225,  // 136 05-17 03:33 - 20:25
212, 1227,  // 137 05-18 03:32 - 20:27
210, 1228,  // 138 05-19 03:30 - 20:28
209, 1230,  // 139 05-20 03:29 - 20:30
207, 1231,  // 140 05-21 03:27 - 20:31
206, 1233,  // 141 05-22 03:26 - 20:33
205, 1234,  // 142 05-23 03:25 - 20:34
203, 1236,  // 143 05-24 03:23 - 20:36
202, 1237,  // 144 05-25 03:22 - 20:37
201, 1239,  // 145 05-26 03:21 - 20:39
200, 1240,  // 146 05-27 03:20 - 20:40
198, 1241,  // 147 05-28 03:18 - 20:41
197, 1243,  // 148 05-29 03:17 - 20:43
196, 1244,  // 149 05-30 03:16 - 20:44
195, 1245,  // 150 05-31 03:15 - 20:45
194, 1246,  // 151 06-01 03:14 - 20:46
194, 1248,  // 152 06-02 03:14 - 20:48
193, 1249,  // 153 06-03 03:13 - 20:49
192, 1250,  // 154 06-04 03:12 - 20:50
191, 1251,  // 155 06-05 03:11 - 20:51
191, 1252,  // 156 06-06 03:11 - 20:52
190, 1253,  // 157 06-07 03:10 - 20:53
189, 1254,  // 158 06-08 03:09 - 20:54
189, 1255,  // 159 06-09 03:09 - 20:55
188, 1255,  // 160 06-10 03:08 - 20:55
188, 1256,  // 161 06-11 03:08 - 20:56
188, 1257,  // 162 06-12 03:08 - 20:57
187, 1258,  // 163 06-13 03:07 - 20:58
187, 1258,  // 164 06-14 03:07 - 20:58
187, 1259,  // 165 06-15 03:07 - 20:59
187, 1259,  // 166 06-16 03:07 - 20:59
187, 1260,  // 167 06-17 03:07 - 21:00
187, 1260,  // 168 06-18 03:07 - 21:00
187, 1260,  // 169 06-19 03:07 - 21:00
187, 1261,  // 170 06-20 03:07 - 21:01
187, 1261,  // 171 06-21 03:07 - 21:01
187, 1261,  // 172 06-22 03:07 - 21:01
188, 1261,  // 173 06-23 03:08 - 21:01
188, 1261,  // 174 06-24 03:08 - 21:01
188, 1261,  // 175 06-25 03:08 - 21:01
189, 1261,  // 176 06-26 03:09 - 21:01
189, 1261,  // 177 06-27 03:09 - 21:01
190, 1261,  // 178 06-28 03:10 - 21:01
190, 1261,  // 179 06-29 03:10 - 21:01
191, 1260,  // 180 06-30 03:11 - 21:00
192, 1260,  // 181 07-01 03:12 - 21:00
193, 1259,  // 182 07-02 03:13 - 20:59
193, 1259,  // 183 07-03 03:13 - 20:59
194, 1258,  // 184 07-04 03:14 - 20:58
195, 1258,  // 185 07-05 03:15 - 20:58
196, 1257,  // 186 07-06 03:16 - 20:57
197, 1257,  // 187 07-07 03:17 - 20:57
198, 1256,  // 188 07-08 03:18 - 20:56
199, 1255,  // 189 07-09 03:19 - 20:55
200, 1254,  // 190 07-10 03:20 - 20:54
201, 1253,  // 191 07-11 03:21 - 20:53
203, 1252,  // 192 07-12 03:23 - 20:52
204, 1251,  // 193 07-13 03:24 - 20:51
205, 1250,  // 194 07-14 03:25 - 20:50
206, 1249,  // 195 07-15 03:26 - 20:49
208, 1248,  // 196 07-16 03:28 - 20:48
209, 1247,  // 197 07-17 03:29 - 20:47
210, 1246,  // 198 07-18 03:30 - 20:46
212, 1244,  // 199 07-19 03:32 - 20:44
213, 1243,  // 200 07-20 03:33 - 20:43
215, 1242,  // 201 07-21 03:35 - 20:42
216, 1240,  // 202 07-22 03:36 - 20:40
218, 1239,  // 203 07-23 03:38 - 20:39
219, 1237,  // 204 07-24 03:39 - 20:37
221, 1236,  // 205 07-25 03:41 - 20:36
222, 1234,  // 206 07-26 03:42 - 20:34
224, 1233,  // 207 07-27 03:44 - 20:33
225, 1231,  // 208 07-28 03:45 - 20:31
227, 1229,  // 209 07-29 03:47 - 20:29
228, 1228,  // 210 07-30 03:48 - 20:28
230, 1226,  // 211 07-31 03:50 - 20:26
232, 1224,  // 212 08-01 03:52 - 20:24
233, 1223,  // 213 08-02 03:53 - 20:23
235, 1221,  // 214 08-03 03:55 - 20:21
236, 1219,  // 215 08-04 03:56 - 20:19
238, 1217,  // 216 08-05 03:58 - 20:17
240, 1215,  // 217 08-06 04:00 - 20:15
241, 1213,  // 218 08-07 04:01 - 20:13
243, 1212,  // 219 08-08 04:03 - 20:12
245, 1210,  // 220 08-09 04:05 - 20:10
246, 1208,  // 221 08-10 04:06 - 20:08
248, 1206,  // 222 08-11 04:08 - 20:06
250, 1204,  // 223 08-12 04:10 - 20:04
251, 1202,  // 224 08-13 04:11 - 20:02
253, 1200,  // 225 08-14 04:13 - 20:00
255, 1198,  // 226 08-15 04:15 - 19:58
256, 1196,  // 227 08-16 04:16 - 19:56
258, 1193,  // 228 08-17 04:18 - 19:53
260, 1191,  // 229 08-18 04:20 - 19:51
261, 1189,  // 230 08-19 04:21 - 19:49
263, 1187,  // 231 08-20 04:23 - 19:47
264, 1185,  // 232 08-21 04:24 - 19:45
266, 1183,  // 233 08-22 04:26 - 19:43
268, 1181,  // 234 08-23 04:28 - 19:41
269, 1179,  // 235 08-24 04:29 - 19:39
271, 1176,  // 236 08-25 04:31 - 19:36
273, 1174,  // 237 08-26 04:33 - 19:34
274, 1172,  // 238 08-27 04:34 - 19:32
276, 1170,  // 239 08-28 04:36 - 19:30
277, 1168,  // 240 08-29 04:37 - 19:28
279, 1165,  // 241 08-30 04:39 - 19:25
281, 1163,  // 242 08-31 04:41 - 19:23
282, 1161,  // 243 09-01 04:42 - 19:21
284, 1159,  // 244 09-02 04:44 - 19:19
285, 1157,  // 245 09-03 04:45 - 19:17
287, 1154,  // 246 09-04 04:47 - 19:14
289, 1152,  // 247 09-05 04:49 - 19:12
290, 1150,  // 248 09-06 04:50 - 19:10
292, 1148,  // 249 09-07 04:52 - 19:08
293, 1145,  // 250 09-08 04:53 - 19:05
295, 1143,  // 251 09-09 04:55 - 19:03
296, 1141,  // 252 09-10 04:56 - 19:01
298, 1139,  // 253 09-11 04:58 - 18:59
300, 1136,  // 254 09-12 05:00 - 18:56
301, 1134,  // 255 09-13 05:01 - 18:54
303, 1132,  // 256 09-14 05:03 - 18:52
304, 1130,  // 257 09-15 05:04 - 18:50
306, 1127,  // 258 09-16 05:06 - 18:47
307, 1125,  // 259 09-17 05:07 - 18:45
309, 1123,  // 260 09-18 05:09 - 18:43
310, 1121,  // 261 09-19 05:10 - 18:41
312, 1118,  // 262 09-20 05:12 - 18:38
313, 1116,  // 263 09-21 05:13 - 18:36
315, 1114,  // 264 09-22 05:15 - 18:34
317, 1112,  // 265 09-23 05:17 - 18:32
318, 1109,  // 266 09-24 05:18 - 18:29
320, 1107,  // 267 09-25 05:20 - 18:27
321, 1105,  // 268 09-26 05:21 - 18:25
323, 1103,  // 269 09-27 05:23 - 18:23
324, 1101,  // 270 09-28 05:24 - 18:21
326, 1098,  // 271 09-29 05:26 - 18:18
327, 1096,  // 272 09-30 05:27 - 18:16
329, 1094,  // 273 10-01 05:29 - 18:14
330, 1092,  // 274 10-02 05:30 - 18:12
332, 1090,  // 275 10-03 05:32 - 18:10
333, 1088,  // 276 10-04 05:33 - 18:08
335, 1085,  // 277 10-05 05:35 - 18:05
336, 1083,  // 278 10-06 05:36 - 18:03
338, 1081,  // 279 10-07 05:38 - 18:01
339, 1079,  // 280 10-08 05:39 - 17:59
341, 1077,  // 281 10-09 05:41 - 17:57
343, 1075,  // 282 10-10 05:43 - 17:55
344, 1073,  // 283 10-11 05:44 - 17:53
346, 1071,  // 284 10-12 05:46 - 17:51
347, 1069,  // 285 10-13 05:47 - 17:49
349, 1067,  // 286 10-14 05:49 - 17:47
350, 1065,  // 287 10-15 05:50 - 17:45
352, 1063,  // 288 10-16 05:52 - 17:43
353, 1061,  // 289 10-17 05:53 - 17:41
355, 1059,  // 290 10-18 05:55 - 17:39
356, 1057,  // 291 10-19 05:56 - 17:37
358, 1055,  // 292 10-20 05:58 - 17:35
359, 1053,  // 293 10-21 05:59 - 17:33
361, 1052,  // 294 10-22 06:01 - 17:32
363, 1050,  // 295 10-23 06:03 - 17:30
364, 1048,  // 296 10-24 06:04 - 17:28
366, 1046,  // 297 10-25 06:06 - 17:26
367, 1044,  // 298 10-26 06:07 - 17:24
369, 1043,  // 299 10-27 06:09 - 17:23
370, 1041,  // 300 10-28 06:10 - 17:21
372, 1039,  // 301 10-29 06:12 - 17:19
373, 1038,  // 302 10-30 06:13 - 17:18
375, 1036,  // 303 10-31 06:15 - 17:16
377, 1034,  // 304 11-01 06:17 - 17:14
378, 1033,  // 305 11-02 06:18 - 17:13
380, 1031,  // 306 11-03 06:20 - 17:11
381, 1030,  // 307 11-04 06:21 - 17:10
383, 1028,  // 308 11-05 06:23 - 17:08
384, 1027,  // 309 11-06 06:24 - 17:07
386, 1025,  // 310 11-07 06:26 - 17:05
387, 1024,  // 311 11-08 06:27 - 17:04
389, 1022,  // 312 11-09 06:29 - 17:02
390, 1021,  // 313 11-10 06:30 - 17:01
392, 1020,  // 314 11-11 06:32 - 17:00
394, 1019,  // 315 11-12 06:34 - 16:59
395, 1017,  // 316 11-13 06:35 - 16:57
397, 1016,  // 317 11-14 06:37 - 16:56
398, 1015,  // 318 11-15 06:38 - 16:55
400, 1014,  // 319 11-16 06:40 - 16:54
401, 1013,  // 320 11-17 06:41 - 16:53
402, 1012,  // 321 11-18 06:42 - 16:52
404, 1011,  // 322 11-19 06:44 - 16:51
405, 1010,  // 323 11-20 06:45 - 16:50
407, 1009,  // 324 11-21 06:47 - 16:49
408, 1008,  // 325 11-22 06:48 - 16:48
410, 1007,  // 326 11-23 06:50 - 16:47
411, 1006,  // 327 11-24 06:51 - 16:46
412, 1005,  // 328 11-25 06:52 - 16:45
414, 1005,  // 329 11-26 06:54 - 16:45
415, 1004,  // 330 11-27 06:55 - 16:44
416, 1003,  // 331 11-28 06:56 - 16:43
418, 1003,  // 332 11-29 06:58 - 16:43
419, 1002,  // 333 11-30 06:59 - 16:42
420, 1002,  // 334 12-01 07:00 - 16:42
421, 1001,  // 335 12-02 07:01 - 16:41
423, 1001,  // 336 12-03 07:03 - 16:41
424, 1001,  // 337 12-04 07:04 - 16:41
425, 1000,  // 338 12-05 07:05 - 16:40
426, 1000,  // 339 12-06 07:06 - 16:40
427, 1000,  // 340 12-07 07:07 - 16:40
428, 1000,  // 341 12-08 07:08 - 16:40
429, 1000,  // 342 12-09 07:09 - 16:40
430, 1000,  // 343 12-10 07:10 - 16:40
431, 1000,  // 344 12-11 07:11 - 16:40
432, 1000,  // 345 12-12 07:12 - 16:40
433, 1000,  // 346 12-13 07:13 - 16:40
434, 1000,  // 347 12-14 07:14 - 16:40
434, 1000,  // 348 12-15 07:14 - 16:40
435, 1000,  // 349 12-16 07:15 - 16:40
436, 1001,  // 350 12-17 07:16 - 16:41
437, 1001,  // 351 12-18 07:17 - 16:41
437, 1001,  // 352 12-19 07:17 - 16:41
438, 1002,  // 353 12-20 07:18 - 16:42
438, 1002,  // 354 12-21 07:18 - 16:42
439, 1003,  // 355 12-22 07:19 - 16:43
439, 1003,  // 356 12-23 07:19 - 16:43
440, 1004,  // 357 12-24 07:20 - 16:44
440, 1004,  // 358 12-25 07:20 - 16:44
440, 1005,  // 359 12-26 07:20 - 16:45
441, 1006,  // 360 12-27 07:21 - 16:46
441, 1007,  // 361 12-28 07:21 - 16:47
441, 1007,  // 362 12-29 07:21 - 16:47
441, 1008,  // 363 12-30 07:21 - 16:48
441, 1009,  // 364 12-31 07:21 - 16:49
441, 1010  // 365 01-01 07:21 - 16:50
};
#endif