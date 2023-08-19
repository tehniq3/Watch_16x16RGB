# Watch_16x16RGB
based on http://arduino-kid.ru/blog/chasy-na-svetodiodakh-ws2812 and https://youtu.be/1oqfN3A-YfY

my article with RTC clock: https://nicuflorica.blogspot.com/2023/02/ceas-rtc-pe-afisaj-16x16-cu-leduri.html
can be use the sketches: Watch16x16_1b5.ino .. Watch16x16_2b.ino

![clock](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEi6ZHpOWyG0e44hcS2nAZaQbHIwU_0hrMingrLSr85IlEfztt706-e7Lt-H-xGBrB5zaHnrtuFwYEJjMQFfxVqt7InFgpXoYg-UQGFvELpoWxeYw8m9OzFjK1LgdRd11wwlXLTNfbHFNtV-5dtg9LFIoZscQR0COq0G3Mu9MG_5L-I63zKIQLQjWXH_iQ/w150-h200/a%20doua%20varianta.jpg)
![clock2](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEhCfKNYVYDh8-k0lR3-iErTuQOH7HNkbgrLbYBtCMJHtF4-w9smn35Xv2YW5Q-I7S4SeVrGKfZNIr1LNqlpJPxjPW5QC3tqUdiFU8ZlL4FlAOZtD7DXwj5GtzuTqwYC1dHuWa4GTo6ELOW_8mpU6Psd90MGOYtFpvGcRVfILwhKrZ98YNlltQoxDCmOOg/w200-h150/monaj_jessie.jpg)

![schematic](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEhwNWdLbVvvZjwwPd2KiqoSb7TZp6hNk57Hglf9iQRp1DFigTnR4hicxbQJwr1dPdYEznKT1hpbogKn6FJztrLPFx9rD8pNncaHBqOAYbpv-W13Bsesueb4QvZnrZnO9AkOzROpVYJyn60XU2lwA7klTdatBtiSumMnJV_BSe6angACnxX8lZUmJ3Z67g/w200-h79/RTC_clock_on_16x16_adresable_led_display_schematic_v1.png)

RTC schematic at high resolution: https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEhwNWdLbVvvZjwwPd2KiqoSb7TZp6hNk57Hglf9iQRp1DFigTnR4hicxbQJwr1dPdYEznKT1hpbogKn6FJztrLPFx9rD8pNncaHBqOAYbpv-W13Bsesueb4QvZnrZnO9AkOzROpVYJyn60XU2lwA7klTdatBtiSumMnJV_BSe6angACnxX8lZUmJ3Z67g/s1487/RTC_clock_on_16x16_adresable_led_display_schematic_v1.png

my article with NTP clock: https://nicuflorica.blogspot.com/2023/02/ceas-ntp-cu-reglaj-ora-varaiarna-pe.html
can be use sketch: https://github.com/tehniq3/Watch_16x16RGB/blob/main/Watch16x16_3a.ino

![NTP clock](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEiHQEjziqusA_V94XB-NZ3krzghrBXzPaxSkNpXzEWAPM2j9tVUhWT02Vhah5oTYyvcISPAKkwjMMLWVcPUH3gCr3lgfthuMSP0UaIySziAZozzXVUi58mPpdlAYKTlzbG4KJhhNzWMaIBKjSRe7_DdgnV3GRW-S10sVPDHbNLTL6iEUL5zsmZGv7VJQg/w200-h150/NTP_clock_consum.jpg)

![NTP DST clock schematic](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEhk6AjQf2jRfvrX-MfhmErwuYgoOHDXwQaznXysAdoFp8JKbtjXozPrQ_HoP1Q5ljLZ4VqXDSN7V-29sXgZwc1HupmYufMKol0kwk24gmDvzo6zkwKHnf3DSlWE_31K8ySVLHcvoLJLhKaq1XvAtaeKdL6AVT4qrNTj_176NYVNHixGgRdE9Wmms5fEQw/s320/NTP_Clock_DST_16x16_WS2812_schematic.png)

NTP schematic at high resolution: https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEhk6AjQf2jRfvrX-MfhmErwuYgoOHDXwQaznXysAdoFp8JKbtjXozPrQ_HoP1Q5ljLZ4VqXDSN7V-29sXgZwc1HupmYufMKol0kwk24gmDvzo6zkwKHnf3DSlWE_31K8ySVLHcvoLJLhKaq1XvAtaeKdL6AVT4qrNTj_176NYVNHixGgRdE9Wmms5fEQw/s1178/NTP_Clock_DST_16x16_WS2812_schematic.png

RTC clock with DS18B20 (D9 pin) used "Watch16x16_2c.ino" sketch
