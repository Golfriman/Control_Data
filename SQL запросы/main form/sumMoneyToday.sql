CREATE OR REPLACE FUNCTION sumMoneyToday()
RETURNS INT
AS $$
DECLARE 
_sum INT:=0;
r VARCHAR(100);
_value INT:=0;

BEGIN
	FOR r IN
		SELECT namework FROM workhotel WHERE workhotel.time = CURRENT_DATE
	LOOP
		IF (r ~ '^[0-9]') THEN _sum:=_sum+(r::int);
		ELSE 
			BEGIN
				SELECT price INTO _value FROM service WHERE typeservice = r;
				_sum:=_sum+_value;
			END;
		END IF;
	END LOOP;
	RETURN _sum;
END; $$ LANGUAGE PLPGSQL;
SELECT summoneytoday();
select * from workhotel where namework ~ '^[0-9]'