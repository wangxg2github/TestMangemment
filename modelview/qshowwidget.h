#ifndef QSHOWWIDGET_H
#define QSHOWWIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QDebug>
#define cout qDebug() << "[" << __FILE__ ":" << __LINE__ << "] >>>"

#include "mysql/mymysql.h"

#include "qmymodel.h"
#include "QVariantListListModel.h"


namespace Ui {
class QShowWidget;
}

class QShowWidget : public QWidget
{
    Q_OBJECT

public:
    QShowWidget(QWidget *parent = 0);
    ~QShowWidget();

    void selectItem(const int index);

private slots:
    void tableUpdata(QModelIndex &index, QVariant value);
private:
    Ui::QShowWidget *ui;

    mymysql m_mysqlDB;
    QMyModel *m_myModel;

    QList< QList<QVariant> > m_datas;
    QStringList m_headerData;
};

#endif // QSHOWWIDGET_H
