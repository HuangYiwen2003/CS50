SELECT name FROM people where id IN (SELECT person_id FROM stars WHERE movie_id in (SELECT id FROM movies WHERE title = "Toy Story"));