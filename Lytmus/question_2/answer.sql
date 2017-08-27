/* 	Write and save your SQL code in this file.
	Do not rename or move it.  */

select name, title 
from actor, movie, movie_actor 
where actor.id = movie_actor.actor_id 
	AND movie.id = movie_actor.movie_id 
order by name, title;