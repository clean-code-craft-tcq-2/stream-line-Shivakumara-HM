
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "BMS_DataSende.h"

/* Prepare sensors data to be sent to console */
void readBMSDataFromFile(float* Temperature, float* SOC, float* ChargeRate)
{
  FILE* fp = fopen("./BMS_SensorsData.txt","r");
  float Temp_readings, SOC_readings, ChargeRate_readings;
  
  for(int i=0; fscanf(fp, "%f \t %f \t %f \n", &Temp_readings,&SOC_readings,&ChargeRate_readings)!=EOF; i++)
    {
      *(Temperature + i) = Temp_readings;
      *(SOC + i) = SOC_readings;
      *(ChargeRate + i) = ChargeRate_readings;
    }
  fclose(fp);
}

/* Send sensors data to console */
void sendBMSDataToConsole(float* Temperature, float* SOC, float* ChargeRate)
{
  float tempToPrint, SOCToPrint, chargeRateToPrint;
  
  for(int i=0;i<No_of_Readings; i++)
  {
    tempToPrint = *(Temperature + i);
    SOCToPrint = *(SOC + i);
    chargeRateToPrint = *(ChargeRate + i);
    printOnConsole(tempToPrint,SOCToPrint,chargeRateToPrint);
  }
}

/* Print Sensors data on console */
void printOnConsole(float TempPrint, float SOCPrint, float ChargeRatePrint)
{
  printf("Temperature: %.2f\t SOC: %.2f\t ChargeRate: %.2f\n", TempPrint,SOCPrint,ChargeRatePrint);
}

/* bms_DataSender main function */
void bms_DataSender(float* Temperature, float* SOC, float* ChargeRate)
{
  readBMSDataFromFile(Temperature, SOC, ChargeRate);
  sendBMSDataToConsole(Temperature, SOC, ChargeRate);  
}
