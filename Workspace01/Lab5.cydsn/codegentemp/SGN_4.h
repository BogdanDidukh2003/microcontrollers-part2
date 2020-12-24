/*******************************************************************************
* File Name: SGN_4.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SGN_4_H) /* Pins SGN_4_H */
#define CY_PINS_SGN_4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SGN_4_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} SGN_4_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   SGN_4_Read(void);
void    SGN_4_Write(uint8 value);
uint8   SGN_4_ReadDataReg(void);
#if defined(SGN_4__PC) || (CY_PSOC4_4200L) 
    void    SGN_4_SetDriveMode(uint8 mode);
#endif
void    SGN_4_SetInterruptMode(uint16 position, uint16 mode);
uint8   SGN_4_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void SGN_4_Sleep(void); 
void SGN_4_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(SGN_4__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define SGN_4_DRIVE_MODE_BITS        (3)
    #define SGN_4_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SGN_4_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the SGN_4_SetDriveMode() function.
         *  @{
         */
        #define SGN_4_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define SGN_4_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define SGN_4_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define SGN_4_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define SGN_4_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define SGN_4_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define SGN_4_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define SGN_4_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define SGN_4_MASK               SGN_4__MASK
#define SGN_4_SHIFT              SGN_4__SHIFT
#define SGN_4_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SGN_4_SetInterruptMode() function.
     *  @{
     */
        #define SGN_4_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define SGN_4_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define SGN_4_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define SGN_4_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(SGN_4__SIO)
    #define SGN_4_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(SGN_4__PC) && (CY_PSOC4_4200L)
    #define SGN_4_USBIO_ENABLE               ((uint32)0x80000000u)
    #define SGN_4_USBIO_DISABLE              ((uint32)(~SGN_4_USBIO_ENABLE))
    #define SGN_4_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define SGN_4_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define SGN_4_USBIO_ENTER_SLEEP          ((uint32)((1u << SGN_4_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << SGN_4_USBIO_SUSPEND_DEL_SHIFT)))
    #define SGN_4_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << SGN_4_USBIO_SUSPEND_SHIFT)))
    #define SGN_4_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << SGN_4_USBIO_SUSPEND_DEL_SHIFT)))
    #define SGN_4_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(SGN_4__PC)
    /* Port Configuration */
    #define SGN_4_PC                 (* (reg32 *) SGN_4__PC)
#endif
/* Pin State */
#define SGN_4_PS                     (* (reg32 *) SGN_4__PS)
/* Data Register */
#define SGN_4_DR                     (* (reg32 *) SGN_4__DR)
/* Input Buffer Disable Override */
#define SGN_4_INP_DIS                (* (reg32 *) SGN_4__PC2)

/* Interrupt configuration Registers */
#define SGN_4_INTCFG                 (* (reg32 *) SGN_4__INTCFG)
#define SGN_4_INTSTAT                (* (reg32 *) SGN_4__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define SGN_4_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(SGN_4__SIO)
    #define SGN_4_SIO_REG            (* (reg32 *) SGN_4__SIO)
#endif /* (SGN_4__SIO_CFG) */

/* USBIO registers */
#if !defined(SGN_4__PC) && (CY_PSOC4_4200L)
    #define SGN_4_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define SGN_4_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define SGN_4_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define SGN_4_DRIVE_MODE_SHIFT       (0x00u)
#define SGN_4_DRIVE_MODE_MASK        (0x07u << SGN_4_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins SGN_4_H */


/* [] END OF FILE */
