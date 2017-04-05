//************* Main.cpp mbed **********************
#include "mbed.h"
#include "function.h"

Ticker flipper;//Internal ISR

int main() {
    printf("Main\n\r");
    
    while(1)
    { 
    wifiConnection();
    }  
  } 
//******************** fontion.h mbed *****************************

#include "mbed.h"
#include <TCPSocket.h>
#include <EthInterface.h>
#include "EthernetInterface.h"
#include "string.h"
#include "ESP8266Interface.h"

ESP8266Interface wifi(D1, D0);
int wifiConnection();
void ClearBuffer();
char rbuffer[300];
int rcount;

int wifiConnection()
{
    
//start of connection to linux machine with wifi
    printf("Connecting...\n\r");
    int ret = wifi.connect("iPhone","Kingpin086+", NSAPI_SECURITY_WPA_WPA2);   
    if (ret != 0) {
        printf("\r\n*** WiFi Connection error ***\r\n");
        return -1;
    }
    printf("IP Address is %s\r\n", wifi.get_ip_address());    
    //create socket
    TCPSocket sock;
    sock.open(&wifi);
   
    int ret2 = sock.connect("anywherealarm.hopto.org", 8086);//mint server working
   
    if(ret2 != 0)//if this is a zero it is connected
    {
       printf("*** Socket connection error ***\r\n");
       return -1;
    }
    sock.set_blocking(false);
    
     //sending to java server
    printf("Sending char[] to ip address...\r\n");
    char sbuffer[] = "Hello from client JOHN\r\n\r\n";
    int scount = sock.send(sbuffer, sizeof sbuffer);
    printf("sent %d [%.*s]\r\n", scount, strstr(sbuffer, "\r\n")-sbuffer, sbuffer);
    
    //recieve from java server
    while( 1) {//waits for something to be in the buffer  (timing issues)
       // int32_t val =sock.recv(rbuffer, sizeof(rbuffer) -1);
         rcount =sock.recv(rbuffer, sizeof(rbuffer) -1);
        //printf("val = %d",val);
        if(rcount >0)
            break;
    }
    printf("recv %d [%.*s]\r\n", rcount, strstr(rbuffer, "\r\n")-rbuffer, rbuffer);
    printf("Done\r\n"); 
    sock.close();
    wifi.disconnect();
    return 0;
}
    //End of connection to linux machine with wifi  
 
void ClearBuffer(){
    for(int i = 0; i <= rcount; i++)
        rbuffer[i] = '\0';
}   
    
