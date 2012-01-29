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

#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::notRelized()
{
    QMessageBox msgBox;
    QPixmap pix;
    msgBox.setText(tr("It is not realized in this version."));
    pix.load(":png/information_32x32.png");
    msgBox.setIconPixmap(pix);
    msgBox.setParent(this);
    msgBox.setWindowModality(Qt::WindowModal);
    msgBox.setModal(true);
    msgBox.exec();
}

void MainWindow::slotFileNew()
{
    qDebug("MainWindow::slotFileNew() called.");
    notRelized();
}

void MainWindow::slotFileOpen()
{
    qDebug("MainWindow::slotFileOpen() called.");
    notRelized();
}

void MainWindow::slotFileClose()
{
    qDebug("MainWindow::slotFileClose() called.");
    notRelized();
}

void MainWindow::slotFileSave()
{
    qDebug("MainWindow::slotFileSave() called.");
    notRelized();
}

void MainWindow::slotFileSaveAs()
{
    qDebug("MainWindow::slotFileSaveAs() called.");
    notRelized();
}

void MainWindow::slotFileSaveAll()
{
    qDebug("MainWindow::slotFileSaveAll() called.");
    notRelized();
}

void MainWindow::slotImportFromFile()
{
    qDebug("MainWindow::slotImportFromFile() called.");
    notRelized();
}

void MainWindow::slotImportTemplatePoints()
{
    qDebug("MainWindow::slotImportTemplatePoints() called.");
    notRelized();
}
