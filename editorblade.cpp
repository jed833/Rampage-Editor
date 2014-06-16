#include <QtWidgets>

#include "editorblade.h"
#include "editortab.h"

EditorBlade::EditorBlade(QWidget *parent): QFrame(parent)
{
    tabWidget = new QTabWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setSizeConstraint(QLayout::SetNoConstraint);
    mainLayout->addWidget(tabWidget);
    setLayout(mainLayout);

    addEditor();

    QFile foo("/home/guser/Developer/Rampage-Editor/in.txt");
    foo.open(QIODevice::ReadOnly | QIODevice::Text);

    QString line, text;
	QTextStream in(&foo);

    while (!in.atEnd()) 
    {
        line = in.readLine();
        text = text + line + "\n";
    }

    addEditor(text);
}

void EditorBlade::addEditor()
{
    tabWidget->addTab(new QTextEdit(), tr("file.h"));
}

void EditorBlade::addEditor(QString text)
{
    tabWidget->addTab(new QTextEdit(text), tr("file.h"));
}

void EditorBlade::cut()
{
    QTextEdit* temp = NULL;
    QWidget* widget = tabWidget->currentWidget(); // for the second tab
    temp = (QTextEdit*)widget;
    temp->cut();
}

void EditorBlade::copy()
{
    QTextEdit* temp = NULL;
    QWidget* widget = tabWidget->currentWidget(); // for the second tab
    temp = (QTextEdit*)widget;
    temp->copy();
}

void EditorBlade::paste()
{
    QTextEdit* temp = NULL;
    QWidget* widget = tabWidget->currentWidget(); // for the second tab
    temp = (QTextEdit*)widget;
    temp->paste();
}
