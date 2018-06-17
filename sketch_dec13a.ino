// Arduino Pro Micro Config for Gamepad by www.zeroboy.eu - p!

#include <Gamepad.h>
Gamepad gb;
// Use PIN Number connected to PCB
#define BTN_DOWN 4
#define BTN_UP 3
#define BTN_LEFT 2
#define BTN_RIGHT 5
#define BTN_A 6
#define BTN_START A0
#define BTN_Y 7
#define BTN_L1 16
#define BTN_X 8
#define BTN_R1 15
#define BT
#define BTN_B 9
#define BTN_SELECT A1
#define BTN_L2 10
#define BTN_R2 14


void setup() {
Serial.begin(9600);
pinMode(A0, INPUT_PULLUP);
pinMode(A1, INPUT_PULLUP);
for (int x = 0; x < 19; x++) {
pinMode(x, INPUT_PULLUP);

}
}
void loop() {

bool downSet = digitalRead(BTN_DOWN);
bool upSet = digitalRead(BTN_UP); 
bool leftSet = digitalRead(BTN_LEFT);
bool rightSet = digitalRead(BTN_RIGHT);
gb.setLeftYaxis(!upSet ? -127 : !downSet ? 127 : 0); 
gb.setLeftXaxis(!leftSet ? -127 : !rightSet ? 127 : 0);
gb.setButtonState(0, !digitalRead(BTN_A));
gb.setButtonState(1, !digitalRead(BTN_B));
gb.setButtonState(2, !digitalRead(BTN_Y));
gb.setButtonState(3, !digitalRead(BTN_X));
gb.setButtonState(4, !digitalRead(BTN_SELECT));
gb.setButtonState(5, !digitalRead(BTN_START));
gb.setButtonState(6, !digitalRead(BTN_L1));
gb.setButtonState(7, !digitalRead(BTN_R1));
gb.setButtonState(8, !digitalRead(BTN_L2));
gb.setButtonState(9, !digitalRead(BTN_R2));

gb.sendUpdate();
}
