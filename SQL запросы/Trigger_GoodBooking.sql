--Создал таблицу для хранения информации о результатах работы INSERT, UPDATE, потому что не смог понять как достать информацию, о том что произошло в триггере
CREATE TABLE LOG_BOOKING
( _idBooking INT PRIMARY KEY,
  _result BOOLEAN
);

CREATE OR REPLACE FUNCTION good_booking() 
RETURNS TRIGGER
AS $$
BEGIN
--как понять что занято? Это когда заселение и выселение содержится пересекается с чужими датами	
	IF EXISTS (SELECT * 
			   FROM booking
			   WHERE ((new.checkin >= checkin and new.checkin <= checkoutfrom)
			  		  or
			  		 (new.checkoutfrom >= checkin and new.checkoutfrom <= checkoutfrom))
			   		  and 
			   		  new.idroom = idroom
			  )
			   THEN
			   BEGIN
			   		INSERT INTO LOG_BOOKING VALUES (new.idbooking, FALSE);
					RETURN NULL;
				END;
	END IF;
	INSERT INTO LOG_BOOKING VALUES (new.idbooking, TRUE);
	RETURN new;
			   
END; $$ LANGUAGE PLPGSQL;

--Триггер срабатывает до того как обновить или вставить значение, потому что мы хотим проверить а занята ли вообще комната.
CREATE OR REPLACE TRIGGER good_booking 
BEFORE INSERT OR UPDATE  ON booking
FOR EACH ROW
EXECUTE PROCEDURE good_booking();

select * from booking;
