/***************************************************************************
 *   Copyright (C) 2010 by Anton V. Skorev                                 *
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


#include "application.h"
#include "ellipsoids.h"
#include "ellipsoid.h"


Ellipsoid::Ellipsoid(QObject *parent) : QObject(parent) {
    Ellipsoids *e;
    e = application->ellipsoids();
    setEllipsoid (e, 0);
}


Ellipsoid::~Ellipsoid() {

}

void Ellipsoid::setEllipsoid (Ellipsoids *e, int index) {
    m_index = index;
    m_id = e->id(index);
    m_name = e->name(index);
}

void Ellipsoid::setEllipsoid(Ellipsoids *e, QString id) {
    m_index = e->index(id);
    if (m_index) {
        m_id = id;
        m_name = e->name(m_index);
    } else {
        m_id = "";
        m_name = e->name(0);
    }
}

int Ellipsoid::index() const {
    return m_index;
}


QString Ellipsoid::id() const {
    return m_id;
}


QString Ellipsoid::name() const {
    return m_name;
}

//Т. к. каждому эллипсоиду соответствует уникальный набор из m_index, m_id и m_name,
//то можно проверить лишь одно из значений этих полей на совпадение с источником,
//чтобы убедиться, что все данные источника отличаются от соответствующих данных
//принимающего эллипсоида.
bool Ellipsoid::copyData(const Ellipsoid *sourceEllipsoid) {
    if (m_index != sourceEllipsoid->index()) {
        m_index = sourceEllipsoid->index();
        m_id = sourceEllipsoid->id();
        m_name = sourceEllipsoid->name();
        return true;
    }
    return false;
}
