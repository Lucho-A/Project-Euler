################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/Modules/arithmeticOperations.c \
../Source/Modules/combinatoric.c \
../Source/Modules/commonFunctions.c \
../Source/Modules/factorization.c \
../Source/Modules/numberConversion.c \
../Source/Modules/palindrome.c \
../Source/Modules/pause.c \
../Source/Modules/prime.c \
../Source/Modules/vector.c 

OBJS += \
./Source/Modules/arithmeticOperations.o \
./Source/Modules/combinatoric.o \
./Source/Modules/commonFunctions.o \
./Source/Modules/factorization.o \
./Source/Modules/numberConversion.o \
./Source/Modules/palindrome.o \
./Source/Modules/pause.o \
./Source/Modules/prime.o \
./Source/Modules/vector.o 

C_DEPS += \
./Source/Modules/arithmeticOperations.d \
./Source/Modules/combinatoric.d \
./Source/Modules/commonFunctions.d \
./Source/Modules/factorization.d \
./Source/Modules/numberConversion.d \
./Source/Modules/palindrome.d \
./Source/Modules/pause.d \
./Source/Modules/prime.d \
./Source/Modules/vector.d 


# Each subdirectory must supply rules for building sources it contributes
Source/Modules/%.o: ../Source/Modules/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/lucho/git/Project-Euler/Project Euler/Headers" -O0 -g3 -Wall -fPIC -c -fmessage-length=0 -lm -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


