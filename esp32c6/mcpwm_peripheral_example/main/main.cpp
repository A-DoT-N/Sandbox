#include <stdint.h>
#include <stdio.h>
#include "reg.h"

extern "C" {
    void app_main(void);
}

void app_main(void)
{
    //Step 0 - select the main clock to use + prescale from 160MHZ -> 1MHZ
    PCR_PWM_CLK_CONF_REG.zero();
    PCR_PWM_CLK_CONF_REG.bits.PCR_PWM_DIV_NUM = 159; // divide by (n+1)
    PCR_PWM_CLK_CONF_REG.bits.PCR_PWM_CLKM_SEL = 1; //160MHz
    PCR_PWM_CLK_CONF_REG.bits.PCR_PWM_CLKM_EN = 1;

    //Step 1 - provide clock access to the peripheral via PCR
    PCR_PWM_CONF_REG.bits.PCR_PWM_CLK_EN = 0x1;
    PCR_PWM_CONF_REG.bits.PCR_PWM_RST_EN = 0x0;

    //Step 2 - pre-scale the MCPWM peripheral base clock from 1MHz -> 10KHz
    MCPWM_CLK_CFG_REG.bits.MCPWM_CLK_PRESCALE = 99; //period of PWM_CLK = PCR_PWM * (PWM_CLK_PRESCALE + 1)

    //Step 3 - configure the timer0 subprocess + prescale timer0 from 10KHz -> 200Hz (5ms period)
    MCPWM_TIMER0_CFG0_REG.bits.MCPWM_TIMER0_PRESCALE = 49; //TIMER0_PWM_CLK = PWM_CLK *  (MCPWM_TIMER0_PRESCALE + 1)
    MCPWM_TIMER0_CFG0_REG.bits.MCPWM_TIMER0_PERIOD = 2; //PWM period == 15ms | 3 clock cycles total (includes 0)
    MCPWM_TIMER0_CFG0_REG.bits.MCPWM_TIMER0_PERIOD_UPMETHOD = 0; //immediate change
    MCPWM_TIMER0_CFG1_REG.bits.MCPWM_TIMER0_MOD = 1; //increasing direction

    //Step 4 - set the duty cycle @50% of the total period
    MCPWM_GEN0_TSTMP_A_REG.bits.MCPWM_GEN0_A = 1; //event triger after 1 clock cycle (33.3% DC)
    MCPWM_GEN0_A_REG.bits.MCPWM_GEN0_A_UTEZ = 2; //toggle high on zero for upward count
    MCPWM_GEN0_A_REG.bits.MCPWM_GEN0_A_UTEA = 1; //toggle low on MCPWM_GEN0_A 
    MCPWM_GEN0_A_REG.bits.MCPWM_GEN0_A_UTEP = 0; //toggle no change on period for upward count

    //Configure GPIO and mux routing
    //Enable pin8 output
    GPIO_ENABLE_W1TS_REG.zero();
    GPIO_ENABLE_W1TS_REG.reg = 1<<1;

    //Configure GPIO Matrix
    GPIO_FUNCn_OUT_SEL_CFG_REG.zero();
    GPIO_FUNCn_OUT_SEL_CFG_REG.bits.GPIO_FUNCn_OUT_SEL = 87;
    GPIO_FUNCn_OUT_SEL_CFG_REG.bits.GPIO_FUNCn_OEN_SEL = 0;

    //Start the PWM
    MCPWM_TIMER0_CFG1_REG.bits.MCPWM_TIMER0_START = 2; //contiuous mode

    while (1)
    {}
}
