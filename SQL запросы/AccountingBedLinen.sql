CREATE TABLE AccountingBedLinen
(
	status TEXT,
	pillowcases INT CHECK(pillowcases >=0) DEFAULT 0 NOT NULL,
	bedsheet INT CHECK(bedsheet >=0) DEFAULT 0 NOT NULL,
	duvetCover INT CHECK(duvetCover >=0) DEFAULT 0 NOT NULL,
	towel INT CHECK(towel >=0) DEFAULT 0 NOT NULL,
);

INSERT INTO AccountingBedLinen (status, pillowcases, bedsheet, duvetCover, towel)
VALUES
('Всего', 100, 100, 100, 100),
('Доступно', 100, 100, 100, 100),
('Стирка', 0, 0, 0, 0),
('Испорчено', 0, 0, 0, 0);

SELECT * FROM accountingBedLinen;
