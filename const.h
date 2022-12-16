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
    ALL,
    ADMINS,
    ADMIN
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
    PAY,
    FIND_WORK,
    FIND_EMPLOYEE,
    FIND_EMPLOYEE_FULLNAME,
    COMPLETE_WORK,
    FILTER_ROOMS,
    CHANGE_CLEAN,
    ARCHIVE,
    ADD
};

#endif // CONST_H
