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
        dac_value = adcValueRead*2.80;//True sum 4.0 increase 0.1 | *1.5
        
        dac_expected_output = (5.0/4096.0) * dac_value;// 0.00 - 5.00 "convert to volt"
        dac.setVoltage(dac_value, false);// 0 - 1024     

        if(dac_expected_output<=0.1)
        {
          dac.setVoltage(0.00, false);
        }
        else
        {
          dac.setVoltage(dac_value, false);// 0 - 1024 
        }
        
        float votb = dac_expected_output*819.2;  
        
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
        dac_value = adcValueRead*1.6;//True sum 4.0 increase 0.1
        
        dac_expected_output = (5.0/4096.0) * dac_value;// 0.00 - 5.00 "convert to volt"
        dac.setVoltage(dac_value, false);// 0 - 1024     

        if(dac_expected_output<=0.1)
        {
          dac.setVoltage(0.00, false);
        }
        else
        {
          dac.setVoltage(dac_value, false);// 0 - 1024 
        }
        
        float votb = dac_expected_output*819.2;  
          
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
        dac_value = adcValueRead*1.2;//True sum 4.0 increase 0.1
        
        dac_expected_output = (5.0/4096.0) * dac_value;// 0.00 - 5.00 "convert to volt"
         

        if(dac_expected_output<=0.10)
        {
          dac.setVoltage(409.6, false);
        }
        else
        {
          dac.setVoltage(dac_value, false);// 0 - 1024 
        }
        
        float votb = dac_expected_output*819.2;  
        
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
