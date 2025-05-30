/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = r_icu_isr, /* ICU IRQ11 (External pin interrupt 11) */
            [1] = r_icu_isr, /* ICU IRQ12 (External pin interrupt 12) */
            [2] = r_icu_isr, /* ICU IRQ13 (External pin interrupt 13) */
            [3] = r_icu_isr, /* ICU IRQ14 (External pin interrupt 14) */
            [4] = sci_uart_rxi_isr, /* SCI0 RXI (Receive data full) */
            [5] = sci_uart_txi_isr, /* SCI0 TXI (Transmit data empty) */
            [6] = sci_uart_tei_isr, /* SCI0 TEI (Transmit end) */
            [7] = sci_uart_eri_isr, /* SCI0 ERI (Receive error) */
            [8] = agt_int_isr, /* AGT0 INT (AGT interrupt) */
            [9] = agt_int_isr, /* AGT1 INT (AGT interrupt) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ11), /* ICU IRQ11 (External pin interrupt 11) */
            [1] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ12), /* ICU IRQ12 (External pin interrupt 12) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ13), /* ICU IRQ13 (External pin interrupt 13) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ14), /* ICU IRQ14 (External pin interrupt 14) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_SCI0_RXI), /* SCI0 RXI (Receive data full) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TXI), /* SCI0 TXI (Transmit data empty) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_SCI0_TEI), /* SCI0 TEI (Transmit end) */
            [7] = BSP_PRV_IELS_ENUM(EVENT_SCI0_ERI), /* SCI0 ERI (Receive error) */
            [8] = BSP_PRV_IELS_ENUM(EVENT_AGT0_INT), /* AGT0 INT (AGT interrupt) */
            [9] = BSP_PRV_IELS_ENUM(EVENT_AGT1_INT), /* AGT1 INT (AGT interrupt) */
        };
        #endif
