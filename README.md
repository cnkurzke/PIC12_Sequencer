# PIC12_Sequencer
Blinken Lights


## What does this do?

This is a very simple "Hello World" for the PIC12F1572 Microcontroller.
The purpose is to verify we have the toolchain, IDE, Programmer etc. all set up and ready to go to explore the wonderful world of microchips.

## Basic Software Setup

I assume you have the Development environmnet downloaded and working.
For the latest version see: https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide#downloads

This is a Netbeans based install, and ... at least on the Linux Version needs to be installed with root permissions.
For that reason, I opted to run the entire IDE inside a Virtual Machine. I don't like complex 3rd party apps messing with my system.

## Hardware Setup

This is the minimum configuration for a flashy demo

        
                        +---\/---+
      5V --+------ VDD  |1*     8|  VSS ------- Ground
           \-LED-- RA5  |2      7|  Data --- (Programmer)
                   RA4  |3      6|  Clock -- (Programmer)
  (Programmer) -- MCLR  |4      5|  RA2
                        +--------+
