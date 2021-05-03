#line 1 "c:\\source\\repos\\ed-irrigation\\README.md"
# ad-irrigation

My web-connected, [Arduino][0]-powered, reservoir-drip-irrigation, system.

## Abstract

I have a balcony with no running water from which I hung planters using [Hold It Mate][1] bracket kits. I planted some herbs and flowers and after some time of manual watering decided I needed to automate the process so I could travel.
I bought [a cheap drip irrigation kit][2] that I placed in a [Weatherproof Connection Box][3] to water them on a schedule.
I left on a trip to Spain, came back and all of my plants were dead. `¯\_(ツ)_/¯` The kit didn't work. So I exchanged it for another.
After interpreting the rather confusing configuration, I managed to set up the second kit to pump. That is until I realized the pump did not have enough power to water all of the plants effectively. It had to run for a long time and eventually one of the hoses decoupled within the box and the pump filled the box with water, committing suicide in the box.
Therefore I decided to get a [more powerful Diaphragm pump][4], [hose clamps][5], [Arduino MKR WiFi 1010][6], [a driver for the Diaphragm pump][7] and do what I do best. Write some software to control my drip irrigation system, with the ability to check-in on it over a web server for peace of mind.

_TLDR; if you want something done right, do it yourself._

## Dependencies

- [My fork][8] of [llhttp][9] to an [Arduino][0] library.
- [My fork][10] of [The Boost C++ libraries][11] to Arduino.
- [OPrintStream by me][20]
- [WiFiNINA by Arduino][12]
- [ArduinoJson by Benoît Blanchon][13]
- [RTCZero by Arduino][14]

## Building

* The project was written using [VS Code][15] with [the following extensions][16].
* The repository includes an automatically generated intellisense configuration.
* The project requires an `arduino_secrets.h` file with `#define` statements for secret values such as your Wi-Fi SSID and password.
* The project builds using the Arduino Framework, so either the [Arduino IDE][17] or the [Arduino CLI][18] are required. See the [Arduino VS Code extension][19] documentation on how to configure the framework and perform a basic build.

[0]: https://www.arduino.cc/
[1]: https://www.holditmate.com/
[2]: https://www.amazon.com/gp/product/B0743F4532/
[3]: https://www.amazon.com/gp/product/B00274SLK8/
[4]: https://www.amazon.com/gp/product/B01N75ZIXF/
[5]: https://www.amazon.com/gp/product/B082NHVL9J/
[6]: https://store.arduino.cc/usa/mkr-wifi-1010
[7]: https://www.dfrobot.com/product-1512.html
[8]: https://github.com/Falven/ad-llhttp
[9]: https://github.com/nodejs/llhttp
[10]: https://github.com/Falven/ad-boost
[11]: https://www.boost.org/
[12]: https://www.arduino.cc/en/Reference/WiFiNINA
[13]: https://github.com/bblanchon/ArduinoJson
[14]: https://www.arduino.cc/en/Reference/RTCZero
[15]: https://code.visualstudio.com/
[16]: https://github.com/Falven/ad-irrigation/blob/main/.vscode/extensions.json
[17]: https://www.arduino.cc/en/software
[18]: https://arduino.github.io/arduino-cli/latest/getting-started/
[19]: https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-arduino
[20]: https://github.com/Falven/ad-oprintstream