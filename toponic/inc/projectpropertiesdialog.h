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

#ifndef PROJECTPROPERTIESDIALOG_H
#define PROJECTPROPERTIESDIALOG_H

#include <QDialog>

namespace Ui {
    class ProjectPropertiesDialog;
}

//! Диалог свойств проекта.
/*!
 * Объект этого класса создается динамически. После завершения работы с окном
 * объект разрушается. При следующем вызове окна пользователем объект создается
 * вновь. При создании объекта окна, его содержимое заполняется данными из объекта
 * класса ProjectProperties, относящегося к текущему проекту.
 *
 * @ingroup gui
 * @author Антон Скорев
 */
class ProjectPropertiesDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ProjectPropertiesDialog(QWidget *parent = 0); //!< Конструктор.
    ~ProjectPropertiesDialog(); //!< Деструктор.
signals:

public slots:

private:
    Ui::ProjectPropertiesDialog *ui;

};

#endif // PROJECTPROPERTIESDIALOG_H
