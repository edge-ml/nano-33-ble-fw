# nano-33-ble-fw

Firmware to use with the Arduino Nano 33 BLE to record sensor data with edge-ml over Web Bluetooth.

## Before you start
1. Download the the Arduino IDE for your PC [here](https://www.arduino.cc/en/software)
2. Install the Arduino IDE on your PC
3. Open the Arduino IDE

**⚠️ IMPORTANT: YOUR ARDUINO IDE HAS TO BE AT LEAST AT VERSION 1.8.13 !**

## Installe Firmware on Nicla Sense ME
1. Add the board-specific support files of the Arduino Nano 33 BLE by going to `Tools => Board: ... => Board Manager`. 
2. In the dialog, seach for "BLE Nano 33" and install `Arduino Mbed OS Nano Boards by Arduino` (this may take a while). 
Note: on Windows, make sure to confirm the dialog that requests to do changes on your PC that pops up during installation (otherwise drivers can not be installed successfully).
3. Configure your Arduino IDE to compile for the Nicla Sense ME by selecting ``Tools => Board => Arduino Nano 33 BLE``
4. Select the port by clicking `Tools => Port => THE PORT YOUR NANO 33 BLE IS CONNECTED TO` (Hint: if the name of the Nano 33 BLE is not showing in the list of ports, you can identify the correct port by plugging the Nano in and out and re-opening the menu which will either show or hide the Port)
5. Download the source code of the latest firmware (Latest, not Draft) version as .zip form the [release page](https://github.com/edge-ml/nano-33-ble-fw/releases).
6. Add the downloaded .zip file as a library to the Arduino IDE: `Sketch => Include Library => Add .ZIP library`.
7. Open the edge-ml firmware by clicking: `Files => Examples => Edge_ML => App`.
9. Upload the firmware to your Nano 33 BLE by clicking the right facing arrow in the top menu bar. This will compile the firmware and upload to your Nano. 
10. **Compilation may take a while. Don't worry, this is expected as long as it does not fail.**
11. You are now ready to connect to your BLE Nano 33 from the edge-ml website
