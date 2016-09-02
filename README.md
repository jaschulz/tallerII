#Instrucciones para correr el AppServer

Dentro del directorio AppServer, tipear "cmake .". A continuacion, ejecutar "make .". Luego, "sudo make install", y finalmente correr el ejecutable creado.

Para realizar una request de post, abrir otra consola y ejecutar, por ejemplo, "echo 'request' | \
curl -X POST -H 'Content-type: text/xml' \
-H 'Accept: text/xml' -d @- http://localhost:8080". 

El Server devolverá el formato que espera, en caso de que no sea el esperado.

También hay un arhivo bash de pueba. Luego de abrir el Server en una consola, abrir otra consola, pararse sobre /AppServer, y ejecutar "sh prueba.sh". 
