// Date macros:

//supports all dates except "???":
//#define DATE_TO_MONTH(d) ("bhegdlj?kcmf?i"[(d[1] + d[2])%17 - 3]- 'a')
//Supports all dates including"???" (mapped to month 13):
#define DATE_TO_MONTH(d) ("f?i?ncmheg?l?b???d?j?k"[(d[1] + d[2])%24 - 2]- 'a')

#define DATE_TO_YEAR(d) (d[7] == '?' ? 1900 : \
                         (((d[7] - '0') * 1000 ) + (d[8] - '0') * 100 + (d[9] - '0') * 10 + d[10] -'0'))

#define DATE_TO_DAY(d) (d[4] == '?' ? 1 \
                        : ((d[4] == ' ' ? 0 : ((d[4] - '0') * 10)) + d[5] - '0'))

#define TIME_TO_HOUR(t) (t[0] == '?' ? 0 : ((t[0] - '0') * 10 + t[1] - '0'))
#define TIME_TO_MIN(t)  (t[3] == '?' ? 0 : ((t[3] - '0') * 10 + t[4] - '0'))
#define TIME_TO_SEC(t)  (t[6] == '?' ? 0 : ((t[6] - '0') * 10 + t[7] - '0'))
