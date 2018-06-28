#include "MainWindow.h"
#include "Gui/YdarImageButton.h"

#include <QPixmap>
#include <QThread>
#include <QFile>
#include <QDir>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent)
    : GuiWidget(parent)
{
    QLabel *versions_label=new QLabel(this);
    versions_label->setText(u8"Version :1.0 By ydar95");
    versions_label->setGeometry(800,575,140,12);


    display.show();
    display.toWallpaperParent();
    display.setFragmentFromFile(":/Frag/YdarWallpaper.frag");
    mp_display_table_widget =new DisplayTableWidget(this);
    mp_display_table_widget->setGeometry(10,55,830,515);


    updateDisplayWidget("./glsl");

    connect(mp_display_table_widget,SIGNAL(cellDoubleClicked(int,int)),
            this,SLOT(slot_cell_double_clicked(int,int)));
}

MainWindow::~MainWindow()
{

}

void MainWindow::updateDisplayWidget(const QString &dir_file){
    m_file_vec.clear();
    mp_display_table_widget->clear();
    QDir dir =QDir(dir_file);
    dir.setFilter(QDir::Files);
    QFileInfoList fileList = dir.entryInfoList();
    qDebug()<<fileList.size();
    for(int i=0;i<fileList.size();i++)  /*����ÿ���ļ�*/
    {
        QFileInfo fileInfo = fileList[i]; /*��ȡÿ���ļ���Ϣ*/
        QString suffix = fileInfo.suffix(); /*��ȡ�ļ���׺��*/
        /*ɸѡ������ini�ļ�(���Ҫɸѡ������ʽ���ļ��������Ҫ�޸�tr("ini")�е��ַ�������)*/
        if(QString::compare(suffix, u8"frag", Qt::CaseInsensitive) == 0)
        {

            QString filePath = fileInfo.absoluteFilePath();/*��ȡ�ļ�����·����ȫ·��*/
            mp_display_table_widget->pushDisplayItemFromFile(filePath,fileInfo.baseName());
            m_file_vec.push_back(filePath);
        }
    }
}

void MainWindow::slot_cell_double_clicked(int row, int column){
    auto ptr=mp_display_table_widget->cellWidget(row,column);
    if(ptr!=nullptr){
        int index=row*mp_display_table_widget->columnCount()+column;
        display.stopGlsl();
        display.setFragmentFromFile(m_file_vec[index]);
        display.runGlsl();
         //dynamic_cast<DisplayTableWidget*>(ptr)->
    }
}
