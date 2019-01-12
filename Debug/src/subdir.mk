################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ActionSendXCMPMessageRequest.cpp \
../src/ActionSendXCMPMessageRequest_test.cpp \
../src/ActionZoneAndChannelChange.cpp \
../src/ActionZoneAndChannelChange_test.cpp \
../src/LoadCodePlug.cpp \
../src/LoadCodePlug_test.cpp \
../src/RAMBuffer.cpp \
../src/RAMBuffer_test.cpp \
../src/TestCase.cpp \
../src/TestCase_test.cpp \
../src/TestCreatorVistaAPX8000.cpp \
../src/TestCreatorVistaAPX8000_test.cpp \
../src/TestStrings.cpp \
../src/Vista\ XML\ Gen.cpp \
../src/XMLUtilities.cpp \
../src/XMLUtilities_test.cpp \
../src/iTestCreator.cpp \
../src/iTestDriver.cpp 

OBJS += \
./src/ActionSendXCMPMessageRequest.o \
./src/ActionSendXCMPMessageRequest_test.o \
./src/ActionZoneAndChannelChange.o \
./src/ActionZoneAndChannelChange_test.o \
./src/LoadCodePlug.o \
./src/LoadCodePlug_test.o \
./src/RAMBuffer.o \
./src/RAMBuffer_test.o \
./src/TestCase.o \
./src/TestCase_test.o \
./src/TestCreatorVistaAPX8000.o \
./src/TestCreatorVistaAPX8000_test.o \
./src/TestStrings.o \
./src/Vista\ XML\ Gen.o \
./src/XMLUtilities.o \
./src/XMLUtilities_test.o \
./src/iTestCreator.o \
./src/iTestDriver.o 

CPP_DEPS += \
./src/ActionSendXCMPMessageRequest.d \
./src/ActionSendXCMPMessageRequest_test.d \
./src/ActionZoneAndChannelChange.d \
./src/ActionZoneAndChannelChange_test.d \
./src/LoadCodePlug.d \
./src/LoadCodePlug_test.d \
./src/RAMBuffer.d \
./src/RAMBuffer_test.d \
./src/TestCase.d \
./src/TestCase_test.d \
./src/TestCreatorVistaAPX8000.d \
./src/TestCreatorVistaAPX8000_test.d \
./src/TestStrings.d \
./src/Vista\ XML\ Gen.d \
./src/XMLUtilities.d \
./src/XMLUtilities_test.d \
./src/iTestCreator.d \
./src/iTestDriver.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Vista\ XML\ Gen.o: ../src/Vista\ XML\ Gen.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Vista XML Gen.d" -MT"src/Vista\ XML\ Gen.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


