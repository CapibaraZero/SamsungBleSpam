/*
 * This file is part of the Capibara zero project(https://capibarazero.github.io/).
 * Copyright (c) 2023 Andrea Canale.
 * Copyright (c) 2023 Spooks4576
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SAMSUNGBLESPAM_H
#define SAMSUNGBLESPAM_H
#include <NimBLEDevice.h>

struct WatchModel
{
    uint8_t value;
    const char *name;
};

class SamsungBleSpam 
{
private:
    NimBLEAdvertisementData getOAdvertisementData();
    NimBLEServer *pServer;
    NimBLEAdvertising *pAdvertising;
    WatchModel *watch_models = new WatchModel[26] {
        {0x1A, "Fallback Watch"},
        {0x01, "White Watch4 Classic 44m"},
        {0x02, "Black Watch4 Classic 40m"},
        {0x03, "White Watch4 Classic 40m"},
        {0x04, "Black Watch4 44mm"},
        {0x05, "Silver Watch4 44mm"},
	{0x06, "Green Watch4 44mm"},
        {0x07, "Black Watch4 40mm"},
	{0x08, "White Watch4 40mm"},
        {0x09, "Gold Watch4 40mm"},
	{0x0A, "French Watch4"},
        {0x0B, "French Watch4 Classic"},
	{0x0C, "Fox Watch5 44mm"},
        {0x11, "Black Watch5 44mm"},
	{0x12, "Sapphire Watch5 44mm"},
        {0x13, "Purpleish Watch5 40mm"},
	{0x14, "Gold Watch5 40mm"},
	{0x15, "Black Watch5 Pro 45mm"},
        {0x16, "Gray Watch5 Pro 45mm"},
	{0x17, "White Watch5 44mm"},
        {0x18, "White & Black Watch5"},
	{0x1B, "Black Watch6 Pink 40mm"},
        {0x1C, "Gold Watch6 Gold 40mm"},
	{0x1D, "Silver Watch6 Cyan 44mm"},
        {0x1E, "Black Watch6 Classic 43m"},
	{0x20, "Green Watch6 Classic 43m"},
    };
public:
    SamsungBleSpam();
    ~SamsungBleSpam();
    void attack();
};
#endif
