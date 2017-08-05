#include <SoftwareSerial.h>
SoftwareSerial bt(10, 11);

void bt_setup() {
  bt.begin(9600);
}

void bt_send(float n1, float n2) {  //水溫 pH 混濁 鹽度
  int data[12];
  n1 *= 100;
  n2 *= 100;
  data[0] = 'a';
  data[1] = (int)(n1) / 256;
  data[2] = (int)(n1) % 256;
  data[3] = 'b';
  data[4] = (int)(n2) / 256;
  data[5] = (int)(n2) % 256; 

  byte bt_buffer = bt.read();
  if (bt_buffer == 49) {
    for (int j = 0; j < 6; j++) {
      bt.write(data[j]);
    }
  }
}
