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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

//! Главное окно приложения.
/*!
 * Приложение может иметь только один объект этого класса.
 * \nГлавное окно содержит в себе документ, вид и элементы управления.
 * Закрытие главного окна означает завершение сеанса Toponic и влечет
 * за собой закрытие всех открытых документов.
 *
 * @ingroup gui
 * @author Антон Скорев
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0); //!< Конструктор.
    ~MainWindow(); //!< Деструктор.

public slots:
    // FILE slots
    void slotFileNew(); //!< Слот создания нового проекта.
    void slotFileOpen(); //!< Слот открытия файла проекта.
    void slotFileClose(); //!< Слот закрытия текущего пректа.
    void slotFileSave(); //!< Слот сохранения текущего проекта.
    void slotFileSaveAs(); //!< Слот сохранения текущего проекта под другим именем.
    void slotFileSaveAll(); //!< Слот сохранения всех открытых проектов.
    void slotImportFromFile(); //!< Слот импорта данных из файла измерений в активный проект.
    void slotImportTemplatePoints(); //!< Слот импорта данных из файла в активный проект (файл - шаблон точек).

protected:
    void changeEvent(QEvent *e); //!< Переопределение события изменения состояния главного окна.

private:
    Ui::MainWindow *ui;

    void notRelized(); //!< Заглушка для нереализованных функций.
};

#endif // MAINWINDOW_H
