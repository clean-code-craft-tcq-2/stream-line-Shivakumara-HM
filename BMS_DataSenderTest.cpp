
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "BMS_DataSender.h"

TEST_CASE("Test to verify the data read from the File")
{
  float Temperature[No_of_Readings], SOC[No_of_Readings], ChargeRate[No_of_Readings] = {0};
  readBMSDataFromFile(Temperature, SOC, ChargeRate);
  float expectedOutput[2][3] = {{20, 23, 0.5},{25, 34, 0.7}};
 
  for(int i = 0; i < 2; i++)
  {
    REQUIRE(Temperature[i] == expectedOutput[i][0]);
    REQUIRE(SOC[i] == expectedOutput[i][1]);
    REQUIRE(ChargeRate[i] == expectedOutput[i][2]);
  }
}
