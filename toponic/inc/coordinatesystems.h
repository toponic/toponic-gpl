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

#ifndef COORDINATESYSTEMS_H
#define COORDINATESYSTEMS_H

#include <QObject>

class Application;

//! Хранилище систем плановых координат.
/*!
 * Приложение может иметь только один объект этого класса.
 * \nВсе системы плановых координат, которые могут быть использованы в приложении,
 * хранятся в этом классе. Доступ к объекту этого класса осуществляется через
 * глобальную переменную application.
 * @code CoordinateSystems *cs = application->coordinateSystems(); @endcode
 * или через статический метод класса Application
 * @code CoordinateSystems *cs = Application::instance()->coordinateSystems(); @endcode
 *
 * @ingroup toponic
 * @author Антон Скорев
 */
class CoordinateSystems : public QObject
{
    Q_OBJECT
public:
    friend class Application;
    
signals:
    
public slots:

protected:
    //! Функция для доступа к объекту хранилища систем координат.
    static CoordinateSystems *instance(Application *parent);

private:
    //! Конструктор.
    explicit CoordinateSystems(Application *parent = 0);
    //! Деструктор.
    ~CoordinateSystems();
    //! Статический указатель на объект хранилища систем координат.
    static CoordinateSystems *m_coordinateSystemsInstance;
};

#endif // COORDINATESYSTEMS_H
