/***************************************************************************
 *   Copyright (C) 2011 by Anton V. Skorev                                 *
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

#include "projectproperties.h"

ProjectProperties::ProjectProperties(QObject *parent) :
    QObject(parent)
{
    m_angles = toponic::right_handed;
    m_axesXY = toponic::ne;
    m_description = "";
    m_sigmaApr = 10.0;
    m_confPr = 0.95;
    m_tolAbs = 1000;
    m_sigmaAct = toponic::aposteriori;
    m_updateConstrainedCoordinates = false;
}

void ProjectProperties::setAngles(const toponic::Angles newAngles)
{
    if (newAngles != m_angles)
    {
        m_angles = newAngles;
    }
}

void ProjectProperties::setAxesXY(const toponic::AxesXY newAxesXY)
{
    if (newAxesXY != m_axesXY)
    {
        m_axesXY = newAxesXY;
    }
}

void ProjectProperties::setDescription(const QString newDescription)
{
    if (newDescription != m_description)
    {
        m_description = newDescription;
    }
}

toponic::Angles ProjectProperties::angles() const
{
    return m_angles;
}

toponic::AxesXY ProjectProperties::axesXY() const
{
    return m_axesXY;
}

QString ProjectProperties::description() const
{
    return m_description;
}
