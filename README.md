# Generate_Display_QRcode

Program Features:
    Arduino running on ESP8266 with 128x64 OLED.
    Encodes text string into a matrix representing the QR Code.
    Displays the resulting code on the OLED display.
    The QRcode will be doubled in size so that each QR code pixel shows up as four pixels on the OLED display.
    Default is lit background with Black QRcode. Inverse can also be displayed however codes seem to scan much better with lit background.

Attributions
--

Uses the [QRCode library by Richard Moore version](https://github.com/ricmoo/QRCode) (0.0.1) which is based off of the [QR Code generator by Nayuki](https://github.com/nayuki/QR-Code-generator).

Also uses the [U8g2 library by olikraus](https://github.com/olikraus/u8g2).
