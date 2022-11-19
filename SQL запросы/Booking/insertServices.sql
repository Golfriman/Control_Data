	--DROP PROCEDURE showServices(TEXT, INT, INT);
--Создание временной таблицы, до бронирования. Чтобы было легче удалить бронь и ее услуги...
DROP TABLE Pre_service_booking;
CREATE TABLE Pre_service_booking
(
	idBooking INT NOT NULL CHECK(idBooking>0),
	typeservies VARCHAR(255),
	_type INT
);
CREATE OR REPLACE PROCEDURE insertServicesBooking(_data TEXT, _id INT)
AS $$
BEGIN
	DELETE FROM Pre_service_booking WHERE idBooking = _id;
	INSERT INTO Pre_service_booking SELECT _id, service.typeservice, 1
									FROM service 
									WHERE service.typeservice SIMILAR TO _data;
END; $$ LANGUAGE PLPGSQL;

--Проверка

DELETE FROM Pre_service_booking
CALL insertServicesBooking(CAST ('(Будильник|Вызов такси)' AS TEXT), 2);
SELECT * FROM livingservice;
SELECT * FROM Pre_service_booking;

