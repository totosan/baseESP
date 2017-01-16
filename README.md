# Full integrated development part of conding, deploying and running code for ESP8266
This repository contains code for setting up a dev environment, that enables developer, to deploy and run code for Arduino-ESP8266 directly from VSCode.


## What you need
* First you need an **ESP8266** (7/12/2e,...) - best with dev-board.
  Setting up your computer for accessing the hardware under windows is pretty easy. Connect it with USB, if you have a Developer-Board. 
  Otherwise use a search-engine you prefer or have a look to this great ["Instructable-Page"](http://www.instructables.com/id/ESP8266-Wi-fi-module-explain-and-connection/?ALLSTEPS)
* **Git** - download [here](https://git-scm.com/downloads) (as well as [Git Credential Manager](https://java.visualstudio.com/Downloads/gitcredentialmanager/Index) for Linux or Mac OS)
* **VSCode** - you can install it from [here](https://code.visualstudio.com/) or clone it from [here](https://github.com/Microsoft/vscode.git).
* **Node.JS** - Download [here](https://nodejs.org/en/)
* **NPM** 


## How to setup
1. Clone this repository
1. **npm install**
1. **npm install -g gulp**
1. modify config.json and add the COM-port, where ESP8266 is connected to 
    1. open **config.json**
    1. open DeviceManager on Windows and have a look to the node *"Connections (COM & LPT)"*
    1. add the listed COM-port ID *(e.g. "COM3")* for your UART-Device as following `"device_port": "COM3"`
1. **gulp install-tools**
1. **gulp run** or with listener **gulp run --listen**

### Congratulations! You've completed.

## Important sites to read:
- [Release notes for Azure C SDK](https://github.com/Azure/azure-iot-sdks/releases)
- [Introduction to Azure IoT Device SDK for C](https://docs.microsoft.com/en-gb/azure/iot-hub/iot-hub-device-sdk-c-intro)