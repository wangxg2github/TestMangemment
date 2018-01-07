#include "qshowwidget.h"
#include "ui_qshowwidget.h"
#include <QTime>
#include <QDateTime>

QShowWidget::QShowWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QShowWidget)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    QTime time;
    time.start();
    //连接数据库
    if (-1 == m_mysqlDB.sql_connect("127.0.0.1", "root", "", "mydata"))
    {
        cout << "connect mysql failed!";
        return;
    }
    cout << "connect mysql successed, use time:" << time.elapsed() / 1000.0 << "s";




//example model.3
    m_myModel = new QMyModel(this);
    m_mysqlDB.sql_open("select * from teacher limit 20;", m_headerData, m_datas);
    m_myModel->setDoubleListPtr(&m_datas, m_headerData);

    ui->tableView->setModel(m_myModel);
    //隐藏某一列数据
    ui->tableView->hideColumn(0);
    //不可编辑
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

//    // 只能单选
//    //ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
//    // 以行作为选择标准
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
//    // 列头隐藏
//    ui->tableView->verticalHeader()->hide();
//    // 让列头可被点击，触发点击事件
//    ui->tableView->horizontalHeader()->setSectionsClickable(true);
//    // 去掉选中表格时，列头的文字高亮
//    ui->tableView->horizontalHeader()->setHighlightSections(false);
//    ui->tableView->horizontalHeader()->setBackgroundRole(QPalette::Background);
//    // 列头灰色
//    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(225,225,225)};");
//    //connect(ui->tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortByColumn(int)));

//    //启用右键菜单
//    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->pushBtn_remove, &QPushButton::clicked, this,
            [=]()
    {
//        QModelIndexList model_index_list = ui->tableView->selectedIndexes();
//        int model_count = model_index_list.count();
//        if(model_count <= 0)
//            return;

//        QList<QVariant> list_row;
//        for(int i = model_count - 1; i > =0; i--)
//        {
//            QModelIndex model_index = model_index_list.at(i);
//            int row = model_index.row();
//            if(!list_row.contains(row))
//                list_row.append(row);
//        }

//        if(list_row.isEmpty())
//            return;

//        //qSort(list_row);

//        for(int i=list_row.count()-1; i>=0; i--)
//        {
//            m_datas.removeAt(list_row.at(i));
//        }

//        model->refrushModel();

    });

    connect(ui->pushBtn_delete, &QPushButton::clicked, this,
            [=]()
    {
        m_myModel->removeRow(1);
    });

}

QShowWidget::~QShowWidget()
{
    delete ui;
}

void QShowWidget::selectItem(const int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}

void QShowWidget::tableUpdata(QModelIndex &index, QVariant value)
{
    int row = index.row();
    int column = index.column();

//    if (true == m_mysqlDB.isLoginMySQL)
//    {
//        m_mysqlDB.sql_exec("", )
//    }
}
