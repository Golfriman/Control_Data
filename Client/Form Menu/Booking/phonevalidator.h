#ifndef PHONEVALIDATOR_H
#define PHONEVALIDATOR_H

#include <QValidator>

class PhoneValidator : public QValidator
{
    Q_OBJECT
public:
    explicit PhoneValidator(QObject *parent = nullptr);
    QValidator::State validate(QString& input, int& pos)const override;
};

#endif // PHONEVALIDATOR_H
