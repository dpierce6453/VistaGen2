################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LoadCodePlug.cpp \
../src/LoadCodePlug_test.cpp \
../src/RAMBufferDriver.cpp \
../src/RAMBufferDriver_test.cpp \
../src/TestCreatorVistaAPX8000.cpp \
../src/TestCreatorVistaAPX8000_test.cpp \
../src/Vista\ XML\ Gen.cpp \
../src/iTestCreator.cpp \
../src/iTestDriver.cpp 

OBJS += \
./src/LoadCodePlug.o \
./src/LoadCodePlug_test.o \
./src/RAMBufferDriver.o \
./src/RAMBufferDriver_test.o \
./src/TestCreatorVistaAPX8000.o \
./src/TestCreatorVistaAPX8000_test.o \
./src/Vista\ XML\ Gen.o \
./src/iTestCreator.o \
./src/iTestDriver.o 

CPP_DEPS += \
./src/LoadCodePlug.d \
./src/LoadCodePlug_test.d \
./src/RAMBufferDriver.d \
./src/RAMBufferDriver_test.d \
./src/TestCreatorVistaAPX8000.d \
./src/TestCreatorVistaAPX8000_test.d \
./src/Vista\ XML\ Gen.d \
./src/iTestCreator.d \
./src/iTestDriver.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Vista\ XML\ Gen.o: ../src/Vista\ XML\ Gen.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Vista XML Gen.d" -MT"src/Vista\ XML\ Gen.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

