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

#ifndef __EEPROM24xx_H__
#define __EEPROM24xx_H__

#include <Arduino.h>
#include <functional>

/* ============================== Register names ============================ */

#define EEPROM_ADDRESS               0x50
#define EEPROM_ERRORBYTE             0xFA


class EEPROM24xx
{
    public:
                 EEPROM24xx(const byte address = EEPROM_ADDRESS);
        void     setDeviceAddress(byte address);
        byte     getDeviceAddress();
        void     storeByte(int startAddress, byte b);
        byte     readByte(int startAddress);

    private:
        byte      _address;
        void      _setStartAddress(int startAddress);
};

extern EEPROM24xx E24xx;
#endif
