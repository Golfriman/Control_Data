#include "phonevalidator.h"

PhoneValidator::PhoneValidator(QObject *parent)
    : QValidator{parent}
{

}

QValidator::State PhoneValidator::validate(QString &input, int &pos) const
{
    (void)pos;
    QRegularExpression exp = QRegularExpression("[^0-9]");
    return input.contains(exp)?Invalid:Acceptable;
}
