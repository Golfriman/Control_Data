#ifndef CONST_H
#define CONST_H

enum Form{
    AUTHORIZATION = 0,
    MAIN_MENU,
    EMPLOYEE,
    ROOMS,
    CHECK_IN,
    BOOKING,
    SIGN_UP,
    REPORT,
    SETTINGS
};

enum Send{
    ONE,
    ALL
};

enum Type
{
    VIEW = 0,
    INSERT,
    UPDATE,
    DROP,
    FIND,
    CONSTANT,
    ACCEPT,
    FIND_ROOM,
    SHOW_CHECK_IN,
    CHECK_OUT_FROM,
    PAY
};

#endif // CONST_H
