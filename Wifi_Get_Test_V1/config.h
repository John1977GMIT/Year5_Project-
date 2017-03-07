
#define LED_TYPE_ANODE    1
#define LED_TYPE_CATHODE  0

/*#define LED_RED         D5
#define LED_GREEN       D6
#define LED_BLUE        D7
#define PIN_PIR         D2*/

void setIntensity(PwmOut led, float value) {
#if LED_TYPE_ANODE == 1
  led = 1.0f - value;
#elif LED_TYPE_CATHODE == 1
  led = value;
#else
  printf("LED_TYPE should be ANODE or CATHODE\n");
#endif
}