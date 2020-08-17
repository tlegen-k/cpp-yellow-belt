################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../merge_sort_div3/merge_sort_div3.cpp 

OBJS += \
./merge_sort_div3/merge_sort_div3.o 

CPP_DEPS += \
./merge_sort_div3/merge_sort_div3.d 


# Each subdirectory must supply rules for building sources it contributes
merge_sort_div3/%.o: ../merge_sort_div3/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


