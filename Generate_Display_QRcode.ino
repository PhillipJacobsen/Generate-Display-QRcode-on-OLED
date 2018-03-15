/**
    QRCode

    A quick example of generating a QR code.

    This prints the QR code to the serial monitor as solid blocks. Each module
    is two characters wide, since the monospace font used in the serial monitor
    is approximately twice as tall as wide.
  https://github.com/ricmoo/QRCode
*/
#define Lcd_X  128
#define Lcd_Y  64

#include "qrcode.h"

#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  Serial.begin(115200);

  u8g2.begin();
  u8g2.clearBuffer();          // clear the internal memory

  u8g2.setContrast(255);

  
  u8g2.setFont(u8g2_font_ncenB12_tr );  // 12 pixel height
  u8g2.drawStr(0, 12, "Starting"); // write something to the internal memory
  u8g2.sendBuffer();          // transfer internal memory to the display
  delay(250);
  u8g2.clearBuffer();          // clear the internal memory

  // Start time
  uint32_t dt = millis();

  // Create the QR code
  QRCode qrcode;
  uint8_t qrcodeData[qrcode_getBufferSize(6)];
  // qrcode_initText(&qrcode, qrcodeData, 1, 0, "{\"a\":\"DE6os4N86ef9bba6kVGurqxmhpBHKctoxY\"}");
  qrcode_initText(&qrcode, qrcodeData, 6, 0, "DE6os4N86ef9bba6kVGurqxmhpBHKctoxY");
 // qrcode_initText(&qrcode, qrcodeData, 3, 0, "ark:AePNZAAtWhLsGFLXtztGLAPnKm98VVC8tJ?amount=20.3");
  
  //  qrcode_initText(&qrcode, qrcodeData, 1, 0, "hello pj");
  // qrcode_initText(&qrcode, qrcodeData, 5, 3, "1BGJvqAuZvr23EixA65PEe5PMLAjVTeyMn");

  // Delta time
  dt = millis() - dt;
  Serial.print("QR Code Generation Time: ");
  Serial.print(dt);
  Serial.print("\n");

  // Top quiet zone
  Serial.print("\n\n\n\n");



  
  for (uint8_t y = 0; y < qrcode.size; y++) {

    // Left quiet zone
    Serial.print("        ");

    // Each horizontal module
    for (uint8_t x = 0; x < qrcode.size; x++) {

      // Print each module (UTF-8 \u2588 is a solid block)
      Serial.print(qrcode_getModule(&qrcode, x, y) ? "\u2588\u2588" : "  ");

    }

    Serial.print("\n");
  }

  // Bottom quiet zone
  Serial.print("\n\n\n\n");



//clear screen
  for (uint8_t y = 0; y < 63; y++) {
    for (uint8_t x = 0; x < 127; x++) {
    u8g2.setDrawColor(1);       //change 0 to make QR code with black background
    u8g2.drawPixel(x, y);
    }
  }

  //uint8_t x0 = (Lcd_X - qrcode.size) / 2;
  //uint8_t y0 = (Lcd_Y - qrcode.size) / 2;

  uint8_t x0 = 12;
  uint8_t y0 =  19;   //16 is the start of the blue oled

  for (uint8_t y = 0; y < qrcode.size; y++) {
    for (uint8_t x = 0; x < qrcode.size; x++) {

      if (qrcode_getModule(&qrcode, x, y) == 0) {     //change to == 1 to make QR code with black background
        u8g2.setDrawColor(1);
        //single size
        u8g2.drawPixel(x0 + x, y0 + y);

        //double size
            //   u8g2.drawPixel(x0 + 2*x,     y0 + 2*y);
             //  u8g2.drawPixel(x0 + 2*x + 1, y0 + 2*y);
            //   u8g2.drawPixel(x0 + 2*x,     y0 + 2*y + 1);
             //  u8g2.drawPixel(x0 + 2*x + 1, y0 + 2*y + 1);


      } else {
        u8g2.setDrawColor(0);
    u8g2.drawPixel(x0 + x, y0 + y);       
      // u8g2.drawPixel(x0 + 2*x,     y0 + 2*y);
             // u8g2.drawPixel(x0 + 2*x + 1, y0 + 2*y);
             //  u8g2.drawPixel(x0 + 2*x,     y0 + 2*y + 1);
             //  u8g2.drawPixel(x0 + 2*x + 1, y0 + 2*y + 1);
      }

    }
  }
  u8g2.sendBuffer();


}

void loop() {

  delay(8000);
    u8g2.setContrast(1);
}




//
//void EncodeDataInLCDAtCenter(uint8_t version,uint8_t ecc,const char *lpsSource){
// //   _ToBeUpdatedFlag = 0;
//
//    uint8_t BufferSize = qrcode_getBufferSize(version);
//    uint8_t qrcodeData[BufferSize];
//    qrcode_initText(&qrcode, qrcodeData, version, ecc, lpsSource);
//    //qrcode_initText(QRCode *qrcode, uint8_t *modules, uint8_t version, uint8_t ecc, const char *data)
//
//    uint8_t x0 = (Lcd_X-qrcode.size)/2;
//    uint8_t y0 = (Lcd_Y-qrcode.size)/2;
//
//    for (uint8_t y = 0; y < qrcode.size; y++) {
//        for (uint8_t x = 0; x < qrcode.size; x++) {
//            if (qrcode_getModule(&qrcode, x, y)) {
//              u8g.setColorIndex(1);
//            }else{
//              u8g.setColorIndex(0);
//            }
//            u8g.drawPixel(x0+x,y0+y);
//        }
//    }
//}
