#define  No_of_Readings 50
void readBMSDataFromFile(float* Temperature, float* SOC, float* ChargeRate);
void printOnConsole(float TempPrint, float SOCPrint, float ChargeRatePrint);
void sendBMSDataToConsole(float* Temperature, float* SOC, float* ChargeRate);
void BMS_DataSender();
