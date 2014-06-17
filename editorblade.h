#ifndef EDITOR_BLADE_H
#define EDITOR_BLADE_H

#include <QFrame>
#include <QCoreApplication>
#include <QTabWidget>
#include <QTextEdit>
#include <QString>
#include <QLabel>
#include <QFile>
#include <QPropertyAnimation>
#include <QFileDialog>

class EditorBlade : public QFrame
{
    Q_OBJECT

	public:
	    EditorBlade(QWidget *parent = 0);

	    void newFile();
	    void openFile();

	    void save();
	    void saveFile();
	    void saveAs();
	    void saveAll();

	    void cut();
	    void copy();
	    void paste();

	private:
		QTabWidget *tabWidget;
 };

#endif
