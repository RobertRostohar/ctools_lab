Board: ARM AVH_MPS2_Cortex-M7
----------------------------------------------

MPS2 platform for Cortex-M7 simulated by Arm Virtual Hardware Targets (VHT).

Running the VHT in uVision requires the following settings:
 - open "Options for Target"
 - select "Debug" tab
 - under "Use" select "Models Cortex-M Debugger" and click "Settings" end enter the following:
   - Command: $KARM\VHT\VHT_MPS2_Cortex-M7.exe
   - Target: armcortexm7ct
   - Configuration File: fvp_config.txt

Running the VHT via command line (from project root directory and VHT executable in path):
`VHT_MPS2_Cortex-M7 -f Board/AVH_MPS2_Cortex-M7/fvp_config.txt -C fvp_mps2.mps2_visualisation.disable-visualisation=1 -C fvp_mps2.telnetterminal0.start_telnet=0 -C fvp_mps2.UART0.out_file=- -a <image>`

> Note: running on fast computers can lead to simulation running too quickly resulting in dropping incoming data packets from the network. 
  This will be seen as error messages in the terminal window.  
  Reduce the number of ticks to simulate for each quantum by specifying the following command line option `-Q <n>`, 
  where `<n>` is the number of ticks (default value = 10000).  
  Example: `-Q 10`

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | CMSDK_CM7_DP_VHT
| Clock                   | 25 MHz
| Heap                    | 64 kB (configured in linker scatter file)
| Stack (MSP)             | 1 kB  (configured in linker scatter file)

**STDIO** is routed to USART0

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| ETH_MAC0     | Ethernet LAN91C111
| ETH_PHY0     | Ethernet LAN91C111
| USART0       | USART0
| VIO          | VHT VIO
