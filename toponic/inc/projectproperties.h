/***************************************************************************
 *   Copyright (C) 2011 by Anton V. Skorev                                 *
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

#ifndef PROJECTPROPERTIES_H
#define PROJECTPROPERTIES_H

#include <QObject>

//! Свойства проекта.
/*!
 * Объект этого класса содержится в каждом объекте сласса Project.
 * Для визуального контроля и изменения свойств текущего проекта служит
 * класс ProjectPropertiesDialog.
 *
 * \n Свойства ProjectProperties::axesXY, ProjectProperties::angles и
 * ProjectProperties::description - необходимы (сотя и не обязательны) для
 * создания входного файла GNU GaMa.
 *
 * @ingroup toponic
 * @author Антон Скорев
 */
class ProjectProperties : public QObject
{
    Q_OBJECT
public:
    explicit ProjectProperties(QObject *parent = 0);

signals:

public slots:

private:
    toponic::Angles m_angles; //!< Направление измерения углов.
    toponic::AxesXY m_axesXY; //!< Ориентация осей.
    QString m_description; //!< Описание
};

#endif // PROJECTPROPERTIES_H
