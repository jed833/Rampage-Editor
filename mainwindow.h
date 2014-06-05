#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QLabel;
class QMdiArea;
class QMenu;
class QToolBar;
class Editor;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow();

    public slots:
        void newFile();

    protected:
        void closeEvent(QCloseEvent *event);

    private slots:
        void openFile();
        void openFolder();
        void save();
        void saveAs();
        void saveAll();

        void undo();
        void cut();
        void copy();
        void paste();

    private:
        void createActions();
        void createMenus();

        QLabel *readyLabel;

        QMenu *fileMenu;
        QMenu *editMenu;
        QMenu *viewMenu;

        QAction *newFileAction;
        QAction *openFileAction;
        QAction *openFolderAction;
        QAction *saveAction;
        QAction *saveAsAction;
        QAction *saveAllAction;
        QAction *exitAction;

        QAction *undoAction;
        QAction *cutAction;
        QAction *copyAction;
        QAction *pasteAction;
};

#endif
