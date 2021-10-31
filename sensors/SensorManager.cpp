//
// Created by Dylan Ray Roodt on 31.10.2021.
//

#include "SensorManager.h"

SensorManager::SensorManager() {

}

void SensorManager::debug(Stream &stream)
{
    _debug = &stream;
}