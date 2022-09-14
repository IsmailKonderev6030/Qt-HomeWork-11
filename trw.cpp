#include "trw.h"

TRW::TRW():SqlModel{this, QSqlDatabase::addDatabase("QSQLITE")} {

    auto db = SqlModel.database();
    db.setDatabaseName("tasks.db");

    if (!db.open())
        qDebug() << "Бд не открыта" << db.lastError();

    query = new QSqlQuery(db);

    if (!query->exec("create table if not exists tasks(Name varchar no null, Date varchar no null, Progres varchar not null)")) {
        qDebug() << "Can't create employees table";
        return;
    }

    tasksTable.setModel(&SqlModel);

    SqlModel.setTable("tasks");
    SqlModel.select();

    totalTasks = tasksTable.verticalHeader()->count();

}

TRW::~TRW(){
    delete query;
}

void TRW::errorEnter(){
    QMessageBox messageError;
    messageError.setWindowTitle("Error");
    messageError.setText(tr("Enter error"));
    messageError.exec();
}

void TRW::addToTasks(QString name,QString date,QString progres){

    // Empty check
    if(name.isEmpty() || (date.isEmpty() || date.size()<10) || progres.isEmpty()) {this->errorEnter(); return;}

    if (!query->exec("insert into tasks values('"
                     +name+"','"
                     +date+"','"
                     +progres+"')")) {
        qDebug() << "Can't insert task :(";
    }

    totalTasks++;

    this->slotPrintTotalTasks(); // for update in QML window
}

void TRW::slotPrintTotalTasks(){
    emit signalPrintTotalTasks(tr("  Total Tasks:= ")+QString::number(totalTasks));
}

void TRW::slotShowAllTasks(){
    SqlModel.select();
    tasksTable.show();
}
