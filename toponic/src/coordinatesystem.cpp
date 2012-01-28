/***************************************************************************
 *   Copyright (C) 2012 by Anton V. Skorev                                 *
 *   anton-skorev@yandex.ru                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "coordinatesystem.h"
#include "ellipsoid.h"

CoordinateSystem::CoordinateSystem(QObject *parent) :
    QObject(parent) {
//    qDebug("CoordinateSystem::CoordinateSystem started");
    m_curEllipsoid = new Ellipsoid(this);
    m_curZoneType = toponic::deg6;
    m_changed = false;
//    qDebug("CoordinateSystem::CoordinateSystem finished");
}

CoordinateSystem::~CoordinateSystem() {
    delete m_curEllipsoid;
    m_curEllipsoid = 0;
}

void CoordinateSystem::setName(const QString value) {
    if (value != m_curName) {
        m_curName = value;
        m_changed = true;
        emit changed();
    }
}

void CoordinateSystem::setFalseNorthing(const float value) {
    if (value != m_curFalseNorthing) {
        m_curFalseNorthing = value;
        m_changed = true;
        emit changed();
    }
}

void CoordinateSystem::setFalseEasting(const float value) {
    if (value != m_curFalseEasting) {
        m_curFalseEasting = value;
        m_changed = true;
        emit changed();
    }
}

void CoordinateSystem::setScaleInCentralMeridian(const float value) {
    if (value != m_curScaleInCentralMeridian) {
        m_curScaleInCentralMeridian = value;
        m_changed = true;
        emit changed();
    }
}

void CoordinateSystem::setCentralMeridianLongitude(const float value) {
    if (value != m_curCentralMeridianLongitude) {
        m_curCentralMeridianLongitude = value;
        m_changed = true;
        emit changed();
    }
}

void CoordinateSystem::setEllipsoid(const Ellipsoid *value) {
    if (m_curEllipsoid->copyData(value)) {
        m_changed = true;
        emit changed();
    }
}

void CoordinateSystem::setZoneNumber(const int value) {
    if (value != m_curZoneNumber) {
        m_curZoneNumber = value;
        m_changed = true;
        emit changed();
    }
}

void CoordinateSystem::setZoneType(const toponic::ZoneType value) {
    if (value != m_curZoneType) {
        m_curZoneType = value;
        m_changed = true;
        emit changed();
    }
}

bool CoordinateSystem::copyData(const CoordinateSystem *sourceCS) {
    blockSignals(true);
    setName(sourceCS->name());
    setFalseNorthing(sourceCS->falseNorthing());
    setFalseEasting(sourceCS->falseEasting());
    setScaleInCentralMeridian(sourceCS->scaleInCentralMeridian());
    setCentralMeridianLongitude(sourceCS->centralMeridianLongitude());
    setEllipsoid(sourceCS->ellipsoid());
    setZoneNumber(sourceCS->zoneNumber());
    setZoneType(sourceCS->zoneType());
    blockSignals(false);
    if (m_changed) {
        emit changed();
        return true;
    } else return false;
}
