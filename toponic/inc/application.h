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

#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QHash>

class MainWindow;
class CoordinateSystems;
class Ellipsoids;
class Project;

//! Класс приложения Toponic.
/*!
 * Свойства, которые связаны с объектом Application, отражают свойства основного окна приложения.
 * Приложение может иметь только один объект этого класса. Ссылку на этот объект можно получить
 * через статическую функцию класса Application::instance() или через глобальную переменную application.
 * Глобальная переменная объявлена в файле application.h
 *
 * @code static Application *application = Application::instance(); @endcode
 *
 * \nКласс Application предоставляет доступ к главному окну приложения через метод mainWindow(),
 * системам координат, используемым в приложении через метод coordinateSystems(),
 * набору эллипсоидов через метод ellipsoids() и активному проекту через метод activeProject().
 *
 * @ingroup toponic
 * @author Антон Скорев
 */
class Application : public QObject
{
    Q_OBJECT
    Q_PROPERTY (CoordinateSystems *coordinateSystems READ coordinateSystems)
public:
    //! Функция для доступа к объекту класса Application.
    /*!
     *  @retval *m_applicationInstance - cтатическая переменная класса Application.
     */
    static Application *instance();
    //! Функция настройки объекта класса Application.
    /*!
     * Функция вызывается в файле main.cpp сразу после инстанцирования объекта класса Application.
     * В ней создаются объекты-одиночки классов Ellipsoids, CoordinateSystems, Projects.
     */
    void setupApplication();
    //! Функция сохранения ссылки на главное окно приложения.
    void setMainWindow(MainWindow* mw);
    //! Функция доступа к объекту главного окна приложения.
    MainWindow *mainWindow() const;
    //! Функция доступа к хранилищу систем координат приложения.
    CoordinateSystems *coordinateSystems() const;
    //! Функция доступа к хранилищу эллипсоидов приложения.
    Ellipsoids* ellipsoids() const;
    //! Функция доступа к активному проекту.
    Project* activeProject() const;

signals:

private:
    //! Конструктор.
    Application();
    //! Деструктор.
    ~Application();
    //! Статический указатель на объект класса Application.
    static Application *m_applicationInstance;
    //! Флаг, сигнализирующий о необходимости запуска функции setupApplication().
    /*!
     * Функция setupApplication() должна запускается один раз. Для того, чтобы выяснить
     * неужен ли запуск функции, используется эта переменная.
     */
    static bool m_needSetup;
    //! Указатель на главное окно приложения.
    MainWindow *m_mainWindow;
    //! Указатель на хранилище систем координат приложения.
    CoordinateSystems *m_coordinateSystems;
    //! Указатель на хранилище эллипсоидов приложения.
    Ellipsoids *m_ellipsoids;
    //! Хранилище проектов, открытых в текущей сессии приложения.
    /*!
     *  Ключ - имя файла проекта. Если проект только создан и еще не сохранен на диск,
     *  то ключ будет иметь вид "newProject-n", где n - какой-то номер.
     */
    QHash <QString, Project *> *m_projects;
    //! Указатель на активный проект.
    Project *m_activeProject;
};

static Application* application = Application::instance();

#endif // APPLICATION_H
