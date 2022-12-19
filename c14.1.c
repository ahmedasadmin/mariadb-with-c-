// c14.1.c : build MySQL database in C
#include<stdio.h>
#include<stdlib.h>
#include<my_global.h>
#include<mysql.h>

MYSQL *con;  // connection object pointer 

void error()
{
	printf("errno= %d %s\n", mysql_errno(con), mysql_error(con));
	mysql_close(con);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){

	con = mysql_init(NULL);
	if(con == NULL)
		//error();
	printf("connect to mySQL server on localhost using database cs360\n");


	if(mysql_real_connect(con, "localhost", "root", NULL, "cs360",0, NULL,0) == NULL)
	//error();

	printf("connection to server OK\n");
	
	printf("drop students table if exists \n");

	
	if(mysql_query(con, "DROP TABLE IF EXISTS students"))
		//error();
	//if(mysql_query(con, "SET FOREIGN_KEY_CHECKS=0"))
	//	printf("error\n"); 

	//mysql_query(con, "ALTER TABLE parent_table ENGINE=InnoDB");
	printf("create students tables in cs360\n");
	if(mysql_query(con, "CREATE TABLE students(Id INT  PRIMARY KEY AUTO_INCREMENT, name CHAR(20), score INT)"))

		error();
	//if(mysql_query(con, "SET FOREIGN_KEY_CHECKS=0"))
	//	printf("error\n"); 
	printf("insert student records into students table\n");
	if(mysql_query(con, "INSERT INTO students VALUES(1001, 'Baker', 50)"))
		error();
	if(mysql_query(con, "INSERT INTO students VALUES(1002,'Miller', 65)"))
		error();
	if(mysql_query(con, "INSERT INTO students VALUES(2001, 'Miller', 75)"))
		error();
	
	if(mysql_query(con, "INSERT INTO students VALUES(2002, 'Smith', 85)"))
		error();
	printf("all done\n");
	

	mysql_close(con);

}
