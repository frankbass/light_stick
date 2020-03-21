float minX;
float maxX;
float minY;
float maxY;
float minZ;
float maxZ;
void minMax(int x, int y, int z) {
   if (x > maxX) {
    maxX = x;
  }
  if (x < minX) {
    minX = x;
  }
  Serial.print("Min X "); Serial.print(minX);
  Serial.print(", Max X "); Serial.println(maxX);
   if (y > maxY) {
    maxY = y;
  }
  if (y < minY) {
    minY = y;
  }
  Serial.print("Min Y "); Serial.print(minY);
  Serial.print(", Max Y "); Serial.println(maxY);

  if (z > maxZ) {
    maxZ = z;
  }
  if (z < minZ) {
    minZ = z;
  }
  Serial.print("Min Z "); Serial.print(minZ);
  Serial.print(", Max Z "); Serial.println(maxZ);
  Serial.println();
}
