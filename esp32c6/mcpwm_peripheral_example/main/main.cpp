#include <stdint.h>
#include <stdio.h>
#include "reg.h"

extern "C" {
    void app_main(void);
}

void app_main(void)
{
    //Step 1 - provide clock access to the peripheral via PCR
    PCR_PWM_CLK_CONF_REG.zero();
    PCR_PWM_CLK_CONF_REG.bits.PCR_PWM_DIV_NUM = 159; // divide by (n+1)
    PCR_PWM_CLK_CONF_REG.bits.PCR_PWM_CLKM_SEL = 1; //160MHz
    PCR_PWM_CLK_CONF_REG.bits.PCR_PWM_CLKM_EN = 1;

    PCR_PWM_CONF_REG.bits.PCR_PWM_CLK_EN = 0x1;
    PCR_PWM_CONF_REG.bits.PCR_PWM_RST_EN = 0x0;

    //Step 2 - pre-scale the clock for the PWM
    MCPWM_CLK_CFG_REG.reg = 99 & 0xFF; //period of PWM_CLK = 1us * (PWM_CLK_PRESCALE + 1)

    //Step 3 - configure the timer subprocess clocked @ 10KHz | 100us
    MCPWM_TIMER0_CFG0_REG.bits.MCPWM_TIMER0_PRESCALE = 49;
    MCPWM_TIMER0_CFG0_REG.bits.MCPWM_TIMER0_PERIOD = 2; //period == 2 seconds
    MCPWM_TIMER0_CFG0_REG.bits.MCPWM_TIMER0_PERIOD_UPMETHOD = 0; //immediate change
    MCPWM_TIMER0_CFG1_REG.bits.MCPWM_TIMER0_MOD = 1; //increasing direction

    //Step 4 - set the duty cycle @50% of the total period
    MCPWM_GEN0_TSTMP_A_REG.bits.MCPWM_GEN0_A = 1;
    MCPWM_GEN0_A_REG.bits.MCPWM_GEN0_A_UTEZ = 2;
    MCPWM_GEN0_A_REG.bits.MCPWM_GEN0_A_UTEA = 1;
    MCPWM_GEN0_A_REG.bits.MCPWM_GEN0_A_UTEP = 0;

    //Configure GPIO and mux routing
    //Enable pin8 output
    GPIO_ENABLE_W1TS_REG.zero();
    GPIO_ENABLE_W1TS_REG.reg = 1<<1;

    //Configure GPIO Matrix
    GPIO_FUNCn_OUT_SEL_CFG_REG.zero();
    GPIO_FUNCn_OUT_SEL_CFG_REG.bits.GPIO_FUNCn_OUT_SEL = 87;
    GPIO_FUNCn_OUT_SEL_CFG_REG.bits.GPIO_FUNCn_OEN_SEL = 0;

    //Start the PWM
    MCPWM_UPDATE_CFG_REG = 1<<1;
    MCPWM_UPDATE_CFG_REG = 0<<1;
    MCPWM_TIMER0_CFG1_REG.bits.MCPWM_TIMER0_START = 2; //contiuous mode

    while (1)
    {}
}