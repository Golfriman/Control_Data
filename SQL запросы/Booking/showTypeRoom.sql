--DROP FUNCTION showTypeRoom;
CREATE OR REPLACE FUNCTION showTypeRoom(filterView VARCHAR(255), bath BOOLEAN, air BOOLEAN, _checkIn DATE, _checkout DATE, numOfPeople INT)
RETURNS TABLE(_type TEXT, _price INT, _id INT)
AS $$
BEGIN
	RETURN QUERY SELECT room.category::TEXT, typeroom.price, MIN(room.idRoom) FROM room, typeroom 
	WHERE room.category = typeroom.category and room.viewfromthewindow LIKE filterView and typeroom.capacity = numOfPeople
		AND (bath IS NULL or typeroom.bathroom = bath) and (air IS NULL or typeroom.airconditioning = air)
		AND room.idRoom NOT IN (SELECT DISTINCT booking.idRoom FROM booking 
								WHERE (_checkin BETWEEN booking.checkin and booking.checkoutfrom) 
								 OR 
								(_checkout BETWEEN booking.checkin and booking.checkoutfrom)
								OR 
								(booking.checkin <= _checkin and booking.checkoutfrom=_checkout))
	GROUP BY room.category, typeroom.price; 
END; $$ LANGUAGE PLPGSQL;
-- Бюджетная 100 10
-- Люкс 200 11

SELECT * FROM showTypeRoom('%', null, null, CURRENT_DATE, CURRENT_DATE+1, 1);

SELECT * FROM acceptBooking(1 ,55, 1, '{"Черенчикова Евдокия Данииловна","Ребенок"}', '{,}', '{,}',  '{"89568106981",""}')