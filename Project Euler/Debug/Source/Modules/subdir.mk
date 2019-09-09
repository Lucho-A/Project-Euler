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
<<<<<<< HEAD
../Source/Modules/strings.c \
../Source/Modules/vector.c 

=======
../Source/Modules/vector.c 

>>>>>>> branch 'master' of https://github.com/Lucho-A/Project-Euler
OBJS += \
./Source/Modules/arithmeticOperations.o \
./Source/Modules/combinatoric.o \
./Source/Modules/commonFunctions.o \
./Source/Modules/factorization.o \
./Source/Modules/numberConversion.o \
./Source/Modules/palindrome.o \
./Source/Modules/pause.o \
./Source/Modules/prime.o \
<<<<<<< HEAD
./Source/Modules/strings.o \
./Source/Modules/vector.o 

=======
./Source/Modules/vector.o 

>>>>>>> branch 'master' of https://github.com/Lucho-A/Project-Euler
C_DEPS += \
./Source/Modules/arithmeticOperations.d \
./Source/Modules/combinatoric.d \
./Source/Modules/commonFunctions.d \
./Source/Modules/factorization.d \
./Source/Modules/numberConversion.d \
./Source/Modules/palindrome.d \
./Source/Modules/pause.d \
./Source/Modules/prime.d \
<<<<<<< HEAD
./Source/Modules/strings.d \
./Source/Modules/vector.d 


# Each subdirectory must supply rules for building sources it contributes
Source/Modules/%.o: ../Source/Modules/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"C:\Users\L\git\Project-Euler\Project Euler\Headers" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


=======
./Source/Modules/vector.d 


# Each subdirectory must supply rules for building sources it contributes
Source/Modules/%.o: ../Source/Modules/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/lucho/git/Project-Euler/Project Euler/Headers" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


>>>>>>> branch 'master' of https://github.com/Lucho-A/Project-Euler
