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
ifeq "$(wildcard nbproject/Makefile-local-XC16_24FJ512GU410.mk)" "nbproject/Makefile-local-XC16_24FJ512GU410.mk"
include nbproject/Makefile-local-XC16_24FJ512GU410.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=XC16_24FJ512GU410
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/pic24_blink_led.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/pic24_blink_led.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=configuration_bits.c interrupts.c main.c system.c traps.c user.c LCD.c lcd_16seg.c lcd_7seg.c adc.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/configuration_bits.o ${OBJECTDIR}/interrupts.o ${OBJECTDIR}/main.o ${OBJECTDIR}/system.o ${OBJECTDIR}/traps.o ${OBJECTDIR}/user.o ${OBJECTDIR}/LCD.o ${OBJECTDIR}/lcd_16seg.o ${OBJECTDIR}/lcd_7seg.o ${OBJECTDIR}/adc.o
POSSIBLE_DEPFILES=${OBJECTDIR}/configuration_bits.o.d ${OBJECTDIR}/interrupts.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/system.o.d ${OBJECTDIR}/traps.o.d ${OBJECTDIR}/user.o.d ${OBJECTDIR}/LCD.o.d ${OBJECTDIR}/lcd_16seg.o.d ${OBJECTDIR}/lcd_7seg.o.d ${OBJECTDIR}/adc.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/configuration_bits.o ${OBJECTDIR}/interrupts.o ${OBJECTDIR}/main.o ${OBJECTDIR}/system.o ${OBJECTDIR}/traps.o ${OBJECTDIR}/user.o ${OBJECTDIR}/LCD.o ${OBJECTDIR}/lcd_16seg.o ${OBJECTDIR}/lcd_7seg.o ${OBJECTDIR}/adc.o

# Source Files
SOURCEFILES=configuration_bits.c interrupts.c main.c system.c traps.c user.c LCD.c lcd_16seg.c lcd_7seg.c adc.c



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
	${MAKE}  -f nbproject/Makefile-XC16_24FJ512GU410.mk dist/${CND_CONF}/${IMAGE_TYPE}/pic24_blink_led.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ512GU410
MP_LINKER_FILE_OPTION=,--script=p24FJ512GU410.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/configuration_bits.o: configuration_bits.c  .generated_files/1a17aac9884816cbc4585459a74ea38b5d69159d.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuration_bits.o.d 
	@${RM} ${OBJECTDIR}/configuration_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  configuration_bits.c  -o ${OBJECTDIR}/configuration_bits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/configuration_bits.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/interrupts.o: interrupts.c  .generated_files/5323c4a15b0dc35eb3b81d02a992a2c4f53b9ddd.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupts.o.d 
	@${RM} ${OBJECTDIR}/interrupts.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  interrupts.c  -o ${OBJECTDIR}/interrupts.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/interrupts.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/8e09ecc62c11fdca88224cf97dfcab6de0564e39.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/system.o: system.c  .generated_files/967bc53c0fdcc1c17ee0e1b2922c658737be75c8.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/traps.o: traps.c  .generated_files/10312116c01aeec1d398d10e3f56f7eb6ad47e91.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/traps.o.d 
	@${RM} ${OBJECTDIR}/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  traps.c  -o ${OBJECTDIR}/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/traps.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/user.o: user.c  .generated_files/18fb9bd903dcf4000b63e34a907b5984d0a4e666.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/user.o.d 
	@${RM} ${OBJECTDIR}/user.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  user.c  -o ${OBJECTDIR}/user.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/user.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/LCD.o: LCD.c  .generated_files/2723a51b32f76d5af67490665c8828b5de821fb8.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD.o.d 
	@${RM} ${OBJECTDIR}/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  LCD.c  -o ${OBJECTDIR}/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/LCD.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lcd_16seg.o: lcd_16seg.c  .generated_files/1df2e004ed03fd9635b7de556c11d8d0ccada6d1.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd_16seg.o.d 
	@${RM} ${OBJECTDIR}/lcd_16seg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lcd_16seg.c  -o ${OBJECTDIR}/lcd_16seg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lcd_16seg.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lcd_7seg.o: lcd_7seg.c  .generated_files/2f626ed730bb18341ad4e8d264e899ee1846b546.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd_7seg.o.d 
	@${RM} ${OBJECTDIR}/lcd_7seg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lcd_7seg.c  -o ${OBJECTDIR}/lcd_7seg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lcd_7seg.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/adc.o: adc.c  .generated_files/7808af8ceade8758784c02d0e11c85b6f9d951c.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  adc.c  -o ${OBJECTDIR}/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/adc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/configuration_bits.o: configuration_bits.c  .generated_files/6ef2be40ef708618db8b4e76b5097a97ff7da95.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/configuration_bits.o.d 
	@${RM} ${OBJECTDIR}/configuration_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  configuration_bits.c  -o ${OBJECTDIR}/configuration_bits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/configuration_bits.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/interrupts.o: interrupts.c  .generated_files/9d835c3904c66d32d0e0531898ab733cdedbb3f1.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/interrupts.o.d 
	@${RM} ${OBJECTDIR}/interrupts.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  interrupts.c  -o ${OBJECTDIR}/interrupts.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/interrupts.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/615a76026ecde54bf36688af7577273f561cb78b.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/system.o: system.c  .generated_files/625f20854344700af0dceb6a6968191e98754540.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/traps.o: traps.c  .generated_files/f4eaec9b7ad57c5cca2ddb5fcaaf4a9939750647.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/traps.o.d 
	@${RM} ${OBJECTDIR}/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  traps.c  -o ${OBJECTDIR}/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/traps.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/user.o: user.c  .generated_files/792b994a2b413720e6bcfcee923aabc93d0ccedf.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/user.o.d 
	@${RM} ${OBJECTDIR}/user.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  user.c  -o ${OBJECTDIR}/user.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/user.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/LCD.o: LCD.c  .generated_files/fb5a9c8de5b99a97dd595c8bbec111d5fc77a8fd.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/LCD.o.d 
	@${RM} ${OBJECTDIR}/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  LCD.c  -o ${OBJECTDIR}/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/LCD.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lcd_16seg.o: lcd_16seg.c  .generated_files/d5a7833e954cc7584bf36ff52a88adb6ddc1060c.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd_16seg.o.d 
	@${RM} ${OBJECTDIR}/lcd_16seg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lcd_16seg.c  -o ${OBJECTDIR}/lcd_16seg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lcd_16seg.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lcd_7seg.o: lcd_7seg.c  .generated_files/df88ed9e862962aed1c1aa69e2ee8a8c33f68e3f.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd_7seg.o.d 
	@${RM} ${OBJECTDIR}/lcd_7seg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lcd_7seg.c  -o ${OBJECTDIR}/lcd_7seg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lcd_7seg.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/adc.o: adc.c  .generated_files/58ca39ced2ff6607e16793cf573f4154684c7575.flag .generated_files/6ecb315f6b8b95712225e5d40894ad71fb77f35.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  adc.c  -o ${OBJECTDIR}/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/adc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/pic24_blink_led.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/pic24_blink_led.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81B -mreserve=data@0x81C:0x81D -mreserve=data@0x81E:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x827 -mreserve=data@0x82A:0x84F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/pic24_blink_led.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/pic24_blink_led.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_XC16_24FJ512GU410=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/pic24_blink_led.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/XC16_24FJ512GU410
	${RM} -r dist/XC16_24FJ512GU410

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
