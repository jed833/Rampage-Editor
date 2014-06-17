#include <QtWidgets>

#include "mainwindow.h"
#include "editorblade.h"

MainWindow::MainWindow()
{
    editorblade = new EditorBlade;
    setCentralWidget(editorblade);
    createActions();
    createMenus();
    createStatusBar();

    setWindowTitle(tr("Rampage"));
}

void MainWindow::newFile()
{
    editorblade->newFile();
}

void MainWindow::closeEvent(QCloseEvent *event)
{

}

void MainWindow::openFile()
{
    editorblade->openFile();
}

void MainWindow::openFolder()
{
    
}

void MainWindow::save()
{
    editorblade->save();
}

void MainWindow::saveAs()
{
    editorblade->saveAs();
}

void MainWindow::saveAll()
{

}

void MainWindow::undo()
{

}

void MainWindow::cut()
{

}

void MainWindow::copy()
{
    editorblade->copy();
}

void MainWindow::paste()
{

}

void MainWindow::createActions()
{
    newFileAction = new QAction(tr("&New File"), this);
    newFileAction->setShortcut(QKeySequence::New);
    newFileAction->setStatusTip(tr("Create a new file"));
    connect(newFileAction, SIGNAL(triggered()), this, SLOT(newFile()));

    openFileAction = new QAction(tr("&Open File"), this);
    openFileAction->setShortcut(QKeySequence::Open);
    openFileAction->setStatusTip(tr("Open an existing file"));
    connect(openFileAction, SIGNAL(triggered()), this, SLOT(openFile()));

    openFolderAction = new QAction(tr("&Open Folder"), this);
    openFolderAction->setStatusTip(tr("Open an existing folder"));
    connect(openFolderAction, SIGNAL(triggered()), this, SLOT(openFolder()));

    saveAction = new QAction(tr("&Save"), this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save the file to disk"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAction = new QAction(tr("Save &As..."), this);
    saveAsAction->setStatusTip(tr("Save the file under a new name"));
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));

    saveAllAction = new QAction(tr("Save &All..."), this);
    saveAllAction->setStatusTip(tr("Save all modified files"));
    connect(saveAllAction, SIGNAL(triggered()), this, SLOT(saveAll()));

    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));


    undoAction = new QAction(tr("&Undo"), this);
    undoAction->setStatusTip(tr("Undo the last action"));
    connect(undoAction, SIGNAL(triggered()), this, SLOT(undo()));

    cutAction = new QAction(tr("Cu&t"), this);
    cutAction->setShortcut(QKeySequence::Cut);
    cutAction->setStatusTip(tr("Cut the current selection to the clipboard"));
    connect(cutAction, SIGNAL(triggered()), this, SLOT(cut()));

    copyAction = new QAction(tr("&Copy"), this);
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setStatusTip(tr("Copy the current selection to the clipboard"));
    connect(copyAction, SIGNAL(triggered()), this, SLOT(copy()));

    pasteAction = new QAction(tr("&Paste"), this);
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("Paste the clipboard's contents at the cursor position"));
    connect(pasteAction, SIGNAL(triggered()), this, SLOT(paste()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newFileAction);
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(openFolderAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addAction(saveAllAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);

    viewMenu = menuBar()->addMenu(tr("&View"));
}

void MainWindow::createStatusBar()
{
    readyLabel = new QLabel(tr(" Ready"));
    statusBar()->addWidget(readyLabel, 1);
}
