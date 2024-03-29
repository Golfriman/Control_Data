--Создал таблицу для хранения информации о результатах работы INSERT, UPDATE, потому что не смог понять как достать информацию, о том что произошло в триггере
DROP TABLE LOG_BOOKING;
CREATE TABLE LOG_BOOKING
( _idVisitor INT PRIMARY KEY,
  _result BOOLEAN
);

CREATE OR REPLACE FUNCTION good_booking() 
RETURNS TRIGGER
AS $$
BEGIN
	IF(new.checkIn > new.checkOutFrom or new.checkIn < current_date or new.checkOutFrom < current_date)
	THEN
	BEGIN
		INSERT INTO LOG_BOOKING VALUES (new.idvisitor, FALSE);
		RETURN NULL;
	END;
	END IF;
--как понять что занято? Это когда заселение и выселение содержится пересекается с чужими датами	
	IF EXISTS (SELECT * 
			   FROM booking
			   WHERE ((new.checkin > checkin and new.checkin < checkoutfrom)
			  		  or
			  		 (new.checkoutfrom > checkin and new.checkoutfrom < checkoutfrom))
			   		  and 
			   		  new.idroom = idroom
			  )
			   THEN
			   BEGIN
			   		INSERT INTO LOG_BOOKING VALUES (new.idvisitor, FALSE);
					RETURN NULL;
				END;
	END IF;
	INSERT INTO LOG_BOOKING VALUES (new.idvisitor, TRUE);
	RETURN new;
			   
END; $$ LANGUAGE PLPGSQL;

--Триггер срабатывает до того как обновить или вставить значение, потому что мы хотим проверить а занята ли вообще комната.
CREATE OR REPLACE TRIGGER good_booking 
BEFORE INSERT OR UPDATE  ON booking
FOR EACH ROW
EXECUTE PROCEDURE good_booking();

select * from booking;
