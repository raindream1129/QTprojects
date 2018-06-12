#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QAxObject>
#include <QMessageBox>
#include <QtGui>
#include <QWidget>
#include <QTextStream>
#include <QSqlQuery>
#include <QSqlError>
#include "dbstr_inf.h"
#include "UdaoImp.h"
#include "DBHelper.h"
#include "common.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy-MM-dd-hh-mm");
    QString logStr = "C:\\meterstore\\";
    //QString logStr = "/meterstore/";
    sFileName = logStr + current_date + ".csv";
}

MainWindow::~MainWindow()
{

    delete ui;
}
void MainWindow::save2Excel(QStringList &number_list)
{
    //QTextCodec *codec = QTextCodec::codecForName("GBK");
    QFile logtxt(sFileName);
    if(logtxt.open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append))
    {
        QTextStream in(&logtxt);
        //in<<codec->toUnicode("表号,表精度,用户编号")<<endl;
        in<<tr("表号,表精度,用户编号")<<endl;
        for(int i=0;i<number_list.size();i++)
        {
            QString sLine = number_list.at(i) + "," + "0.01" + "," + "";
            in<<sLine<<endl;
        }
    }
    else
    {
       qDebug()<<"打开文件失败";
    }
    logtxt.close();
}

void MainWindow::save2Db(QStringList &number_list)
{
    dbstr_inf stDBSTR_INF;

    UdaoImp *AddNewMT = new UdaoImp();
    DBHelper *helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.exec("BEGIN");

    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyyMMdd");
    int timeT = current_date_time.toTime_t();   //将当前时间转为时间戳
    for(int i=0;i<number_list.size();i++)
    {
        stDBSTR_INF.clear();

        stDBSTR_INF.setMT_NUM(number_list.at(i));       //仪表编号
        stDBSTR_INF.setCST_NUM("000001");               //客户号
        stDBSTR_INF.setCST_NM("上海飞奥燃气设备有限公司"); //客户名
        stDBSTR_INF.setOPN_NUM("H1309");                //操作员号
        stDBSTR_INF.setOPN_DT(current_date);            //操作日期
        stDBSTR_INF.setMNT_NUM("");                     //维护人员编号
        stDBSTR_INF.setMNT_DT("");                      //维护日期
        stDBSTR_INF.setRCD_ST("1");                     //记录状态
        stDBSTR_INF.setTMS(timeT);                      //时间戳
        stDBSTR_INF.setABSTRACT("这是一个测试");          //摘要
        stDBSTR_INF.setRSV_FLD1("");                    //备用字段1
        stDBSTR_INF.setRSV_FLD2("");                    //备用字段2
        stDBSTR_INF.setRSV_FLD3("");                    //备用字段3
        stDBSTR_INF.setRSV_FLD4("");                    //备用字段4

        if(AddNewMT->inserterMt(stDBSTR_INF) == FAIL)
        {
            QMessageBox::warning(this,"提示","数据库异常");
        }
    }
    query.exec("COMMIT");
    helper->destoryConn();
}

void MainWindow::on_LDN_LE_returnPressed()
{
    QString sLDN = ui->LDN_LE->text();

    ui->LDN_LE->clear();
    QString text = ui->All_LDN_LE->toPlainText();
    QStringList number_list = text.split("\n");
    for(int i=0;i<number_list.size();i++)
    {
        if(sLDN == number_list.at(i))
        {
            QMessageBox::warning(this,"提示","此编号已存在");
            return;
        }
    }

    ui->All_LDN_LE->append(sLDN);
}

void MainWindow::on_OK_Btn_clicked()
{
    QString text = ui->All_LDN_LE->toPlainText();
    QStringList number_list = text.split("\n");
    save2Excel(number_list);

    save2Db(number_list);
    QMessageBox::about(this,"提示","完成");

    /*******************************************
     * 保存为excel格式
     * ***************************************/
    /*
    QString text = ui->All_LDN_LE->toPlainText();
    QStringList number_list = text.split("\n");
    QList<QVariant> allRowsData;//保存所有行数据
    QList<QVariant> Frt_row;
    Frt_row.append(QVariant("表号"));
    Frt_row.append(QVariant("表精度"));
    Frt_row.append(QVariant("用户编号"));
    allRowsData.append(QVariant(Frt_row));

    for (int i = 0; i < number_list.size(); i++)
    {
        QList<QVariant> aRowData;//保存一行数据
        aRowData.clear();
        aRowData.append(QVariant("'"+number_list.at(i)));
        aRowData.append(QVariant("0.01"));
        aRowData.append(QVariant(" "));
        allRowsData.append(QVariant(aRowData));
    }
    QAxObject *excel = new QAxObject("Excel.Application");//连接Excel控件
    excel->dynamicCall("SetVisible (bool Visible)",false);//不显示窗体
    excel->setProperty("DisplayAlerts", true);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
    QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
    workbooks->dynamicCall("Add");//新建一个工作簿
    QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
    QAxObject *worksheets = workbook->querySubObject("Sheets");//获取工作表集合
    QAxObject *worksheet = worksheets->querySubObject("Item(int)",1);//获取工作表集合的工作表1，即sheet1

    QString len = QString::number(number_list.size()+1);
    QString rg = "A1:C"+len;

    //QAxObject *range = worksheet->querySubObject("Range(const QString )", "A1:B1000");

    QAxObject *range = worksheet->querySubObject("Range(const QString )", rg);

    range->dynamicCall("SetValue(const QVariant&)",QVariant(allRowsData));//存储所有数据到 excel 中,批量操作,速度极快
    range->querySubObject("Font")->setProperty("Size", 12);//设置字号
    range->setProperty("ColumnWidth", 15);  //设置单元格列宽

    QAxObject *cell = worksheet->querySubObject("Range(QVariant, QVariant)","A1");//获取单元格
    cell = worksheet->querySubObject("Cells(int, int)", 1, 1);//等同于上一句
    //cell->dynamicCall("SetValue(const QVariant&)",QVariant(123));//存储一个 int 数据到 excel 的单元格中
    //cell->dynamicCall("SetValue(const QVariant&)",QVariant("仪表编号"));//存储一个 string 数据到 excel 的单元格中
    QString str = cell->dynamicCall("Value2()").toString();//读取单元格中的值
    cout<<"\nThe value of cell is "<<str.toStdString()<<endl;

    /*QAxObject *font = cell->querySubObject("Font");
    font->setProperty("Name", itemFont.family());  //设置单元格字体
    font->setProperty("Bold", itemFont.bold());  //设置单元格字体加粗
    font->setProperty("Size", itemFont.pixelSize());  //设置单元格字体大小
    font->setProperty("Italic",itemFont.italic());  //设置单元格字体斜体
    font->setProperty("Underline", itemFont.underline());  //设置单元格下划线
    font->setProperty("Color", item->foreground().color());  //设置单元格字体颜色
    worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 12);//调整第一行行高

    workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(sFileName));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
    workbook->dynamicCall("Close()");//关闭工作簿
    excel->dynamicCall("Quit()");//关闭excel
    delete excel;
    excel=NULL;
*/
}
