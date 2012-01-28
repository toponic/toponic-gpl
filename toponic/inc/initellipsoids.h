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


/***************************************************************************
 * Этот файл сформирован утилитой ellipsoids-xml. Исходные данные взяты    *
 * из фала ellipsoids.xml, входящего в состав роекта GNU GaMa              *
 * (http://www.gnu.org/software/gama/xml/ellipsoids.xml)                   *
 ***************************************************************************/

#ifndef INITELLIPSOIDS_H_
#define INITELLIPSOIDS_H_

#include <QtCore>

namespace toponic
{
    //! Функция инициализации хранилища эллипсоидов.
    /*!
    * Функция используется при создании объекта класса Ellipsoids для заполнения полей m_id и m_name.
    *
    * @arg @c id Идентификаторы эллипсоидов с соответствующими индексами.
    * @arg @c name Названия эллипсоидов с соответствующими индексами.
    *
    * @ingroup toponic
    * @author Антон Скорев
    *
    * @todo Надо подправить немного утилиту ellipsoids-xml на предмет соответсвия стилю отступов и удалить две точки с запятой в конце.
    */
    void initEllipsoids(QMap<int, QString> *id, QMap<int, QString> *name)
    {
        id->insert(0, "");
        id->insert(1, "airy");
        id->insert(2, "airy_mod");
        id->insert(3, "apl1965");
        id->insert(4, "andrae1876");
        id->insert(5, "australian");
        id->insert(6, "bessel");
        id->insert(7, "bessel_nam");
        id->insert(8, "clarke1858a");
        id->insert(9, "clarke1858b");
        id->insert(10, "clarke1866");
        id->insert(11, "clarke1880");
        id->insert(12, "clarke1880m");
        id->insert(13, "cpm1799");
        id->insert(14, "delambre");
        id->insert(15, "engelis");
        id->insert(16, "everest1830");
        id->insert(17, "everest1848");
        id->insert(18, "everest1856");
        id->insert(19, "everest1869");
        id->insert(20, "everest_ss");
        id->insert(21, "fisher1960");
        id->insert(22, "fisher1960m");
        id->insert(23, "fischer1968");
        id->insert(24, "grs67");
        id->insert(25, "grs80");
        id->insert(26, "hayford");
        id->insert(27, "helmert");
        id->insert(28, "hough");
        id->insert(29, "iau76");
        id->insert(30, "international");
        id->insert(31, "kaula");
        id->insert(32, "krassovski");
        id->insert(33, "lerch");
        id->insert(34, "mprts");
        id->insert(35, "mercury");
        id->insert(36, "merit");
        id->insert(37, "new_intl");
        id->insert(38, "nwl1965");
        id->insert(39, "plessis");
        id->insert(40, "se_asia");
        id->insert(41, "sgs85");
        id->insert(42, "schott");
        id->insert(43, "sa1969");
        id->insert(44, "walbeck");
        id->insert(45, "wgs60");
        id->insert(46, "wgs66");
        id->insert(47, "wgs72");
        id->insert(48, "wgs84");

        name->insert(0, QObject::tr("unknown ellipsoid"));
        name->insert(1, QObject::tr("Airy ellipsoid 1830"));
        name->insert(2, QObject::tr("Modified Airy"));
        name->insert(3, QObject::tr("Appl. Physics. 1965"));
        name->insert(4, QObject::tr("Andrae 1876 (Denmark, Iceland)"));
        name->insert(5, QObject::tr("Australian National 1965"));
        name->insert(6, QObject::tr("Bessel ellipsoid 1841"));
        name->insert(7, QObject::tr("Bessel 1841 (Namibia)"));
        name->insert(8, QObject::tr("Clarke ellipsoid 1858 1st"));
        name->insert(9, QObject::tr("Clarke ellipsoid 1858 2nd"));
        name->insert(10, QObject::tr("Clarke ellipsoid 1866"));
        name->insert(11, QObject::tr("Clarke ellipsoid 1880"));
        name->insert(12, QObject::tr("Clarke ellipsoid 1880 (modified)"));
        name->insert(13, QObject::tr("Comm. des Poids et Mesures 1799"));
        name->insert(14, QObject::tr("Delambre 1810 (Belgium)"));
        name->insert(15, QObject::tr("Engelis 1985"));
        name->insert(16, QObject::tr("Everest 1830"));
        name->insert(17, QObject::tr("Everest 1948"));
        name->insert(18, QObject::tr("Everest 1956"));
        name->insert(19, QObject::tr("Everest 1969"));
        name->insert(20, QObject::tr("Everest (Sabah and Sarawak)"));
        name->insert(21, QObject::tr("Fisher 1960 (Mercury Datum)"));
        name->insert(22, QObject::tr("Modified Fisher 1960"));
        name->insert(23, QObject::tr("Fischer 1968"));
        name->insert(24, QObject::tr("GRS 67 (IUGG 1967)"));
        name->insert(25, QObject::tr("Geodetic Reference System 1980"));
        name->insert(26, QObject::tr("Hayford 1909 (International)"));
        name->insert(27, QObject::tr("Helmert ellipsoid 1906"));
        name->insert(28, QObject::tr("Hough"));
        name->insert(29, QObject::tr("IAU 1976"));
        name->insert(30, QObject::tr("International 1924 (Hayford 1909)"));
        name->insert(31, QObject::tr("Kaula 1961"));
        name->insert(32, QObject::tr("Krassovski ellipsoid 1940"));
        name->insert(33, QObject::tr("Lerch 1979"));
        name->insert(34, QObject::tr("Maupertius 1738"));
        name->insert(35, QObject::tr("Mercury spheroid 1960"));
        name->insert(36, QObject::tr("MERIT 1983"));
        name->insert(37, QObject::tr("New International 1967"));
        name->insert(38, QObject::tr("Naval Weapons Lab., 1965"));
        name->insert(39, QObject::tr("Plessis 1817 (France)"));
        name->insert(40, QObject::tr("Southeast Asia"));
        name->insert(41, QObject::tr("Soviet Geodetic System 85"));
        name->insert(42, QObject::tr("Schott 1900 spheroid"));
        name->insert(43, QObject::tr("South American Spheroid 1969"));
        name->insert(44, QObject::tr("Walbeck"));
        name->insert(45, QObject::tr("WGS 60"));
        name->insert(46, QObject::tr("WGS 66"));
        name->insert(47, QObject::tr("WGS 72"));
        name->insert(48, QObject::tr("World Geodetic System 1984"));
    }
}

#endif /* INITELLIPSOIDS_H_ */

