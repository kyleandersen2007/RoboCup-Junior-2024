#include <Pixy2.h>

Pixy2 pixy;

void setup() {
  Serial.begin(115200);
  pixy.init();
}

void loop() {
  int blocks = pixy.ccc.getBlocks();

  if (blocks) {
    for (int i = 0; i < blocks; i++) {
      // Get the width and height of the detected object
      int width = pixy.ccc.blocks[i].m_width;
      int height = pixy.ccc.blocks[i].m_height;

      // Calculate the distance to the object based on its size (you need to calibrate this based on your setup)
      float distance = calculateDistance(width, height);

      Serial.print("Object at X: ");
      Serial.print(pixy.ccc.blocks[i].m_x);
      Serial.print(", Y: ");
      Serial.print(pixy.ccc.blocks[i].m_y);
      Serial.print(", Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
    }
  }
}

float calculateDistance(int width, int height) {
  float knownWidth = 5.0;  // Known width of the object in cm
  float focalLength = 500.0;  // Focal length of the camera lens in pixels (you need to measure this)
  float pixelWidth = width;  // Width of the object in pixels

  float distance = (knownWidth * focalLength) / (pixelWidth);
  return distance;
}
