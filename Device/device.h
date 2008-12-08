/*
 * PacMan - Packet Manipulation Library 
 * Copyright © 2008  Jeff Scaparra, Gaurav Yadav, Andrie Tanusetiawan
 *
 * This file is a part of PacMan.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/** \file device.h
 * This is the declaration for the class Device
 */

/** \class Device 
 * This class is the main interface for the Device library
 */

#ifndef DEVICE_H
#define DEVICE_H

#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <pcap.h>
#include "devicesLookup.h"


class Device
{
	public:
                //!Default constructor
		Device();
                //!Constructor
		Device(std::string dev, int isDev);
                //!Set device name and whether it is a device (isDev = 1) or it is a Pcap file (isDev = 0)
		void setDevice(std::string dev, int isDev);
                //!Get device name
		std::string getDevice();
                //!Returns 1 if it is a device, 0 if it is a pcap file
		int isDevice();
                //!Returns 1 if device exists, 0 otherwise
		int isValid();
                //!Destructor
		~Device();

	private:
                //!Device name
		std::string dev;
                //!Indicates 1 if it is a device, 0 if it is a pcap file
		int isDev;
};

#endif
