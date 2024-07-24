#ifndef __IMXRT1062__
  #error "This sketch should be compiled for Teensy 4.x"
#endif


#include <ACAN_T4.h>
#include "Moteus.h"

Moteus moteus1(
[]() { // lambda function which initializes options
  Moteus::Options options;
  options.id = 1;
  return options;
}
());

Moteus::PositionMode::Command position_cmd;

void setup () {
 // Let the world know we have begun!
  Serial.begin(115200);
  while (!Serial) {}
  Serial.println(F("started"));

  ACAN_T4FD_Settings settings (1000000, DataBitRateFactor::x1) ;

  const uint32_t errorCode = ACAN_T4::can3.beginFD (settings) ;
  if (0 == errorCode) {
    Serial.println ("can3 ok") ;
  }else{
    Serial.print ("Error can3: 0x") ;
    Serial.println (errorCode, HEX) ;
  }

  moteus1.SetStop();
  Serial.println(F("all stopped"));
}


static uint32_t gNextSendMillis = 0;
uint16_t gLoopCount = 0;

void loop () {
  // We intend to send control frames every 20ms.
  const auto time = millis();
  if (gNextSendMillis >= time) { return; }

  gNextSendMillis += 20;
  gLoopCount++;

  Moteus::PositionMode::Command cmd;
  cmd.position = NaN;
  cmd.velocity = 5*::sin(time / 1000.0);
  moteus1.SetPosition(cmd);

  if (gLoopCount % 5 != 0) { return; }

  // Only print our status every 5th cycle, so every 1s.
  Serial.print(F("time "));
  Serial.print(gNextSendMillis);

  auto print_moteus = [](const Moteus::Query::Result& query) {
    Serial.print(static_cast<int>(query.mode));
    Serial.print(F(" "));
    Serial.print(query.position);
    Serial.print(F("  velocity "));
    Serial.print(query.velocity);
  };

  print_moteus(moteus1.last_result().values);
  Serial.println();

}
