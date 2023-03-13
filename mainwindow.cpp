#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDir>
#include <QFile>
#include <QQueue>
//#include "library/ebmlparser.h"
#include "library/exmlnode.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadEbmlParser(){
    EXMLDocument doc;
    QString curPath = QCoreApplication::applicationDirPath();

    curPath += "/ebml.xml";
    if (EXMLDocument_load(&doc, curPath.toStdString().c_str())) {
        setEbmlTable(&doc);
    }

    return;
}
void MainWindow::parsingNode(EXMLNode* node){
    qDebug() << "node->tag : " <<node->tag;
    qDebug() << "node->inner_text : " <<node->inner_text;

    QString nodeTag = QString::fromUtf8(node->tag);

//    QList<QString> valuesList = nodeTags.keys(); // get a list of all the values
//    if(valuesList.contains(nodeTag)){
//        nodeTags[nodeTag]++;
//    }else{
//        nodeTags[nodeTag] = 1;
//    }
    /*
    // element
        add table row
    // documentation

    // enum

    // extension

    // implementation_note

    // restriction
    */
    for(int i=0; i < node->attributes.size; i++){
        EXMLAttribute attr = node->attributes.data[i];
        qDebug() << attr.key << " : " << attr.value;
    }

    qDebug() << "================================================";
    // set Data on Table
}

/*
struct _EXMLNode
{
    char* tag;
    char* inner_text;
    struct _EXMLNode* parent;
    EXMLAttributeList attributes;
    EXMLNodeList children;
};
*/

void MainWindow::setEbmlTable(EXMLDocument* doc){
    EXMLNode* node= doc->root;
    QQueue<EXMLNode*> queue;
    queue.enqueue(node);
    while(!queue.empty()){
        EXMLNode* currNode = queue.dequeue();
        parsingNode(currNode);
        for(int i=0; i < currNode->children.size ; i++){
            EXMLNode* node = EXMLNodeList_at(&currNode->children, i);
            queue.enqueue(node);
        }
    }

    QMap<QString, int>::iterator itr;
    for (itr = nodeTags.begin(); itr != nodeTags.end(); ++itr) {
        qDebug() << "Key : "<<itr.key();
        qDebug() << "Value : "<<itr.value();
    }
}

void MainWindow::TableWidgetDisplay()
{
    QTableWidget *table = new QTableWidget(this);
    /*
     * table->setRowCount(4);
     * table->setColumnCount(4);
     * this->setCentralWidget(table);
     * QStringList hLabels;
     * hLabels << "Name" << "Surname" << "Age" << "Address";
     * table->setHorizontablHeaderLabels(hLabels);
     *
     */

    //https://www.youtube.com/watch?v=SbDufd4Ug-M


}

void MainWindow::setDatainTable()
{
    // ui->tableVie
    /*
     * EBMLSchema xmlns ~~~ docType ~~~~ version ~~~~
     * element : name, path, id, type, range, default, minOccurs, maxOccurs, unknownsizeallowed
     *   -> document : explaination.
     *   -> extension : type, webm, cppname, keep
     *   -> restriction
     *      -> enum : value, label
     *          -> documentation
     *
     *
     *
    */
}


void MainWindow::on_searchBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "",
                "All files (*.*);; XML File (*.xml)"
                );
    QMessageBox::information(this, tr("File Name"), filename);

    setDatainTable();

}

