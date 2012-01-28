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

#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include <QObject>
#include "toponic.h"

class Ellipsoid;

//! Система плановых координат проекта.
/*!
 * Каждый проект обязан иметь систему плановых координат. \n
 * Объект этого класса входит в объект класса ProjectProperties.
 *
 * @ingroup toponic
 * @author Антон Скорев
 */
class CoordinateSystem: public QObject
{
    Q_OBJECT

public:
    //! Конструктор.
    CoordinateSystem(QObject *parent = 0);
    //! Деструктор.
    ~CoordinateSystem();

public:
    //! Функция получения названия системы координат.
    /*!
     * @retval QString - Ткущее название системы координат.
     */
    QString name() const {
        return m_curName;
    }
    //! Функция получения значения смещения на север.
    /*!
     * @retval float - Текущее значение смещения на север.
     */
    float falseNorthing() const {
        return m_curFalseNorthing;
    }
    //! Функция получения значения смещения на восток.
    /*!
     * @retval float - Текущее значение смещения на восток.
     */
    float falseEasting() const {
        return m_curFalseEasting;
    }
    //! Функция получения значения масштаба по осевому меридиану.
    /*!
     * @retval float - Текущее значение масштаба по осевому меридиану.
     */
    float scaleInCentralMeridian() const {
        return m_curScaleInCentralMeridian;
    }
    //! Функция получения значения долготы осевого меридиана.
    /*!
     * @retval float - Текущее значение долготы осевого меридиана.
     */
    float centralMeridianLongitude() const {
        return m_curCentralMeridianLongitude;
    }
    //! Функция получения эллипсоида.
    /*!
     * @retval Ellipsoid - Текущий эллипсоид.
     */
    Ellipsoid* ellipsoid() const {
        return m_curEllipsoid;
    }
    //! Функция получения номера зоны.
    /*!
     * @retval int - Текущий номер зоны.
     */
    int zoneNumber() const {
        return m_curZoneNumber;
    }
    //! Функция получения типа зоны.
    /*!
     * @retval toponic::ZoneType - Текущий тип зоны.
     */
    toponic::ZoneType zoneType() const {
        return m_curZoneType;
    }

    //! Функция назначения нового названия системы координат.
    /*!
     * @param value - Новое имя проекта.
     */
    void setName(const QString value);
    //! Функция назначения нового смещения на север.
    /*!
     * @param value - Новое смещение на север.
     */
    void setFalseNorthing(const float value);
    //! Функция назначения нового смещения на восток.
    /*!
     * @param value - Новое смещение на восток.
     */
    void setFalseEasting(const float value);
    //! Функция назначения нового значения масштаба по осевому меридиану.
    /*!
     * @param value - Новое значение масштаба по осевому меридиану.
     */
    void setScaleInCentralMeridian(const float value);
    //! Функцияя назначения нового значения долготы осевого меридиана.
    /*!
     * @param value - Новое значение долготы осевого меридиана.
     */
    void setCentralMeridianLongitude(const float value);
    //! Функция назначения нового эллипсоида.
    /*!
     * @param value - Новый эллипсоид.
     */
    void setEllipsoid(const Ellipsoid *value);
    //! Функция назначения нового номера зоны.
    /*!
     * @param value - Новый номер зоны.
     */
    void setZoneNumber(const int value);
    //! Функция назначения нового типа зоны.
    /*!
     * @param value - Новый типа зоны.
     */
    void setZoneType(const toponic::ZoneType value);

    //! Функция копирования данных.
    /*!
     * @param sourceCS - источник новых данных;
     * @retval - true если изменения внесены, в противном случае false.
     */
    bool copyData(const CoordinateSystem *sourceCS);

signals:
    //! Сигнал испускается при изменении любого из полей объекта.
    void changed();

private:
    QString m_curName; //!< Текщее название системы координат.
    float m_curFalseNorthing; //!< Текущее смещение на север.
    float m_curFalseEasting; //!< Текущее смещение на восток.
    float m_curScaleInCentralMeridian; //!< Текущий масштаб по осевому мередиану.
    float m_curCentralMeridianLongitude; //!< Текущая долгота осевого меридиана.
    Ellipsoid *m_curEllipsoid; //!< Текущий эллипсоид.
    int m_curZoneNumber; //!< Текущий номер зоны.
    toponic::ZoneType m_curZoneType; //!< Текущий тип зоны.
    bool m_changed; //!< Флаг, сигнализирующий, что объект был изменен.
};

#endif // COORDINATESYSTEM_H
