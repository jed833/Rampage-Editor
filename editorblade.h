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

class EditorBlade : public QFrame
{
    Q_OBJECT

	public:
	    EditorBlade(QWidget *parent = 0);
	    void addEditor();
	    void addEditor(QString text);

	private:
		QTabWidget *tabWidget;
 };

#endif
