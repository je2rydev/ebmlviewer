#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "library/ebmlparser.h"
#include "library/exmlnode.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setDatainTable();
    void loadEbmlParser();

private slots:
    void on_searchBtn_clicked();

private:
    void parsingNode(EXMLNode* node);
    void setEbmlTable(EXMLDocument* doc);
    void TableWidgetDisplay();
    Ui::MainWindow *ui;
    int elementCount =  0;
//    std::vector<QString> nodeTags;
    QMap<QString, int> nodeTags;
};


#endif // MAINWINDOW_H
