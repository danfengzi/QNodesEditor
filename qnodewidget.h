#ifndef QNODEWIDGET_H
#define QNODEWIDGET_H

#include <QWidget>
#include <QDragEnterEvent>
#include <qsizegrip.h>

#include "qhandle.h"
#include "qconnectorblob.h"
#include "qnodeview.h"

class qconnectorblob;
class QNodeView;

namespace Ui {
class QNodeWidget;
}

class QNodeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QNodeWidget(QWidget *parent = 0, QNodeView *view = 0,
                         QString mName = "", QPoint *myPos = 0);
    ~QNodeWidget();

    QPoint offset;
    static unsigned int mIDcounter;
    long mID;
    QString mName;

    void moveEvent(QMoveEvent *event);

    void addQConnection(qconnectorblob *newConn);
    QVector<qconnectorblob*> getConnectors();

    void updateIOText();

    QNodeView *mParentView;
    static QMap<int,QNodeWidget*> QNodeCollector;

private slots:
    void on_pushButton_pressed();

    void on_pushButton_2_pressed();

    void on_pushButton_3_pressed();

    void on_pushButton_4_pressed();

    void on_pushButton_5_pressed();

    void on_label_destroyed();

    void on_lineEdit_textChanged(const QString &arg1);

private:

    QVector<qconnectorblob*> mInConnectors;
    QVector<qconnectorblob*> mOutConnectors;

    Ui::QNodeWidget *ui;
};

#endif // QNODEWIDGET_H
