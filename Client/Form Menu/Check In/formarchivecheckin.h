#ifndef FORMARCHIVECHECKIN_H
#define FORMARCHIVECHECKIN_H

#include <QWidget>
#include <QStringList>
#include <QStringListModel>

namespace Ui {
class FormArchiveCheckIn;
}

class FormArchiveCheckIn : public QWidget
{
    Q_OBJECT

public:
    explicit FormArchiveCheckIn(QWidget *parent = nullptr);
    ~FormArchiveCheckIn();
public slots:
    void slotGetData(QDataStream& in);
signals:
    void signalArchive(const QByteArray&);

private slots:
    void on_pushButton_clicked();

private:
    Ui::FormArchiveCheckIn *ui;
    QStringList list;
    QStringListModel model;
};

#endif // FORMARCHIVECHECKIN_H
