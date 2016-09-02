#Instrucciones para correr el AppServer

Dentro del directorio AppServer, tipear "cmake .". A continuacion, ejecutar "make .". Luego, "sudo make install", y finalmente correr el ejecutable creado.

Para realizar una request de post, abrir otra consola y ejecutar, por ejemplo, "echo '<issue><project_id>project-01</project_id><subject>test1</subject><description>desc1</description><category_id>1</category_id></issue>' | \
curl -X POST -H 'Content-type: text/xml' \
-H 'Accept: text/xml' -d @- http://localhost:8080".
