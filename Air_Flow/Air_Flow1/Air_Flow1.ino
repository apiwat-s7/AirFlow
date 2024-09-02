#include <Wire.h>
#include <Adafruit_MCP4725.h>
#define voltsIn A0
#define INTERVAL_MESSAGE1 50
#define INTERVAL_MESSAGE2 90
#define INTERVAL_MESSAGE3 200

Adafruit_MCP4725 dac; // constructor

void setup(void) {
  Serial.begin(9600);
  dac.begin(0x60); // The I2C Address: Run the I2C Scanner if you're not sure  
/*
MCP4725A0 address is 0x60 or 0x61
MCP4725A1 address is 0x62 or 0x63
MCP4725A2 address is 0x64 or 0x65
MCP4725A3 address is 0x66 or 0x67
*/  
}

void loop(void) {
  
    uint32_t dac_value;
    int adcValueRead = 0;
    float voltageRead = 0;
    
    float dac_expected_output;

    /*
    if(millis() > time_1 + INTERVAL_MESSAGE1)
    {

    }
    if(millis() > time_2 + INTERVAL_MESSAGE2)
    {
    
    }
    if(millis() > time_3 + INTERVAL_MESSAGE3)
    {
      
    }*/
    int normal = digitalRead(2);
    int S1 = digitalRead(3);
    int S2 = digitalRead(4);
    int S3 = digitalRead(5);
     //normal mode
     
      //S1 mode
    if(S1 == HIGH)
    {
        adcValueRead = analogRead(voltsIn);// 0 - 1024
        voltageRead = (adcValueRead * 5.0 )/ 1024.0;// 0.00 - 5.00 "convert to volt"
        dac_value = adcValueRead*6;//True sum 4.0 increase 0.1 | *1.5
        
        dac_expected_output = (5.0/4096.0) * dac_value;// 0.00 - 5.00 "convert to volt"
        //dac.setVoltage(dac_value, false);// 0 - 1024     

        if(dac_expected_output>5.00)
        {
          dac_expected_output = 5.00;
          dac.setVoltage(4095.999, false);
        }
        else
        {
          dac.setVoltage(dac_value, false);// 0 - 1024 
        }
        
        float votb = dac_expected_output*819.2;  

        Serial.print("Node = S1 ");
        
        Serial.print("analog IN : ");
        Serial.print(adcValueRead);
        
        Serial.print(" analog IN Volt: ");
        Serial.print(voltageRead,3);
        
        Serial.print(" analog OUT : ");
        Serial.print(dac_expected_output);
        
        Serial.print(" analog OUT Volt : ");      
        Serial.println(votb);    
      
    }
      //S2 mode
    else if(S2 == HIGH)
    {   
        adcValueRead = analogRead(voltsIn);// 0 - 1024
        voltageRead = (adcValueRead * 5.0 )/ 1024.0;// 0.00 - 5.00 "convert to volt"
        dac_value = adcValueRead*8.0;//True sum 4.0 increase 0.1
        
        dac_expected_output = (5.0/4096.0) * dac_value;// 0.00 - 5.00 "convert to volt"
        //dac.setVoltage(dac_value, false);// 0 - 1024     

        if(dac_expected_output>=5.0)
        {
          dac_expected_output = 5.00;
          dac.setVoltage(4095.999, false);
        }
        else
        {
          dac.setVoltage(dac_value, false);// 0 - 1024 
        }
        
        float votb = dac_expected_output*819.2;  

        Serial.print("Node = S2 ");
          
        Serial.print("analog IN : ");
        Serial.print(adcValueRead);
        
        Serial.print(" analog IN Volt: ");
        Serial.print(voltageRead,3);
        
        Serial.print(" analog OUT : ");
        Serial.print(dac_expected_output);
        
        Serial.print(" analog OUT Volt : ");      
        Serial.println(votb);    
     
    }
      //S3 mode
    else if(S3 == HIGH)
    {
        adcValueRead = analogRead(voltsIn);// 0 - 1024
        voltageRead = (adcValueRead * 5.0 )/ 1024.0;// 0.00 - 5.00 "convert to volt"
        dac_value = adcValueRead*10.0;//True sum 4.0 increase 0.1
        
        dac_expected_output = (5.0/4096.0) * dac_value;// 0.00 - 5.00 "convert to volt"
         

        if(dac_expected_output>4.50)
        {
          dac_expected_output = 4.50;
          dac.setVoltage(3686.4, false);
        }
        else
        {
          dac.setVoltage(dac_value, false);// 0 - 1024 
        }
        
        float votb = dac_expected_output*819.2;  

        Serial.print("Node = S3 ");
        
        Serial.print("analog IN : ");
        Serial.print(adcValueRead);
        
        Serial.print(" analog IN Volt: ");
        Serial.print(voltageRead,3);
        
        Serial.print(" analog OUT : ");
        Serial.print(dac_expected_output);
        
        Serial.print(" analog OUT Volt : ");      
        Serial.println(votb);    
     
    }   

    else
     {
        adcValueRead = analogRead(voltsIn);// 0 - 1024
        voltageRead = (adcValueRead * 5.0 )/ 1024.0;// 0.00 - 5.00 "convert to volt"
        dac_value = adcValueRead*4.0;//True sum 4.0 increase 0.1
        
        dac_expected_output = (5.0/4096.0) * dac_value;// 0.00 - 5.00 "convert to volt"
        dac.setVoltage(dac_value, false);// 0 - 1024    

        float votb = dac_expected_output*819.2;  
  
        Serial.print("Node = Normal ");
        
        Serial.print("analog IN : ");
        Serial.print(adcValueRead);
        
        Serial.print(" analog IN Volt: ");
        Serial.print(voltageRead,3);
        
        Serial.print(" analog OUT : ");
        Serial.print(dac_expected_output);
        
        Serial.print(" analog OUT Volt : ");      
        Serial.println(votb);    
     }
        
}
