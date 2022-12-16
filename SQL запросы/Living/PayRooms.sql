--DROP FUNCTION payRoom;
CREATE OR REPLACE FUNCTION payRoom(_id INT, idEmpl INT, _days INT)
RETURNS TEXT
AS $$
DECLARE
	_status INT:=0;
	_checkOutFrom DATE;
	_d_checkIn DATE;
	_price INT;
	_room INT;
	_number INT;
	_diff INT:=0;
	_msg TEXT;
BEGIN
	SELECT price INTO _price FROM typeroom;
	
	SELECT Booking.checkOutFrom, CheckIn.d_checkIn, Booking.idroom, checkin.numberofpaiddays 
		INTO _checkOutFrom, _d_checkIn, _room, _number 
	FROM Booking, CheckIn 
	WHERE Booking.idRoom = CheckIn.idRoom and CheckIn.idCheckIn = _id and checkin.d_checkin = booking.checkin;
	SELECT EXTRACT(DAY FROM _checkoutfrom::timestamp - _d_checkin::timestamp)::INT INTO _diff;
	IF (_days + _number > _diff) THEN 
	BEGIN
			UPDATE checkIn 
				SET numberOfPaidDays = _diff
				WHERE idCheckIn = _id;
			IF(_number - _diff <> 0 ) THEN
				_msg:= addWork(idEmpl, _room, ((_days + _number - _diff) *_price)::TEXT);
			END IF;
			RETURN 'Оплачено лишних дней ' || (_days + _number - _diff)::TEXT;
	END;
	END IF;
	
	UPDATE checkIn 
	SET numberOfPaidDays = numberOfPaidDays + _days 
	WHERE idCheckIn = _id;
	
	IF EXISTS (SELECT * FROM checkin WHERE idcheckin = _id and numberofpaiddays = _number + _days ) THEN
			_msg:= addWork(idEmpl, _room, (_days*_price)::TEXT);
			RETURN 'Успешно продлено!';	
	END IF;
	RETURN 'ЧТО-ТО ПОШЛО НЕ ПОПЛАНУ';
END; $$ LANGUAGE PLPGSQL;

SELECT booking.idRoom, booking.checkin, booking.checkoutfrom
                FROM checkin, booking WHERE booking.checkin = checkin.d_checkin and booking.idroom = checkin.idroom and idcheckin = 40;
SELECT EXTRACT(DAY FROM '2022-12-08'::timestamp-'2022-11-07'::timestamp)::INT;
SELECT * FROM booking;
delete from checkin where idcheckin = 17;
SELECT payRoom(140,2, 1)
delete from living where idcheckin =138;
delete from checkin where idcheckin = 138;
update checkin SET numberofpaiddays = 0 where idcheckin =140
select booking.checkoutfrom, booking.checkin 
from checkin, booking
where idcheckin = 140 
and booking.idroom = checkin.idroom 
and checkin.idcheckin = 140 
and checkin.d_checkin = booking.checkin;
SELECT payRoom(17,2,0);