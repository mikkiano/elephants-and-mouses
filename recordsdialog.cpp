#include "recordsdialog.h"
#include "ui_recordsdialog.h"

recordsDialog::recordsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recordsDialog)
{
    ui->setupUi(this);
}

recordsDialog::~recordsDialog()
{
    delete ui;
}

void recordsDialog::setRecords(std::map<QString, int> records)
{
    for (auto const& pair : records){
        ui->recordsWidget->insertRow( ui->recordsWidget->rowCount() );
        ui->recordsWidget->setItem(ui->recordsWidget->rowCount() - 1, 0, new QTableWidgetItem(QString::number(pair.second)));
        ui->recordsWidget->setItem(ui->recordsWidget->rowCount() - 1, 1, new QTableWidgetItem(pair.first));
    }
}
