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

#ifndef PROJECTPROPERTIES_H
#define PROJECTPROPERTIES_H

#include <QObject>

#include "toponic.h"
#include "ellipsoid.h"

//! Свойства проекта.
/*!
 * Объект этого класса содержится в каждом объекте сласса Project.
 * Для визуального контроля и изменения свойств текущего проекта служит
 * класс ProjectPropertiesDialog.
 *
 * \n Свойства ProjectProperties::axesXY, ProjectProperties::angles и
 * ProjectProperties::description - необходимы (хотя и не обязательны) для
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

    //! @deprecated Функция назначения направления измерения углов.
    /*! @param[in] newAngles Направление измерения углов в сети.
     *  @note Параметры, определяющие направление измерения углов и ориентацию осей
     *  координат в сети взаимозависимы (см. toponic::Angles). Может тогда не стоит
     *  задавать направление измерения углов, а сделать, чтобы поле
     *  ProjectProperties::m_angles устанавливалось в правильное значение в функции
     *  ProjectProperties::setAxesXY?
     *  @todo Смотри заметки по функции. */
    void setAngles(const toponic::Angles newAngles);

    //! Функция назначения ориентации осей X и Y по сторонам света.
    /*! @param[in] newAxesXY Ориентации осей X и Y по сторонам света. */
    void setAxesXY(const toponic::AxesXY newAxesXY);

    //! Функция назначения описания проекта.
    /*! Необязательное описание проекта (сети) в произвольной форме.
     *  @param[in] newDescription Описание проекта. */
    void setDescription(const QString newDescription);

    //! Функция получения установленного направления измерения углов.
    toponic::Angles angles() const;

    //! Функция получения установленной ориентации осей X и Y по сторонам света.
    toponic::AxesXY axesXY() const;

    //! Функция получения установленного описания проекта.
    QString description() const;
signals:

public slots:

private:
    //! Идентифицирует конфигурацию сети в базе данных.
    int m_confId;
    //! Идентификатор конфигурации сети.
    /*! Выдержка из документации GaMa:
     *  Field conf_name is used to identify configuration outside the database
     *  (e.g. parameter in command-line when reading data from database to gama-local).
     *  Не должно превышать 60 символов.
     *  @todo Перевести описание в документации. */
    QString m_confName;
    //! Значение априорного среднеквадратичного отклонения поправок.
    /*! @todo Убедиться в правильности перевода описания. */
    double m_sigmaApr;
    //! Доварительный интервал (confidence probability).
    double m_confPr;
    //! tolerance for identification of gross absolute terms in project equations (default value 1000 mm).
    /*! @todo Перевести описание в документации. */
    unsigned short m_tolAbs;
    //! actual type of reference standard deviation use in statistical tests.
    /*! @todo Перевести описание в документации. */
    toponic::SigmaActual m_sigmaAct;
    //! Определяет, будут ли предварительные координаты пунктов обновлены в итерационном уравнивании.
    bool m_updateConstrainedCoodrinates;
    //! Ориентация осей.
    toponic::AxesXY m_axesXY;
    //! Направление измерения углов.
    toponic::Angles m_angles;
    //! measurement epoch. It is floating point number (default value is 0.0).
    /*! @todo Перевести описание в документации.
     *  @todo Что это вообще означает? */
    double m_epoch;
    //! Алгоритм уравнивания сети.
    toponic::Algorithm m_algorithm;
    //! Единицы измерения углов (в XML файле результатов уравнивания).
    toponic::AngularUnits m_angUnits;
    //! Средняя широта района уравниваемой сети (в гонах).
    double m_latitude;
    //! Эллипсоид проекта.
    Ellipsoid *m_ellipsoid;
    //! Описание сети.
    QString m_description;
};

#endif // PROJECTPROPERTIES_H
