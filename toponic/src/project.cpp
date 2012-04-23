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

#include <QtDebug>

#include <QDomDocument>
#include <QStandardItemModel>
#include <QFile>

#include "project.h"

Project::Project(QObject *parent) :
    QObject(parent)
{
    m_projectDOM = new QDomDocument();
}

Project::~Project()
{
    delete m_projectDOM;
}

bool Project::readFromFile(const QString fileName)
{
    qDebug("Project::readFromFile(const QString fileName) called.");

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
        return false;
    if (!m_projectDOM->setContent(&file)) {
        file.close();
        return false;
    }
    file.close();

    qDebug() << m_projectDOM->doctype().name();
    return true;
}
