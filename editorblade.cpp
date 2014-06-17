#include <QtWidgets>

#include "editorblade.h"

EditorBlade::EditorBlade(QWidget *parent): QFrame(parent)
{
    tabWidget = new QTabWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setSizeConstraint(QLayout::SetNoConstraint);
    mainLayout->addWidget(tabWidget);
    setLayout(mainLayout);

    newFile();

    QFile foo("/home/guser/Developer/Rampage-Editor/in.txt");
    foo.open(QIODevice::ReadOnly | QIODevice::Text);

    QString line, text;
	QTextStream in(&foo);

    while (!in.atEnd()) 
    {
        line = in.readLine();
        text = text + line + "\n";
    }

    openFile();
}

void EditorBlade::newFile()
{
    tabWidget->addTab(new QTextEdit(), tr("untitled"));
}

void EditorBlade::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open"), ".");

    if (fileName.isEmpty())
    {
        return;
    }
    else
    {
        // read file into string
    }

    // replace fileName with string from above
    tabWidget->addTab(new QTextEdit(fileName), fileName);

    QTextEdit* temp = NULL;
    QWidget* widget = tabWidget->widget(tabWidget->count() -1);
    temp = (QTextEdit*)widget;
    temp->setDocumentTitle(fileName);
}

void EditorBlade::save()
{
    QTextEdit* temp = NULL;
    QWidget* widget = tabWidget->currentWidget(); // for the second tab
    temp = (QTextEdit*)widget;

    if (temp->documentTitle() == "")
    {
        printf("untitled\n");
        saveAs();
    }
    else
    {
        printf("titled\n");
        saveFile();
    }
}

void EditorBlade::saveFile()
{
    QTextEdit* temp = NULL;
    QWidget* widget = tabWidget->currentWidget(); // for the second tab
    temp = (QTextEdit*)widget;
    
}

void EditorBlade::saveAs()
{
    QTextEdit* temp = NULL;
    QWidget* widget = tabWidget->currentWidget(); // for the second tab
    temp = (QTextEdit*)widget;

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open"), ".");

    if (fileName.isEmpty())
    {
        return;
    }
    else
    {
        // write editor to file
    }
}

void EditorBlade::saveAll()
{
    
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
