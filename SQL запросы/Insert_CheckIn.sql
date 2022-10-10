--CheckIn(idRoom, d_checkIn, d_checkOut, num)
TRUNCATE TABLE CheckIn CASCADE;
ALTER SEQUENCE CheckIn_idCheckIn_seq RESTART WITH 1;
INSERT INTO CheckIn (idRoom, d_checkIn, numberOfPaidDays) VALUES
(16, '27/06/2022', 4),
(5, '28/06/2022', 2),
(1, '29/06/2022', 1),
(2, '29/06/2022', 1),
(10, '29/06/2022', 1),
(1, '29/06/2022', 1),
(17, '30/06/2022', 1),
(1, '30/06/2022', 1),
(2, '30/06/2022', 1),
(4, '30/06/2022', 1),
(8, '01/07/2022', 2),
(16, '01/07/2022', 2);
