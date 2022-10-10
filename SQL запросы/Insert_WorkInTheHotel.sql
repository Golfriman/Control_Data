--WorkHotel (idWork, idEmployee, idRoom, nameWork, time)

TRUNCATE TABLE WorkHotel CASCADE;

ALTER SEQUENCE WorkHotel_idWork_seq RESTART WITH 1;

INSERT INTO WorkHotel (idEmployee, idRoom, nameWork) VALUES
(8, 1, 'Уборка'),
(8, 2, 'Уборка'),
(9, 3, 'Уборка'),
(10, 4, 'Уборка'),
(11, 1, 'Уборка');