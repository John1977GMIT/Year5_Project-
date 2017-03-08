#include "mbed.h"
#include "rtos.h"
#include "config.h"
#include "security.h"
#include "easy-connect.h"
#include "simple-mbed-client.h"
#include "hcsr04.h"

//Resources
SimpleMbedClient client;
SimpleResourceString name = client.define_resource("device/0/name", "jan", M2MBase::GET_PUT_ALLOWED, true);//User name
SimpleResourceString sensorName = client.define_resource("device/0/sensorName", "jan", M2MBase::GET_PUT_ALLOWED, true);//Module Name
SimpleResourceInt UltraSonicData = client.define_resource("device/0/USdata", 0, M2MBase::GET_ALLOWED);//UltraSonicData
SimpleResourceInt pirCount = client.define_resource("pir/0/count", 0, M2MBase::GET_ALLOWED);


//Prototypes
long distance();
long echo_duration();
long distanceDetect();
int connectWiFi();


//Declare LEDs
DigitalOut red(LED_RED);
DigitalOut green(LED_GREEN);
DigitalOut blue(LED_BLUE);


//HCSR04 sensor(D12, D11);
//set D12 = trigger D11 = echo
DigitalOut trig = D12;
DigitalIn echo = D11;
Timer timer;
long duration,distance_cm;

int run()
{


    return 0;
}


//dictance
long distance()
{
   
    //printf("in distance function\r\n");
    duration = echo_duration();
    distance_cm = (duration/2)/29.1;
     if(distance_cm < 20)
    {
        distanceDetect();
    }
    else
    {
        
        
        }
    printf("end distance function\r\n");
    return distance_cm;
   
}

long echo_duration()
{
    //printf("in echo duration function\r\n");
    timer.reset();  //reset timer
    trig=1;   // trigger low
    wait_us(2); //  wait
    trig=0;   //  trigger high
    wait_us(10);
    trig=1;  // trigger low
    while(!echo); // start pulseIN
    timer.start();
    while(echo);
    timer.stop();
    //printf("end echo duration function\r\n");
    return timer.read_us();

}

long distanceDetect()
{
    DigitalOut led(LED_RED);
    DigitalOut led2(LED_BLUE);
    //an action to demo distance change
    led = !led; // toggle led
    wait(0.2f);
    led = !led2; // toggle led
    wait(0.2f);
    printf("Distance change detected: %d", distance_cm);
    printf("\n\r");
    return distance_cm;
    
}


// Registered callback for mbed Client
//DigitalOut statusLed(LED1, 1);

void registered()
{
    printf("Welcome John Lynam");
    red = 0;
}

int connectWiFi()
{
    
    NetworkInterface* network = easy_connect(true);
   if (!network)
   {
        printf("Connect to internet failed... See serial output.\n");
        return 1;
    }
    struct MbedClientOptions options = client.get_default_options();
    options.DeviceType = "Wifi_Sonic_Test";
    if (!client.setup(options, network))
    {
        printf("Setting up mbed_client failed...\n");
        return 1;
    }
    client.on_registered(&registered);
     
    return 0;
    
}
