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


#ifndef ELLIPSOIDS_H_
#define ELLIPSOIDS_H_

#include <QObject>
#include <QMap>

class Application;

//! Хранилище эллипсоидов.
/*!
 * Приложение может иметь только один объект этого класса.
 * \nВсе эллипсоиды, которые могут быть использованы в приложении, хранятся в этом классе.
 * На самом деле хранятся только имена эллипсодов (полные и сокращенные) и их идентификаторы.
 * Имена эллипсоидов идентичны именам, применяемым в GNU GaMa. Ни какие параметры эллипсоидов не задаются.
 * Заполнение хранилища эллипсоидами производится во время создания экземпляра класса.
 * Количество, идентификаторы и названия эллипсоидов, хранящихся в классе, постоянно для каждой
 * конкретной версии файла ellipsoids.xml, который является частью проекта GNU GaMa.
 *
 * В программе gama-local используются идентификаторы (id) эллипсоидов в качестве аргумента
 * для запуска программы. Например строка
 * \n<I>\>\>gama-local.exe input.xml [options] -ellipsoid krassovski</I>
 * \nзапустит программу для расчета файла входных данных input.xml, при этом вертикальные и(или) зенитные
 * углы будут приведены к плоскости.
 *
 * @ingroup toponic
 * @author Антон Скорев
 */
class Ellipsoids: public QObject {
    Q_OBJECT

public:
    friend class Application;

protected:
    //! Функция для доступа к хранилищу эллипсоидов.
    /*!
     *  @retval *m_ellipsoidsInstance - cтатическая переменная класса Ellipsoids.
     */
    static Ellipsoids *instance(Application *parent);

public:
    //! Функция чтения идентификатора эллипсоида.
    /*!
     * @arg @c index индекс эллипсоида.
     */
    QString id(int index);
    //! Функция чтения названия эллипсоида.
    /*!
     * @arg @c index индекс эллипсоида.
     */
    QString name(int index);
    //! Функция чтения индекса эллипсоида.
    /*!
     * @arg @c id идентификатор эллипсоида.
     */
    int index(QString id);
    //! Функция пвозвращает количество эллипсоидов, зарегистрированных в классе.
    int count();

private:
    //! Конструктор.
    Ellipsoids (Application *parent = 0);
    //! Деструктор.
    ~Ellipsoids();
    //! Статический указатель на хранилище эллипсоидов.
    static Ellipsoids *m_ellipsoidsInstance;
    //! Идентификаторы эллипсоидов с соответствующими индексами.
    QMap<int, QString> m_id;
    //! Названия эллипсоидов с соответствующими индексами.
    QMap<int, QString> m_name;
};

#endif /* ELLIPSOIDS_H_ */
