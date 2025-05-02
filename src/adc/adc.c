#include "hal_data.h"
#include "adc.h"
#include "../globals/globals.h"

uint16_t potentiometer_mV = 0, potentiometer_Ra = 0, potentiometer_Rb = 0;
CDS_t brightness;
uint16_t cds_data;

const float ADC_CONST = (float)(3.3/4096);

void Potentiometer_Read()
{
    uint16_t ch0_adc_result;

    R_ADC_Read(&g_adc0_ctrl, ADC_CHANNEL_0, &ch0_adc_result);
    potentiometer_mV = (uint16_t)(ch0_adc_result * ADC_CONST * 1000);
    potentiometer_Rb = (uint16_t)(potentiometer_mV * 3.0303);
    potentiometer_Ra = (uint16_t)(10000 - potentiometer_Rb);
}

void Cds_Sensor_Read()
{
    uint16_t ch2_adc_result;

    R_ADC_Read(&g_adc0_ctrl, ADC_CHANNEL_2, &ch2_adc_result);
    if(ch2_adc_result >= 800){
        cds_data = ch2_adc_result;
        brightness = CDS_dark;
    }
    else{
        cds_data = ch2_adc_result;
        brightness = CDS_light;
    }
}

void ADC_Read_and_Convert(void)
{
    adc_status_t status;

    R_ADC_ScanStart(&g_adc0_ctrl);
    status.state = ADC_STATE_SCAN_IN_PROGRESS;
    while(ADC_STATE_SCAN_IN_PROGRESS == status.state){
        R_ADC_StatusGet(&g_adc0_ctrl, &status);
    }

    Potentiometer_Read();
    Cds_Sensor_Read();
}