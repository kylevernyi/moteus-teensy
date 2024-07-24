# moteus library for Arduino #

## Summary ##

This is a C++ library that provides a convenient API for controlling and monitoring an mjbots moteus brushless servo controller.  It uses the ACAN4 library to perform CAN-FD communications, but could be easily modified to work with other libraries.

## Getting started ##

Note that this library can only communicate and operate a moteus controller which has already been calibrated.  Calibration currently can not be performed via an Arduino and requires `moteus_tool` executing on a desktop computer with some CAN-FD adapter.  See the moteus [getting started guide](https://github.com/mjbots/moteus/blob/main/docs/getting_started.md#calibration) for details.  The only controllers sold by mjbots.com which are pre-calibrated are those included in development kits.

### Hardware ###
For Teensy 4.x support, you will need a 3.3v compatible CAN transceiver such as the Adafruit TJA1051T/3. Only CAN3 (pins 30/31) support FD mode. Connected the CRX to RX and CTX to TX on the transceiver. From the transceiver to the Moteus CAN-H, CAN-L, and GND should be connected in standard way. The CAN-FD bus needs to be connected to moteus, typically this would be at least the CANL and CANH wires, and likely the ground as well.  For more than 2 or 3 controllers, separate 120 ohm termination resistors will be required on each end of the CAN bus.  Some Arduino CAN-FD shields, like the CANBed FD, have one termination resistor built in.


### Software ###

If you are using version 1.6.x or later of the Arduino software (IDE) you can use the Library Manager to install this library:

1. In the Arduino IDE, open the "Sketch" menu, select "Include Library", then "Manage Libraries...".
2. Search for "moteus"
3. Click the moteus entry in the list.
4. Click "Install".

If this does not work, you can manually install the library:

1. Download the [latest release archive from GitHub](https://github.com/kylevernyi/moteus-teensy) and decompress it
2. Rename the folder "moteus-arduino" to "moteus"
3. Drag the "moteus" folder into the "libraries" directory inside your Arduino sketchbook directory.  You can view your sketchbook location by opening the "File" menu and selecting "Preferences" in the Arduino IDE.  If there is not already a "libraries" folder in that location, you should make the folder yourself.
4. After installing the library, restart the Arduino IDE.

## Examples ##

Several examples are available.  You can access them from the Arduino IDE by opening the "File" menu, selecting "Examples", and then selecting "moteus".

## Documentation ##

For complete documentation, see [docs/reference.md](the reference documentation).
