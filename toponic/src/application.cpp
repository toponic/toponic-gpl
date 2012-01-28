/***************************************************************************
 *   Copyright (C) 2011 by Anton V. Skorev                                 *
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

#include "application.h"
#include "mainwindow.h"
#include "coordinatesystems.h"
#include "ellipsoids.h"


Application* Application::m_applicationInstance = 0;
bool Application::m_needSetup = true;


Application* Application::instance()
{
    if  (m_applicationInstance == 0)
    {
        m_applicationInstance = new Application();
    }
    return m_applicationInstance;
}

void Application::setupApplication()
{
    if (m_needSetup)
    {
        m_coordinateSystems = CoordinateSystems::instance(this);
        m_ellipsoids = Ellipsoids::instance(this);
//        m_projects = Projects::instance(this);
    }
    m_needSetup = false;
}

Application::Application()
{

}

Application::~Application()
{

}

void Application::setMainWindow(MainWindow* mw)
{
    if (! mw == 0)
    {
        m_mainWindow = mw;
    }
}

MainWindow* Application::mainWindow() const
{
    return m_mainWindow;
}

CoordinateSystems *Application::coordinateSystems() const
{
    return m_coordinateSystems;
}

Ellipsoids* Application::ellipsoids() const
{
    return m_ellipsoids;
}

//Projects* Application::projects() const
//{
//    return m_projects;
//}

//Project* Application::activeProject() const
//{
//    return m_activeProject;
//}

