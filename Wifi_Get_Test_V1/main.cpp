#include "mbed.h"
#include "rtos.h"
#include "config.h"
#include "security.h"
#include "easy-connect.h"
#include "simple-mbed-client.h"

SimpleMbedClient client;

// Declare our peripherals here
/*PwmOut red(LED_RED);
PwmOut green(LED_GREEN);
PwmOut blue(LED_BLUE);*/
DigitalOut red(LED_RED);
DigitalOut green(LED_GREEN);
DigitalOut blue(LED_BLUE);

InterruptIn pir(SW2);

// We need a way to signal from an interrupt context -> main thread, use a Semaphore for it...
Semaphore updates(0);

// YOUR CODE HERE
// Fwd declaration

// Variable that holds whether the light is on because the PIR sensor triggered (and timeout didn't happen yet)
bool ledOnBecauseOfPir = false;

// Timeout based on led/0/timeout, disables the light after a set interval
Timeout pirTimeout;

// Permanent statuses (set by led/0/permanent_status)
#define STATUS_NONE     0
#define STATUS_ON       1
#define STATUS_OFF      2



// Here are our resources:

SimpleResourceString name = client.define_resource("device/0/name", "jan", M2MBase::GET_PUT_ALLOWED, true);//User name
SimpleResourceString sensorName = client.define_resource("device/0/sensorName", "jan", M2MBase::GET_PUT_ALLOWED, true);//Module Name
SimpleResourceInt UltraSonicData = client.define_resource("device/0/USdata", 0, M2MBase::GET_ALLOWED);//UltraSonicData
//SimpleResourceInt pirCount = client.define_resource("pir/0/count", 0, M2MBase::GET_ALLOWED);

// Registered callback for mbed Client
DigitalOut statusLed(LED1, 1);
void registered() {
   printf("Welcome John Lynam");
  statusLed = 0;
}

int main(int, char**) {
  
   sensorName = "Front Window 2";
    name = "John Lynam";
   UltraSonicData = 20;
  /*  
    int i;
    for( i = 0; i < 20; i++)
    {
          wait(0.5);
        i = UltraSonicData;
    }*/
    
  
  red=1;
  green=1;
  blue=1;


  NetworkInterface* network = easy_connect(true);
  if (!network) {
    printf("Connect to internet failed... See serial output.\n");
    return 1;
  }

  struct MbedClientOptions options = client.get_default_options();
  options.DeviceType = "Wifi_Sonic_Test";
  if (!client.setup(options, network)) {
    printf("Setting up mbed_client failed...\n");
    return 1;
  }

  client.on_registered(&registered);
     
}