#ifndef EDITSERVICE_H
#define EDITSERVICE_H

#include <QWidget>

namespace Ui {
class EditService;
}

class EditService : public QWidget
{
    Q_OBJECT

public:
    explicit EditService(QWidget *parent = nullptr);
    ~EditService();

private slots:
    void on_pushButton_clicked();

private:
    Ui::EditService *ui;
};

#endif // EDITSERVICE_H
