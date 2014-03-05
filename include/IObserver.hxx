/**
 * libcppattern - C++ Pattern library
 * Copyright (C) 2014  Andreas Speier
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */


#ifndef IOBSERVER_HPP_
#define IOBSERVER_HPP_

class IObserver {
    public:
        IObserver() {}
        virtual ~IObserver() {}

        virtual void Update() = 0;

};


#endif

