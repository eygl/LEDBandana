#include <Adafruit_NeoPixel.h>

#define ROW_0_PIN 27
#define LED_COUNT 64
#define MAX_BRIGHTNESS 64

Adafruit_NeoPixel row0(LED_COUNT, ROW_0_PIN, NEO_GRB + NEO_KHZ800);


void setWhite();
void drawMouth(int wait);
void drawCircle(int wait);

void setup() {
  row0.begin();
  row0.show(); // Initialize all pixels to 'off'
  row0.setBrightness(MAX_BRIGHTNESS);
  //setWhite();
  
}



int counter = 0;
int maxLoop = 2000;

void loop() {
  counter++;
  if (counter < maxLoop/2)
  {
    row0.clear();
    drawCircle(10);
  }
  else 
  {
    row0.clear();
    rainbow(10);
  }
  if (counter > maxLoop) counter = 0;
}

void rainbow(int wait) {

for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<row0.numPixels(); i++) { 
      int pixelHue = firstPixelHue + (i * 65536L / row0.numPixels());
      row0.setPixelColor(i, row0.gamma32(row0.ColorHSV(pixelHue)));
    }
    row0.show(); 
    delay(wait);  

    counter++;
    if (counter > maxLoop) return;
  }
}

void setWhite()
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    row0.setPixelColor(i,255,255,255,MAX_BRIGHTNESS);
  }
}

void clearScreen()
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    row0.setPixelColor(i,0,0,0,MAX_BRIGHTNESS);
  }
}

void drawMouth(int wait)
{
  int mouth [] = 
  {0,0,0,1,1,
   0,0,1,0,0,
   0,1,0,0,0,
   0,0,0,1,0,

   1,0,0,0,0,
   0,0,0,0,1,
   1,0,0,0,0,
   0,0,0,0,1,
   
   0,1,0,0,0,
   0,0,0,1,0,
   0,0,1,0,0,
   1,1,0,0,0};

  for (int i = 0; i < row0.numPixels(); i++)
  {
    if (mouth[i] == 1) row0.setPixelColor(i,255,255,255,MAX_BRIGHTNESS);
    else row0.setPixelColor(i,1,1,1,MAX_BRIGHTNESS);
  }
  row0.show();
  delay(wait);
}


int red = 255;
int green = 0;
int blue = 0;
void drawCircle(int wait)
{
  int circle [] = 
  {0,0,0,0,0,
   0,0,0,0,0,
   0,0,0,0,0,
   0,0,1,0,0,
   
   0,1,1,1,0,
   1,1,1,1,1,
   1,1,1,1,1,
   0,1,1,1,0,
   
   0,0,1,0,0,
   0,0,0,0,0,
   0,0,0,0,0,
   0,0,0,0,0,
   0,0,0,0,0};

  for (int i = 0; i < row0.numPixels(); i++)
  {
    if (circle[i] == 1) row0.setPixelColor(i,red,green,blue,MAX_BRIGHTNESS);
    else row0.setPixelColor(i,blue,red,green,MAX_BRIGHTNESS);
  }


  if (red > 0 && blue == 0)
  {
    red--;
    green++;
  }
  if (green > 0 && red == 0)
  {
    green--;
    blue++;
  }
  if (blue > 0 && green == 0)
  {
    blue--;
    red++;
  }


  row0.show();
  delay(10);
}
