#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Simple_login.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Simple_login.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=APP_CFG_Layer/display_cfg/display_cfg.c APP_CFG_Layer/hardware_cfg/hardware_cfg.c APP_CFG_Layer/mode_cfg/mode_cfg.c APP_CFG_Layer/user_cfg/user_cfg.c ECU_Layer/ecu_buzzer/ecu_buzzer.c ECU_Layer/ecu_keypad/ecu_keypad.c ECU_Layer/ecu_lcd/ecu_lcd.c ECU_Layer/ecu_led/ecu_led.c ECU_Layer/push_btn/push_btn.c MCAL_Layer/device_config/device_config.c MCAL_Layer/device_config/ecu_keypad.c MCAL_Layer/hal_gpio/hal_gpio.c application.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/APP_CFG_Layer/display_cfg/display_cfg.p1 ${OBJECTDIR}/APP_CFG_Layer/hardware_cfg/hardware_cfg.p1 ${OBJECTDIR}/APP_CFG_Layer/mode_cfg/mode_cfg.p1 ${OBJECTDIR}/APP_CFG_Layer/user_cfg/user_cfg.p1 ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1 ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1 ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1 ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1 ${OBJECTDIR}/ECU_Layer/push_btn/push_btn.p1 ${OBJECTDIR}/MCAL_Layer/device_config/device_config.p1 ${OBJECTDIR}/MCAL_Layer/device_config/ecu_keypad.p1 ${OBJECTDIR}/MCAL_Layer/hal_gpio/hal_gpio.p1 ${OBJECTDIR}/application.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/APP_CFG_Layer/display_cfg/display_cfg.p1.d ${OBJECTDIR}/APP_CFG_Layer/hardware_cfg/hardware_cfg.p1.d ${OBJECTDIR}/APP_CFG_Layer/mode_cfg/mode_cfg.p1.d ${OBJECTDIR}/APP_CFG_Layer/user_cfg/user_cfg.p1.d ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1.d ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1.d ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1.d ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1.d ${OBJECTDIR}/ECU_Layer/push_btn/push_btn.p1.d ${OBJECTDIR}/MCAL_Layer/device_config/device_config.p1.d ${OBJECTDIR}/MCAL_Layer/device_config/ecu_keypad.p1.d ${OBJECTDIR}/MCAL_Layer/hal_gpio/hal_gpio.p1.d ${OBJECTDIR}/application.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/APP_CFG_Layer/display_cfg/display_cfg.p1 ${OBJECTDIR}/APP_CFG_Layer/hardware_cfg/hardware_cfg.p1 ${OBJECTDIR}/APP_CFG_Layer/mode_cfg/mode_cfg.p1 ${OBJECTDIR}/APP_CFG_Layer/user_cfg/user_cfg.p1 ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1 ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1 ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1 ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1 ${OBJECTDIR}/ECU_Layer/push_btn/push_btn.p1 ${OBJECTDIR}/MCAL_Layer/device_config/device_config.p1 ${OBJECTDIR}/MCAL_Layer/device_config/ecu_keypad.p1 ${OBJECTDIR}/MCAL_Layer/hal_gpio/hal_gpio.p1 ${OBJECTDIR}/application.p1

# Source Files
SOURCEFILES=APP_CFG_Layer/display_cfg/display_cfg.c APP_CFG_Layer/hardware_cfg/hardware_cfg.c APP_CFG_Layer/mode_cfg/mode_cfg.c APP_CFG_Layer/user_cfg/user_cfg.c ECU_Layer/ecu_buzzer/ecu_buzzer.c ECU_Layer/ecu_keypad/ecu_keypad.c ECU_Layer/ecu_lcd/ecu_lcd.c ECU_Layer/ecu_led/ecu_led.c ECU_Layer/push_btn/push_btn.c MCAL_Layer/device_config/device_config.c MCAL_Layer/device_config/ecu_keypad.c MCAL_Layer/hal_gpio/hal_gpio.c application.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Simple_login.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/APP_CFG_Layer/display_cfg/display_cfg.p1: APP_CFG_Layer/display_cfg/display_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/APP_CFG_Layer/display_cfg" 
	@${RM} ${OBJECTDIR}/APP_CFG_Layer/display_cfg/display_cfg.p1.d 
	@${RM} ${OBJECTDIR}/APP_CFG_Layer/display_cfg/display_cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/APP_CFG_Layer/display_cfg/display_cfg.p1 APP_CFG_Layer/display_cfg/display_cfg.c 
	@-${MV} ${OBJECTDIR}/APP_CFG_Layer/display_cfg/display_cfg.d ${OBJECTDIR}/APP_CFG_Layer/display_cfg/display_cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/APP_CFG_Layer/display_cfg/display_cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/APP_CFG_Layer/hardware_cfg/hardware_cfg.p1: APP_CFG_Layer/hardware_cfg/hardware_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/APP_CFG_Layer/hardware_cfg" 
	@${RM} ${OBJECTDIR}/APP_CFG_Layer/hardware_cfg/hardware_cfg.p1.d 
	@${RM} ${OBJECTDIR}/APP_CFG_Layer/hardware_cfg/hardware_cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/APP_CFG_Layer/hardware_cfg/hardware_cfg.p1 APP_CFG_Layer/hardware_cfg/hardware_cfg.c 
	@-${MV} ${OBJECTDIR}/APP_CFG_Layer/hardware_cfg/hardware_cfg.d ${OBJECTDIR}/APP_CFG_Layer/hardware_cfg/hardware_cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/APP_CFG_Layer/hardware_cfg/hardware_cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/APP_CFG_Layer/mode_cfg/mode_cfg.p1: APP_CFG_Layer/mode_cfg/mode_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/APP_CFG_Layer/mode_cfg" 
	@${RM} ${OBJECTDIR}/APP_CFG_Layer/mode_cfg/mode_cfg.p1.d 
	@${RM} ${OBJECTDIR}/APP_CFG_Layer/mode_cfg/mode_cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/APP_CFG_Layer/mode_cfg/mode_cfg.p1 APP_CFG_Layer/mode_cfg/mode_cfg.c 
	@-${MV} ${OBJECTDIR}/APP_CFG_Layer/mode_cfg/mode_cfg.d ${OBJECTDIR}/APP_CFG_Layer/mode_cfg/mode_cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/APP_CFG_Layer/mode_cfg/mode_cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/APP_CFG_Layer/user_cfg/user_cfg.p1: APP_CFG_Layer/user_cfg/user_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/APP_CFG_Layer/user_cfg" 
	@${RM} ${OBJECTDIR}/APP_CFG_Layer/user_cfg/user_cfg.p1.d 
	@${RM} ${OBJECTDIR}/APP_CFG_Layer/user_cfg/user_cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/APP_CFG_Layer/user_cfg/user_cfg.p1 APP_CFG_Layer/user_cfg/user_cfg.c 
	@-${MV} ${OBJECTDIR}/APP_CFG_Layer/user_cfg/user_cfg.d ${OBJECTDIR}/APP_CFG_Layer/user_cfg/user_cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/APP_CFG_Layer/user_cfg/user_cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1: ECU_Layer/ecu_buzzer/ecu_buzzer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_buzzer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1 ECU_Layer/ecu_buzzer/ecu_buzzer.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.d ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1: ECU_Layer/ecu_keypad/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_keypad" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1 ECU_Layer/ecu_keypad/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.d ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1: ECU_Layer/ecu_lcd/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_lcd" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1 ECU_Layer/ecu_lcd/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.d ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1: ECU_Layer/ecu_led/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_led" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1 ECU_Layer/ecu_led/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.d ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/push_btn/push_btn.p1: ECU_Layer/push_btn/push_btn.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/push_btn" 
	@${RM} ${OBJECTDIR}/ECU_Layer/push_btn/push_btn.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/push_btn/push_btn.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/push_btn/push_btn.p1 ECU_Layer/push_btn/push_btn.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/push_btn/push_btn.d ${OBJECTDIR}/ECU_Layer/push_btn/push_btn.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/push_btn/push_btn.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/device_config/device_config.p1: MCAL_Layer/device_config/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/device_config" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/device_config/device_config.p1 MCAL_Layer/device_config/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/device_config/device_config.d ${OBJECTDIR}/MCAL_Layer/device_config/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/device_config/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/device_config/ecu_keypad.p1: MCAL_Layer/device_config/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/device_config" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/device_config/ecu_keypad.p1 MCAL_Layer/device_config/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/device_config/ecu_keypad.d ${OBJECTDIR}/MCAL_Layer/device_config/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/device_config/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/hal_gpio/hal_gpio.p1: MCAL_Layer/hal_gpio/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/hal_gpio" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/hal_gpio/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/hal_gpio/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/hal_gpio/hal_gpio.p1 MCAL_Layer/hal_gpio/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/hal_gpio/hal_gpio.d ${OBJECTDIR}/MCAL_Layer/hal_gpio/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/hal_gpio/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/APP_CFG_Layer/display_cfg/display_cfg.p1: APP_CFG_Layer/display_cfg/display_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/APP_CFG_Layer/display_cfg" 
	@${RM} ${OBJECTDIR}/APP_CFG_Layer/display_cfg/display_cfg.p1.d 
	@${RM} ${OBJECTDIR}/APP_CFG_Layer/display_cfg/display_cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/APP_CFG_Layer/display_cfg/display_cfg.p1 APP_CFG_Layer/display_cfg/display_cfg.c 
	@-${MV} ${OBJECTDIR}/APP_CFG_Layer/display_cfg/display_cfg.d ${OBJECTDIR}/APP_CFG_Layer/display_cfg/display_cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/APP_CFG_Layer/display_cfg/display_cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/APP_CFG_Layer/hardware_cfg/hardware_cfg.p1: APP_CFG_Layer/hardware_cfg/hardware_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/APP_CFG_Layer/hardware_cfg" 
	@${RM} ${OBJECTDIR}/APP_CFG_Layer/hardware_cfg/hardware_cfg.p1.d 
	@${RM} ${OBJECTDIR}/APP_CFG_Layer/hardware_cfg/hardware_cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/APP_CFG_Layer/hardware_cfg/hardware_cfg.p1 APP_CFG_Layer/hardware_cfg/hardware_cfg.c 
	@-${MV} ${OBJECTDIR}/APP_CFG_Layer/hardware_cfg/hardware_cfg.d ${OBJECTDIR}/APP_CFG_Layer/hardware_cfg/hardware_cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/APP_CFG_Layer/hardware_cfg/hardware_cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/APP_CFG_Layer/mode_cfg/mode_cfg.p1: APP_CFG_Layer/mode_cfg/mode_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/APP_CFG_Layer/mode_cfg" 
	@${RM} ${OBJECTDIR}/APP_CFG_Layer/mode_cfg/mode_cfg.p1.d 
	@${RM} ${OBJECTDIR}/APP_CFG_Layer/mode_cfg/mode_cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/APP_CFG_Layer/mode_cfg/mode_cfg.p1 APP_CFG_Layer/mode_cfg/mode_cfg.c 
	@-${MV} ${OBJECTDIR}/APP_CFG_Layer/mode_cfg/mode_cfg.d ${OBJECTDIR}/APP_CFG_Layer/mode_cfg/mode_cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/APP_CFG_Layer/mode_cfg/mode_cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/APP_CFG_Layer/user_cfg/user_cfg.p1: APP_CFG_Layer/user_cfg/user_cfg.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/APP_CFG_Layer/user_cfg" 
	@${RM} ${OBJECTDIR}/APP_CFG_Layer/user_cfg/user_cfg.p1.d 
	@${RM} ${OBJECTDIR}/APP_CFG_Layer/user_cfg/user_cfg.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/APP_CFG_Layer/user_cfg/user_cfg.p1 APP_CFG_Layer/user_cfg/user_cfg.c 
	@-${MV} ${OBJECTDIR}/APP_CFG_Layer/user_cfg/user_cfg.d ${OBJECTDIR}/APP_CFG_Layer/user_cfg/user_cfg.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/APP_CFG_Layer/user_cfg/user_cfg.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1: ECU_Layer/ecu_buzzer/ecu_buzzer.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_buzzer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1 ECU_Layer/ecu_buzzer/ecu_buzzer.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.d ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_buzzer/ecu_buzzer.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1: ECU_Layer/ecu_keypad/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_keypad" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1 ECU_Layer/ecu_keypad/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.d ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_keypad/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1: ECU_Layer/ecu_lcd/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_lcd" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1 ECU_Layer/ecu_lcd/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.d ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_lcd/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1: ECU_Layer/ecu_led/ecu_led.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/ecu_led" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1 ECU_Layer/ecu_led/ecu_led.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.d ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_led/ecu_led.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/push_btn/push_btn.p1: ECU_Layer/push_btn/push_btn.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/push_btn" 
	@${RM} ${OBJECTDIR}/ECU_Layer/push_btn/push_btn.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/push_btn/push_btn.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/push_btn/push_btn.p1 ECU_Layer/push_btn/push_btn.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/push_btn/push_btn.d ${OBJECTDIR}/ECU_Layer/push_btn/push_btn.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/push_btn/push_btn.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/device_config/device_config.p1: MCAL_Layer/device_config/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/device_config" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/device_config/device_config.p1 MCAL_Layer/device_config/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/device_config/device_config.d ${OBJECTDIR}/MCAL_Layer/device_config/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/device_config/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/device_config/ecu_keypad.p1: MCAL_Layer/device_config/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/device_config" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/device_config/ecu_keypad.p1 MCAL_Layer/device_config/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/device_config/ecu_keypad.d ${OBJECTDIR}/MCAL_Layer/device_config/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/device_config/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/hal_gpio/hal_gpio.p1: MCAL_Layer/hal_gpio/hal_gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/hal_gpio" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/hal_gpio/hal_gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/hal_gpio/hal_gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/hal_gpio/hal_gpio.p1 MCAL_Layer/hal_gpio/hal_gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/hal_gpio/hal_gpio.d ${OBJECTDIR}/MCAL_Layer/hal_gpio/hal_gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/hal_gpio/hal_gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/application.p1: application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/application.p1.d 
	@${RM} ${OBJECTDIR}/application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/application.p1 application.c 
	@-${MV} ${OBJECTDIR}/application.d ${OBJECTDIR}/application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Simple_login.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Simple_login.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Simple_login.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/Simple_login.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/Simple_login.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Simple_login.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Simple_login.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
