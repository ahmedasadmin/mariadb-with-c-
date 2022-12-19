#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char **argv){

	MYSQL *con = mysql_init(NULL);

	if(con == NULL){
	
		fprintf(stderr, "%s\n", mysql_error(con));
		exit(EXIT_FAILURE);
	}

	if (mysql_real_connect(con, "localhost", "root", "root_password", 
				"testdb", 0, NULL, 0) == NULL)
	{
	
		fprintf(stderr, "%s\n", mysql_error(con)) ;
		mysql_close(con);
		exit(EXIT_FAILURE);
	}
/*	if(mysql_query(con, "CREATE DATABASE testdb")) {
	
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(EXIT_FAILURE);
	
	} */
	if (mysql_query(con, "DROP TABLE IF EXISTS students")) {
		
		fprintf(stderr,"%s\n", mysql_error(con)) ;
		exit(EXIT_FAILURE);
	}

	if(mysql_query(con, "CREATE TABLE students(id INT PRIMARY KEY AUTO_INCREMENT, name VARCHAR(20), score INT)"))
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		exit(EXIT_FAILURE);
	}
	mysql_close(con);
	exit(EXIT_SUCCESS);
}
