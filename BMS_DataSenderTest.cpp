
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "BMS_DataSender.h"

TEST_CASE("Test to verify the sensors data sent to console")
{
  float Temperature_loc, SOC_loc, ChargeRate_loc;
  float Temperature[No_of_Readings], SOC[No_of_Readings], ChargeRate[No_of_Readings] = {0};
  float ExpectedTemperature[No_of_Readings], ExpectedSOC[No_of_Readings], ExpectedChargeRate[No_of_Readings] = {0};
  readBMSDataFromFile(Temperature, SOC, ChargeRate);
    
  FILE *file = fopen("./BMS_SensorsData.txt","r");                                                                  
  for(int i=0; i<No_of_Readings; i++)
   {
     if (file!=NULL) 
     {
        for(int i=0; fscanf(file, "%f \t %f \t %f \n", &Temperature_loc,&SOC_loc,&ChargeRate_loc)!=EOF; i++)
        {
            ExpectedTemperature[i] = Temperature_loc;
            ExpectedSOC[i] = SOC_loc;
			ExpectedChargeRate = ChargeRate_loc;
        }
     }
       
    REQUIRE(Temperature[i] == ExpectedTemperature[i]);
    REQUIRE(SOC[i] == ExpectedSOC[i]);
    REQUIRE(ChargeRate[i] == ExpectedChargeRate[i]);
   }
   fclose(file);
}
