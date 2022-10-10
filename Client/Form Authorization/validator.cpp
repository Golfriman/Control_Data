#include "validator.h"
#include <QRegularExpression>

Validator::Validator(QObject *parent):QValidator(parent)
{

}

QValidator::State Validator::validate(QString &str, int &pos) const
{
    QRegularExpression exp = QRegularExpression("[А-я]");
    return str.contains(exp)?Invalid: Acceptable;
}
