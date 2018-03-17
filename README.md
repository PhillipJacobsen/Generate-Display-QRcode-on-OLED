# Generate_Display_QRcode

Program Features:
    Arduino running on ESP8266 with 128x64 OLED.
    Encodes text string into a matrix representing the QR Code
    Displays the resulting code on the OLED display
    The QRcode will be doubled in size so that each QR code pixel shows up as four pixels on the OLED display.
    Default is lit background with Black QRcode. Inverse can also be displayed however codes seem to scan much better with lit background.

Uses QRCode library by Richard Moore version 0.0.1
        https://github.com/ricmoo/QRCode
