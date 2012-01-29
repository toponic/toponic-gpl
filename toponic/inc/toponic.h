/***************************************************************************
 *   Copyright (C) 2009 by Anton V. Skorev                                 *
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


#ifndef TOPONIC_H_
#define TOPONIC_H_

#include <QString>

//! Пространство имен, содержащее различные структуры, перечисления и функции, используемые в приложении.
/*!
 *  @ingroup toponic
 *  @author Антон Скорев
 */
namespace toponic
{
    //! Направление измерения углов.
    enum Angles
    {
        right_handed, //!< измерение углов против часовой стрелки;
        left_handed  //!< измерение углов по часовой стрелки.
    };

    //! Ориентация осей X и Y.
    /*!
     *  Значение <I>ne</I> означает, что ось X ориентирована на север, а ось Y - на восток.
     *  Для систем координат с измерением углов по часовой стрелке применяются значения
     *  ориентации осей <I>ne, sw, es, wn</I>. Для систем координат с измерением углов
     *  против часовой стрелки применяются значения <I>en, nw, se, ws</I>.
     */
    enum AxesXY
    {
        ne, //!< направление осей: X на север,  Y на восток;
        sw, //!< направление осей: X на юг,     Y на запад;
        es, //!< направление осей: X на восток, Y на юг;
        wn, //!< направление осей: X на запад,  Y на запад;
        en, //!< направление осей: X на восток, Y на север;
        nw, //!< направление осей: X на север,  Y на запад;
        se, //!< направление осей: X на юг,     Y на восток;
        ws  //!< направление осей: X на запад,  Y на юг.
    };

    enum SigmaActual
    {
        aposteriori,
        apriori
    };

    //! Расширение файла для экспорта проекта.
    enum ExportExtention
    {
        MIF_MID,
        SHP,
        DXF,
        TOP_ABR,
        CDX
    };

    //! Расширение файла измерений, импортируемого в проект.
    enum ImportExtention
    {
        dat_R4,
        dat_R5,
        dat_M5,
        dat_Rec500,
        sdr,
        gre_Leica,
        rdf_Nicon,
        txt_2TA5,
        txt_3TA5,
        txt_4TA5,
        txt_Topcon_GTS6,
        txt_Topcon_GTS7,
        are_Geodimeter_points,
        job_Geodimeter_measurements,
        dc1_Pentax_points,
        dc1_Pentax_measurements
    };

    //! Масштаб съемки.
    /*!
     *  Значение масштаба съемки влияет на размер отображения условных знаков и
     *  текста в графическом окне проекта.
     */
    enum SurveyScale
    {
        s10, //!< 1: 10
        s20, //!< 1: 20
        s50, //!< 1: 50
        s100, //!< 1: 100
        s200, //!< 1: 200
        s500, //!< 1: 500
        s1k, //!< 1: 1 000
        s5k, //!< 1: 5 000
        s10k, //!< 1: 10 000
        s25k, //!< 1: 25 000
        s50k, //!< 1: 50 000
        s100k, //!< 1: 100 000
        s250k, //!< 1: 250 000
        s500k, //!< 1: 500 000
        s1m //!< 1: 1 000 000
    };

    //! Представление координаты <I>X</I> (Север).
    enum NPresentation
    {
        N, //!< Координата "Север" (N)
        N_No //!< Координата "Север" (N-N<SMALL>o</SMALL>), где N<SMALL>o</SMALL> - смещение на север.
    };

    //! Представление координаты <I>Y</I> (Восток).
    enum EPresentation
    {
        E, //!< Координата "Восток" (E)
        E_Eo, //!< Координата "Восток" (E+E<SMALL>o</SMALL>), где E<SMALL>o</SMALL> - смещение на восток
        zone_E_Eo //!< Координата "Восток" (&lt;номер зоны&gt;E+E<SMALL>o</SMALL>), где E<SMALL>o</SMALL> - смещение на восток
    };

    //! Тип роекции.
    /*!
     *  В данной версии представляется два типа проекции - локальная и картографическая проекция - Transverse Mercator (ТМ).
     *  Частным случаем этой проекции является проекция Гаусса-Крюгера (в СК-63, СК-95, СК-42 и аналогичных),
     *  в которой масштаб проекции по осевому меридиану равен 1.000.
     */
    enum ProjectionType
    {
        local, //!< Локальная картографическая проекция
        transverse_Merkator //!< Картографическая проекция - Transverse Mercator (ТМ).
    };

    //! Тип зоны.
    enum ZoneType
    {
        deg3, //!< Трехградусная
        deg6, //!< Шестиградусная
        nonstandard //!< Нестандартная.
    };

    //! Система высот.
    /*!
     *  @todo Не доделана структура, описывающая систему высот.
     */
    struct MSLSystem
    {
        QString name; //!< Название системы высот.
    };
}

#endif /* TOPONIC_H_ */
