#ifndef TRW_H
#define TRW_H

#include <QObject>
#include <QFile>
#include <QString>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QPushButton>
#include <QtSql/QSqlRelationalTableModel>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtWidgets/QHeaderView>
#include <QDebug>

class TRW : public QObject
{
    Q_OBJECT

private:
    quint32 totalTasks;

    QSqlRelationalTableModel SqlModel;

    QTableView tasksTable;

    QSqlQuery *query;
public:
    TRW();
    ~TRW();
    void errorEnter();

signals:
    void signalPrintTotalTasks(QString text);  //  we use this signal for update total status in QML window
                                               //  check TRW::slotPrintTotalTasks() in trw.cpp

public slots:
    void addToTasks(QString,QString,QString);
    void slotPrintTotalTasks();
    void slotShowAllTasks();

};

#endif // TRW_H
