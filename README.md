# Soldering-tester
Arduino code for testing of soldering. It was used Nucleo64 STM32L152, but can be used different kind of board.

The principle of the soldering test is the measuring of structural diodes inside the IC. If you measure the diode, probably it is soldered well. 

Description:

Wire the GND of Nucleo64 board to Vcc of tested board.

Enable or connect pull-up resistor for each analog input (3k3 - 10k).

Wire the A0, A1,... pin of Nucleo64 to PIN (GPIO etc.) of tested board.

The structural diode is not included in VCC or GND of tested board.
