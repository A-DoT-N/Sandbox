#include "stdint.h"

#ifndef REG_H
#define REG_H

//Register Structs
typedef union{
    uint32_t reg;
    struct{
        uint32_t PCR_RMT_CLK_EN : 1;
        uint32_t PCR_RMT_RST_EN : 1;
    } bits;
    void reset() volatile{
        reg = 0x1;
    }
    void zero() volatile{
        reg = 0x0;
    }
}PCR_RMT_CONF_TYPE;

typedef union{
    uint32_t reg;
    struct{
        uint32_t PCR_RMT_SCLK_DIV_A : 6;
        uint32_t PCR_RMT_SCLK_DIV_B : 6;
        uint32_t PCR_RMT_SCLK_DIV_NUM : 8;
        uint32_t PCR_RMT_SCLK_SEL : 2;
        uint32_t PCR_RMT_SCLK_EN : 1;
    } bits;
    void reset() volatile{
        reg = 0x501000;
    }
    void zero() volatile{
        reg = 0x0;
    }
}PCR_RMT_SCLK_CONF_TYPE;

typedef union{
    uint32_t reg;
    struct{
        uint32_t PCR_PWM_CLK_EN : 1;
        uint32_t PCR_PWM_RST_EN : 1;
        uint32_t : 30;
    } bits;
    void reset() volatile{
        reg = 0x1;
    }
    void zero() volatile{
        reg = 0x0;
    }
}PCR_PWM_CONF_TYPE;

typedef union{
    uint32_t reg;
    struct{
        uint32_t : 12;
        uint32_t PCR_PWM_DIV_NUM : 8; //reset = 0x4
        uint32_t PCR_PWM_CLKM_SEL : 2;
        uint32_t PCR_PWM_CLKM_EN : 1; //reset = 0x1
        uint32_t : 9;
    } bits;
    void reset() volatile{
        reg = 0x404000;
    }
    void zero() volatile{
        reg = 0x0;
    }
}PCR_PWM_CLK_CONF_TYPE;

typedef union{
    uint32_t reg;
    struct{
        uint32_t GPIO_FUNCn_OUT_SEL : 8;
        uint32_t GPIO_FUNCn_OUT_INV_SEL : 1;
        uint32_t GPIO_FUNCn_OEN_SEL : 1;
        uint32_t GPIO_FUNCn_OEN_INV_SEL : 1;
    } bits;
    void reset() volatile{
        reg=0x80;
    }
    void zero() volatile{
        reg = 0x0;
    }
} GPIO_FUNCx_OUT_SEL_CFG_TYPE;

typedef union{
    uint32_t reg;
    void reset() volatile{
        reg=0x0;
    }
    void zero() volatile{
        reg = 0x0;
    }
} GPIO_ENABLE_W1TS_TYPE;

typedef union{
    uint32_t reg;
    struct{
        uint32_t IO_MUX_GPIOn_MCU_OE : 1;
        uint32_t IO_MUX_GPIOn_SLP_SEL : 1;
        uint32_t IO_MUX_GPIOn_MCU_WPD : 1;
        uint32_t IO_MUX_GPIOn_MCU_WPU : 1;
        uint32_t IO_MUX_GPIOn_MCU_IE : 1;
        uint32_t IO_MUX_GPIOn_MCU_DRV : 2;
        uint32_t IO_MUX_GPIOn_FUN_WPD : 1;
        uint32_t IO_MUX_GPIOn_FUN_WPU : 1;
        uint32_t IO_MUX_GPIOn_FUN_IE : 1;
        uint32_t IO_MUX_GPIOn_FUN_DRV : 2;
        uint32_t IO_MUX_GPIOn_MCU_SEL : 3;
        uint32_t IO_MUX_GPIOn_FILTER_EN : 1;

    } bits;
    void reset() volatile{
        reg=0xB00;
    }
    void zero() volatile{
        reg = 0x0;
    }
} IO_MUX_GPIOn_TYPE;

typedef union{
    uint32_t reg;
    struct{
        uint32_t RMT_APB_FIFO_MASK : 1;
        uint32_t RMT_MEM_CLK_FORCE_ON : 1;
        uint32_t RMT_MEM_FORCE_PD : 1;
        uint32_t RMT_MEM_FORCE_PU : 1;
        uint32_t : 27; //reserved
        uint32_t RMT_CLK_EN : 1;
    } bits;
    void reset() volatile{
        reg=0x5000010;
    }
    void zero() volatile{
        reg = 0x0;
    }
} RMT_SYS_CONF_TYPE;

typedef union{
    uint32_t reg;
    struct{
        uint32_t RMT_TX_START : 1;
        uint32_t RMT_MEM_RD_RST : 1;
        uint32_t RMT_APB_MEM_RST : 1;
        uint32_t RMT_TX_CONTI_MODE : 1;
        uint32_t RMT_MEM_TX_WRAP_EN : 1;
        uint32_t RMT_IDLE_OUT_LV : 1;
        uint32_t RMT_IDLE_OUT_EN : 1;
        uint32_t RMT_TX_STOP : 1;
        uint32_t RMT_DIV_CNT : 8;
        uint32_t RMT_MEM_SIZE : 3;
        uint32_t : 1;
        uint32_t RMT_CARRIER_EFF_EN : 1;
        uint32_t RMT_CARRIER_EN : 1;
        uint32_t RMT_CARRIER_OUT_LV : 1;
        uint32_t : 1;
        uint32_t RMT_CONF_UPDATE : 1;
    } bits;
    void reset() volatile{
        reg=0x710200;
    }
    void zero() volatile{
        reg = 0x0;
    }
    void reset_ram_pointers() volatile{
        bits.RMT_MEM_RD_RST = 0x1;
        bits.RMT_APB_MEM_RST = 0x1;
        bits.RMT_MEM_RD_RST = 0x0;
        bits.RMT_APB_MEM_RST = 0x0;
    }
} RMT_CHnCONF0_TYPE;

typedef union{
    uint32_t reg;
    void reset() volatile{
        reg = 0x0;
    }
    void zero() volatile{
        reg = 0x0;
    }
} RMT_CHnDATA_TYPE;

typedef union{
    uint32_t reg;
    struct{
        uint32_t MCPWM_CLK_PRESCALE : 8;
        uint32_t : 24;
    } bits;
    void reset() volatile{
        reg=0x0;
    }
    void zero() volatile{
        reg = 0x0;
    }
} MCPWM_CLK_CFG_TYPE;

typedef union{
    uint32_t reg;
    struct{
        uint32_t MCPWM_TIMER0_PRESCALE : 8;
        uint32_t MCPWM_TIMER0_PERIOD : 16; //reset = 0xff
        uint32_t MCPWM_TIMER0_PERIOD_UPMETHOD : 2;
        uint32_t : 6;
    } bits;
    void reset() volatile{
        reg=0xFF00;
    }
    void zero() volatile{
        reg = 0x0;
    }
} MCPWM_TIMER0_CFG0_TYPE;

typedef union{
    uint32_t reg;
    struct{
        uint32_t MCPWM_TIMER0_START : 3;
        uint32_t MCPWM_TIMER0_MOD : 2;
        uint32_t : 27;
    } bits;
    void reset() volatile{
        reg=0x00;
    }
    void zero() volatile{
        reg = 0x0;
    }
} MCPWM_TIMER0_CFG1_TYPE;

typedef union{
    uint32_t reg;
    struct{
        uint32_t MCPWM_GEN0_A : 16;
        uint32_t : 16;
    } bits;
    void reset() volatile{
        reg=0x00;
    }
    void zero() volatile{
        reg = 0x0;
    }
} MCPWM_GEN0_TSTMP_A_TYPE;

typedef union{
    uint32_t reg;
    struct{
        uint32_t MCPWM_GEN0_A_UTEZ : 2;
        uint32_t MCPWM_GEN0_A_UTEP : 2;
        uint32_t MCPWM_GEN0_A_UTEA : 2;
        uint32_t MCPWM_GEN0_A_UTEB : 2;
        uint32_t MCPWM_GEN0_A_UT0 : 2;
        uint32_t MCPWM_GEN0_A_UT1 : 2;
        uint32_t MCPWM_GEN0_A_DTEZ : 2;
        uint32_t MCPWM_GEN0_A_DTEP : 2;
        uint32_t MCPWM_GEN0_A_DTEA : 2;
        uint32_t MCPWM_GEN0_A_DTEB : 2;
        uint32_t MCPWM_GEN0_A_DT0 : 2;
        uint32_t MCPWM_GEN0_A_DT1 : 2;
        uint32_t : 8;
    } bits;

    void reset() volatile{
        reg=0x00;
    }
    void zero() volatile{
        reg = 0x0;
    }
} MCPWM_GEN0_A_TYPE;

//Custom
#define USER_PIN                        1
//Offset
#define PCR_OFFSET                      0x00096000
#define IO_MUX_OFFSET                   0x00090000
#define GPIO_MATRIX_OFFSET              0x00091000
#define RMT_OFFSET                      0x00006000
#define MCPWM_OFFSET                    0x00014000

// Base
#define PERIPH_BASE                     0x60000000
#define PCR_BASE                        (PERIPH_BASE + PCR_OFFSET)
#define IO_MUX_BASE                     (PERIPH_BASE + IO_MUX_OFFSET)
#define GPIO_MATRIX_BASE                (PERIPH_BASE + GPIO_MATRIX_OFFSET)
#define RMT_BASE                        (PERIPH_BASE + RMT_OFFSET)
#define MCPWM_BASE                      (PERIPH_BASE + MCPWM_OFFSET)

//Register
#define PCR_RMT_CONF_REG                (*(volatile PCR_RMT_CONF_TYPE*) (PCR_BASE + 0x002C))
#define PCR_RMT_SCLK_CONF_REG           (*(volatile PCR_RMT_SCLK_CONF_TYPE*) (PCR_BASE + 0x0030))
#define PCR_PWM_CONF_REG                (*(volatile PCR_PWM_CONF_TYPE*) (PCR_BASE + 0x009C))
#define PCR_PWM_CLK_CONF_REG            (*(volatile PCR_PWM_CLK_CONF_TYPE*) (PCR_BASE + 0x00A0))

#define GPIO_FUNCn_OUT_SEL_CFG_REG      (*(volatile GPIO_FUNCx_OUT_SEL_CFG_TYPE*) (GPIO_MATRIX_BASE + 0x0554 + (4 * USER_PIN)))
#define GPIO_ENABLE_W1TS_REG            (*(volatile GPIO_ENABLE_W1TS_TYPE*) (GPIO_MATRIX_BASE + 0x0024))

#define IO_MUX_GPIOn_REG                (*(volatile IO_MUX_GPIOn_TYPE*) (IO_MUX_BASE + 0x0004 + (4 * USER_PIN)))

#define RMT_SYS_CONF_REG                (*(volatile RMT_SYS_CONF_TYPE*) (RMT_BASE + 0x0068))
#define RMT_CH0CONF0_REG                (*(volatile RMT_CHnCONF0_TYPE*) (RMT_BASE + 0x0010 + (0x4 * RMT_Tx_CH0)))
#define RMT_CHnDATA_REG                 (*(volatile RMT_CHnDATA_TYPE*) (RMT_BASE + 0x0000 + (0x4 * RMT_Tx_CH0)))

#define MCPWM_CLK_CFG_REG               (*(volatile MCPWM_CLK_CFG_TYPE*) (MCPWM_BASE + 0x0000))
#define MCPWM_TIMER0_CFG0_REG           (*(volatile MCPWM_TIMER0_CFG0_TYPE*) (MCPWM_BASE + 0x0004))
#define MCPWM_TIMER0_CFG1_REG           (*(volatile MCPWM_TIMER0_CFG1_TYPE*) (MCPWM_BASE + 0x0008))
#define MCPWM_GEN0_TSTMP_A_REG          (*(volatile MCPWM_GEN0_TSTMP_A_TYPE*) (MCPWM_BASE + 0x0040))
#define MCPWM_GEN0_A_REG                (*(volatile MCPWM_GEN0_A_TYPE*) (MCPWM_BASE + 0x0050))
#define MCPWM_UPDATE_CFG_REG            (*(volatile uint32_t*) (MCPWM_BASE + 0x010C))
#endif