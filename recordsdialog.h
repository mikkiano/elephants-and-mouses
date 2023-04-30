#ifndef RECORDSDIALOG_H
#define RECORDSDIALOG_H

#include <QDialog>

namespace Ui {
class recordsDialog;
}

class recordsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit recordsDialog(QWidget *parent = nullptr);
    ~recordsDialog();
    /**
     * @brief setRecords заполняет таблицу рекордами игроков
     *
     * @param map с рекордами игроков, где ключ - имя игрока, значение - рекорд
     */
    void setRecords(std::map<QString, int>);
private:
    Ui::recordsDialog *ui;
};

#endif // RECORDSDIALOG_H
