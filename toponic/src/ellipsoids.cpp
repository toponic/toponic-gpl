/***************************************************************************
 *   Copyright (C) 2010 by Anton V. Skorev                                 *
 *   askorev@gmail.com                                                     *
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


#include <QMapIterator>

#include "application.h"
#include "ellipsoids.h"
#include "initellipsoids.h"


Ellipsoids *Ellipsoids::m_ellipsoidsInstance = 0;

Ellipsoids* Ellipsoids::instance(Application *parent) {
    if  (m_ellipsoidsInstance == 0) {
        m_ellipsoidsInstance = new Ellipsoids(parent);
    }
    return m_ellipsoidsInstance;
}

Ellipsoids::Ellipsoids(Application *parent) : QObject(parent) {
    toponic::initEllipsoids(&m_id, &m_name);
}

Ellipsoids::~Ellipsoids() {

}

QString Ellipsoids::id(int index) {
    if (m_id.contains(index))
        return m_id.value(index);
    else
        return m_id.value(0);
}


QString Ellipsoids::name(int index) {
    if (m_name.contains(index))
        return m_name.value(index);
    else
        return m_name.value(index);
}


int Ellipsoids::index(QString id) {
    int result = 0;
    QMapIterator<int, QString> id_iter(m_id);
    while (id_iter.hasNext()) {
        id_iter.next();
        if (id_iter.value() == id)
            result = id_iter.key();
    }
    return result;
}


int Ellipsoids::count() {
    return m_id.count();
}

