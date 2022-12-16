#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <QValidator>

class Validator : public QValidator
{
public:
    Validator(QObject* parent = nullptr);
    virtual State validate(QString& str, int& pos)const override;
};

#endif // VALIDATOR_H
