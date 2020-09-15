################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Vectors_intr.obj: ../Vectors_intr.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti_6/ccsv6/tools/compiler/c6000_7.4.12/bin/cl6x" -g --define="CHIP_6713" --include_path="C:/ti_6/ccsv6/tools/compiler/c6000_7.4.12/include" --include_path="C:/ti/ccsv5/tools/compiler/c6000/C6xCSL/include" --display_error_number --diag_warning=225 --mem_model:data=far --abi=coffabi --preproc_with_compile --preproc_dependency="Vectors_intr.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

c6713dskinit.obj: ../c6713dskinit.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti_6/ccsv6/tools/compiler/c6000_7.4.12/bin/cl6x" -g --define="CHIP_6713" --include_path="C:/ti_6/ccsv6/tools/compiler/c6000_7.4.12/include" --include_path="C:/ti/ccsv5/tools/compiler/c6000/C6xCSL/include" --display_error_number --diag_warning=225 --mem_model:data=far --abi=coffabi --preproc_with_compile --preproc_dependency="c6713dskinit.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

c6713dskinit.obj: ../c6713dskinit.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti_6/ccsv6/tools/compiler/c6000_7.4.12/bin/cl6x" -g --define="CHIP_6713" --include_path="C:/ti_6/ccsv6/tools/compiler/c6000_7.4.12/include" --include_path="C:/ti/ccsv5/tools/compiler/c6000/C6xCSL/include" --display_error_number --diag_warning=225 --mem_model:data=far --abi=coffabi --preproc_with_compile --preproc_dependency="c6713dskinit.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti_6/ccsv6/tools/compiler/c6000_7.4.12/bin/cl6x" -g --define="CHIP_6713" --include_path="C:/ti_6/ccsv6/tools/compiler/c6000_7.4.12/include" --include_path="C:/ti/ccsv5/tools/compiler/c6000/C6xCSL/include" --display_error_number --diag_warning=225 --mem_model:data=far --abi=coffabi --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


