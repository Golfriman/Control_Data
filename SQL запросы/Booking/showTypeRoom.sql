--DROP FUNCTION showTypeRoom;
CREATE OR REPLACE FUNCTION showTypeRoom(filterView VARCHAR(255), bath BOOLEAN, air BOOLEAN, _checkIn DATE, _checkout DATE, numOfPeople INT)
RETURNS TABLE(_type TEXT, _price INT, _id INT)
AS $$
BEGIN
	RETURN QUERY SELECT room.category::TEXT, typeroom.price, MIN(room.idRoom) FROM room, typeroom 
	WHERE room.category = typeroom.category and room.viewfromthewindow LIKE filterView and typeroom.capacity = numOfPeople
		AND (bath IS NULL or typeroom.bathroom = bath) and (air IS NULL or typeroom.airconditioning = air)
		AND room.idRoom NOT IN (SELECT booking.idRoom FROM booking 
								WHERE (booking.checkin >= _checkin AND booking.checkin <= _checkout) 
								 OR 
								(booking.checkoutfrom >= _checkin AND booking.checkoutfrom <=_checkout))
	GROUP BY room.category, typeroom.price; 
END; $$ LANGUAGE PLPGSQL;
-- Бюджетная 100 10
-- Люкс 200 11
SELECT * FROM showTypeRoom('%', null, null, '2022-11-30', '2022-12-03', 1);