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


#ifndef ELLIPSOID_H_
#define ELLIPSOID_H_

#include <QObject>
#include <QMap>

class Ellipsoids;

//! Эллипсоид проекта.
/*!
 * Каждый проект обязан иметь эллипсоид. \n
 * Объект этого класса входит в объект класса ProjectProperties.
 *
 * @ingroup toponic
 * @author Антон Скорев
 */
class Ellipsoid : public QObject {
    Q_OBJECT
public:
    //! Конструктор.
    Ellipsoid (QObject *parent = 0);
    //! Деструктор.
    ~Ellipsoid();

    //! Назначение эллипоида по индексу.
    void setEllipsoid (Ellipsoids *e, int index);
    //! Назначение эллипсоида по идентификатору.
    void setEllipsoid (Ellipsoids *e, QString id);
    //! Получение индекса эллипсоида.
    int index() const;
    //! Получение идентификатора эллипсоида.
    QString id() const;
    //! Получение названия эллипсоида.
    QString name() const;

    //! Функция копирования данных.
    /*!
     * @param sourceEllipsoid - источник новых данных;
     * @retval - true если изменения внесены, в противном случае false.
     */
    bool copyData(const Ellipsoid *sourceEllipsoid);

private:
    //! Индекс эллипсоида.
    int m_index;
    //! Идентификатор эллипсоида.
    QString m_id;
    //! Название эллипсоида.
    QString m_name;
};

#endif /* ELLIPSOID_H_ */
