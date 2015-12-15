/*******************************************************************************
* Copyright (C) 2015, Jean-Yves VET, contact [at] jean-yves [dot] vet          *
*                                                                              *
* This software is licensed as described in the file LICENCE, which you should *
* have received as part of this distribution. You may opt to use, copy,        *
* modify, merge, publish, distribute and/or sell copies of the Software, and   *
* permit persons to whom the Software is furnished to do so, under the terms   *
* of the LICENCE file.                                                         *
*                                                                              *
* This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY    *
* KIND, either express or implied.                                             *
*******************************************************************************/

/**
 * @file EEPROM24xx.h
 * @brief Driver library for 24xx external (I2C) EEPROMs.
 * @author Jean-Yves VET
 */

#include <Wire.h>
#include "EEPROM24xx.h"

/* ============================== Constructor =============================== */

/**
 * Create an EEPROM24xx object.
 *
 * @param   address[in]    I2C address of the device.
 */
EEPROM24xx::EEPROM24xx(byte address) {
    setAddress(address);
}


/* =========================== Private Functions ============================ */

/**
 * Start transmission and set initial address.
 *
 * @param   startAddress[in]   Initial address.
 */
void EEPROM24xx::_setStartAddress(int startAddress) {
    Wire.beginTransmission(_address);
    Wire.write((int)(startAddress >> 8));
    Wire.write((int)(startAddress & 0xFF));
}


/* =========================== Public Functions ============================= */

/**
 * Get the address of the device.
 *
 * @return   I2C address of the device.
 */
byte EEPROM24xx::getDeviceAddress() {
    return _address;
}


/**
 * Set the address of the device.
 *
 * @param   address[in]    I2C address of the device.
 */
void EEPROM24xx::setDeviceAddress(byte address) {
    _address = address;
}


/**
 * Store one byte at the provided address.
 *
 * @param   startAddress[in]     Address where to store the byte.
 * @param   byte[in]             Byte to store.
 */
void EEPROM24xx::storeByte(int startAddress, byte b) {
    _setStartAddress(startAddress);
    Wire.write(b);
    Wire.endTransmission();

    delay(10);
}


/**
 * Read one byte at the provided address.
 *
 * @param   startAddress[in]     Address where to read the byte.
 * @return  One byte.
 */
byte EEPROM24xx::readByte(int startAddress) {
    _setStartAddress(startAddress);
    Wire.endTransmission();

    // Request byte content
    Wire.requestFrom(_address, (uint8_t)1);

    if (Wire.available()) {
        return Wire.read();
    } else {
        return EEPROM_ERRORBYTE;
    }
}


EEPROM24xx E24xx;
