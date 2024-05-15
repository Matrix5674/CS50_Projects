-- Keep a log of any SQL queries you execute as you solve the mystery.

--To access Crime Scene Reports
SELECT description FROM crime_scene_reports WHERE day = 28 AND month = 7 AND year = 2021 AND street = 'Humphrey Street';

--To access witness transcripts and descriptions
SELECT transcript FROM interviews WHERE day = 28 AND month = 7 AND year = 2021;

-- To find out what the id of the soonest flight out of Fiftyville is
SELECT * FROM flights WHERE day = 29 AND month = 7 AND year = 2021;

--To find out all the people who called someone for under 60 seconds and on the day of the crime
SELECT * FROM phone_calls WHERE day = 28 AND year = 2021 AND month = 7 AND duration < 60;

--To find out more details about the people taking the soonest flight out of Fiftyville
SELECT * FROM passengers JOIN people ON passengers.passport_number = people.passport_number WHERE flight_id = 36;

--To access the bakery secuirty logs of the theif leaving at the given time frame (10:15-25)
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND hour = 10 AND minute >= 15 AND minute < 25;

--To narrow down our lists of suspects by making sure they also were present at the bakery where the crime occured
SELECT * FROM people
WHERE license_plate IN
(SELECT distinct(license_plate) FROM bakery_security_logs WHERE license_plate IN
(SELECT license_plate FROM passengers JOIN people ON passengers.passport_number = people.passport_number WHERE flight_id = 36));

--To narrow down our list of remaining suspects by making sure they were also present at the ATM on the day of the crime
SELECT * FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.day = 28
AND atm_transactions.month = 7
AND atm_transactions.year = 2021
AND transaction_type = 'withdraw'
AND atm_location = 'Leggett Street';

--To find our who Bruce's accomplice was
SELECT * FROM people WHERE phone_number = '(375) 555-8161';


