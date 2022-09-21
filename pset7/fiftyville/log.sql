-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports WHERE month = 7 AND day = 28 AND year = 2021 AND street = "Humphrey Street";

SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%thief%";

SELECT * FROM flights WHERE origin_airport_id = 8 AND year = 2021 AND month = 7 AND day = 29;

-- 8:20

SELECT passport_number FROM passengers WHERE flight_id = 36;

SELECT name FROM people where passport_number in (SELECT passport_number FROM passengers WHERE flight_id = 36);

+--------+
|  name  |
+--------+
| Kenny  |
| Sofia  |
| Taylor |
| Luca   |
| Kelsey |
| Edward |
| Bruce  |
| Doris  |
+--------+

SELECT name FROM people WHERE phone_number in (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60);

SELECT name FROM people WHERE license_plate in (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <=25 AND activity = "exit");
+---------+
|  name   |
+---------+
| Sofia   |
| Luca    |
| Kelsey  |
| Bruce   |
+---------+
SELECT name FROM people WHERE id in (SELECT person_id FROM bank_accounts WHERE account_number in (SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw"));
+---------+
|  name   |
+---------+
| Bruce   |
+---------+

SELECT * FROM flights WHERE id = 36;

