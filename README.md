
# ctools_lab

This is the experimental [**CMSIS-Toolbox**](https://github.com/Open-CMSIS-Pack/devtools/tree/main/tools#cmsis-toolbox) Laboratory for
[**csolution - CMSIS Project Manager**](https://github.com/Open-CMSIS-Pack/devtools/tree/main/tools/projmgr).

It is possible to create Blinky and IoT (AWS MQTT Demo) examples for different boards using csolution and cproject YML files.

Available examples:
 - [Blinky project](README.md#blinky-project)
 - [AWS MQTT Demo](README.md#aws-mqtt-demo)


## Prerequisites

Tools:
 - [CMSIS-Toolbox 0.10.2](https://github.com/Open-CMSIS-Pack/devtools/releases/tag/tools%2Ftoolbox%2F0.10.2)
 - [Keil MDK 5.37](https://www.keil.com/download/product)
 - Arm Compiler 6.18 (part of MDK)

CMSIS packs: see examples for list of required packs


## Blinky project

Subdirectory: `example/Blinky`

Simple project blinking LEDs. See details in [README.md](example/Blinky/README.md).

Required CMSIS packs are listed in file [Blinky.csolution.yml](example/Blinky/Blinky.csolution.yml).

Project is available for for different build types and for different boards.
See table [Boards - Examples](README.md#boards-\--examples).

### Build and Run

1. start in folder `./example/Blinky/`

2. Use `csolution` to create `.cprj` project  
  ```
  csolution convert -s Blinky.csolution.yml -c Blinky.<build-type>+<target-type>
  
      <build-type>:  Debug | Release
      <target-type>: <board name>
  ```
  
  example: `csolution convert -s Blinky.csolution.yml -c Blinky.Debug+32L4R9IDISCOVERY`  

3. Use `cbuild` or MDK to build the created project

  - `cbuild`:
  ```
  cbuild Blinky.<build-type>+<target-type>.cprj  
  ```
  
  example: `cbuild Blinky.Debug+32L4R9IDISCOVERY.cprj`  

  - MDK:
    - import `*.cprj` and build  

4. Run the demo
  - power the board and establish debug connection  
  - program the image to the target  
  - run the program  


## AWS MQTT Demo

Subdirectory: `example/IoT/AWS_MQTT_MutualAuth_Demo`

Demo for connecting to AWS cloud. See details in [README.md](example/IoT/AWS_MQTT_MutualAuth_Demo/README.md).

Note: Make sure to update the credentials as described.

Required CMSIS packs are listed in file [IoT.csolution.yml](example/IoT/IoT.csolution.yml).

Project is available for different build types, for different boards, for different WiFi modules and Ethernet connection.
See table [Boards - Examples](README.md#boards-\--examples).

### Build and Run

1. start in folder `./example/IoT/`

2. Use `csolution` to create `.cprj` project  
  ```
  csolution convert -s IoT.csolution.yml -c AWS_MQTT_MutualAuth_Demo.<build-type>+<target-type>
  
      <build-type>:  Debug | Release
      <target-type>: <board-name>[+<module-name>]
      <module-name>: ESP8266 | ISM43362 | WizFi360
      
      Note: if optional <module-name> is not spezified then on-board WifI or on-board Ethernet is used. 
  ```
  
  example: `csolution convert -s IoT.csolution.yml -c AWS_MQTT_MutualAuth_Demo.Debug+32L4R9IDISCOVERY_ESP8266`  

3. Configure CMSIS-Driver  
  Note: due to current importer limitation it is necessary to manually configure the used CMSIS-Driver. 
  According table [Boards - Examples](README.md#boards-\--examples) choose the correct serial driver number for `Driver_USART` or `Driver_SPI`.  

4. Use `cbuild` or MDK to build the created project

  - `cbuild`:
  ```
  cbuild AWS_MQTT_MutualAuth_Demo/AWS_MQTT_MutualAuth_Demo.<build-type>+<target-type>.cprj  
  ```
  
  example: `cbuild AWS_MQTT_MutualAuth_Demo/AWS_MQTT_MutualAuth_Demo.Debug+32L4R9IDISCOVERY.cprj`  

  - MDK:
    - import `AWS_MQTT_MutualAuth_Demo/*.cprj` and build  
  Note: due to current importer limitation it is necessary to manually add the following preprocessor define 
  `MBEDTLS_CONFIG_FILE=\"aws_mbedtls_config.h\"`

5. Run the demo
  - power the board and establish debug connection  
  - open terminal and connect to board's serial port (Baud rate: 115200)
  - program the image to the target  
  - reset the target and observe messages in the terminal


## Boards - Examples

| Board Name           | Blinky | AWS MQTT Demo | ext. WiFi ESP8266 | ext. WiFi ISM43362 | ext. WiFi WizFi360 | on-board WiFi | on-board Ethernet |
|:--                   | :-:    | :-:           | :--               | :--                | :--                | :--           | :--               |
|32F746GDISCOVERY      | [x]    | [x]           | [x] UART\# 6      | [x] SPI\# 2        | [x] UART\# 6       | [ ]           | [x]               |
|32L4R9IDISCOVERY      | [x]    | [x]           | [x] UART\# 6      | [x] SPI\# 2        | [x] UART\# 6       | [ ]           | [ ]               |
|B-L475E-IOT01A        | [x]    | [ ]           | [ ]               | [ ]                | [ ]                | [x]           | [ ]               |
|FRDM-K32L3A6          | [x]    | [x]           | [x] UART\# 1      | [x] SPI\# 0        | [x] UART\# 1       | [ ]           | [ ]               |
|IMXRT1050-EVKB        | [x]    | [x]           | [x] UART\# 3      | [ ]                | [x] UART\# 3       | [ ]           | [x]               |
|LPC54018-IoT-Module   | [x]    | [x]           | [ ]               | [ ]                | [ ]                | [x]           | [ ]               |
|LPCXpresso55S69       | [x]    | [x]           | [x] UART\# 2      | [x] SPI\# 8        | [x] UART\# 2       | [ ]           | [ ]               |
|MCB4300               | [x]    | [x]           | [ ]               | [ ]                | [ ]                | [ ]           | [x]               |
|MIMXRT1064-EVK        | [x]    | [x]           | [x] UART\# 3      | [ ]                | [x] UART\# 3       | [ ]           | [x]               |
|Musca-S1              | [x]    | [x]           | [x] UART\# 0      | [ ]                | [x] UART\# 0       | [ ]           | [ ]               |
|NUCLEO-G474RE         | [x]    | [ ]           | [ ]               | [ ]                | [ ]                | [ ]           | [ ]               |
|NUCLEO-L552ZE-Q       | [x]    | [x]           | [x] UART\# 3      | [x] SPI\# 1        | [x] UART\# 3       | [ ]           | [ ]               |
|STM32G071B-DISCO      | [x]    | [ ]           | [ ]               | [ ]                | [ ]                | [ ]           | [ ]               |
|STM32H745I-DISCO      | [x]    | [ ]           | [ ]               | [ ]                | [ ]                | [ ]           | [ ]               |
|STM32L562E-DK         | [x]    | [x]           | [x] UART\# 6      | [x] SPI\# 3        | [x] UART\# 6       | [ ]           | [ ]               |
|AVH_MPS3_Corstone-300 | [x]    | [x]           | [ ]               | [ ]                | [ ]                | [ ]           | [x]               |
