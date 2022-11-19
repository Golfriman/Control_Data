-- Booking (idVisitor, idRoom, checkin, checkoutfrom)
TRUNCATE TABLE BOOKING CASCADE;
--ALTER SEQUENCE Booking_idBooking_seq RESTART WITH 1;
INSERT INTO Booking (idVisitor, idRoom, checkIn, checkOutFrom, numOfPeople) VALUES
(1, 16, '27/11/2022', '30/11/2022', 3),
(4, 5, '28/11/2022', '30/11/2022', 2),
(6, 1, '29/11/2022', '30/11/2022', 1),
(7, 2, '29/11/2022', '30/11/2022', 1),
(8, 10, '29/11/2022', '30/11/2022', 2),
(10, 1, '29/11/2022', '30/11/2022', 1),
(11, 17, '30/11/2022', '30/11/2022', 3),
(14, 1, '30/11/2022', '30/11/2022', 1),
(15, 2, '07/11/2022', '10/11/2022', 1),
(16, 4, '06/11/2022', '08/11/2022', 1),
(17, 8, '06/11/2022', '08/11/2022', 2),
(19, 16, '06/11/2022', '08/11/2022', 3);

SELECT * FROM BOOKING;
SELECT deleteBooking(10);
select * from authorizationinsystem;