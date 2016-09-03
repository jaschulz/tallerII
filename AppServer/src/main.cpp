#include <stdio.h>
#include <string.h>
#include "mongoose/mongoose.h"
#include <json/json.h>
#include <json/value.h>

static int handler(struct mg_connection *conn) {
  char var1[500], var2[500];

  if (strcmp(conn->uri, "/handle_post_request") == 0) {
	if(strcmp(conn->request_method, "POST") != 0) {
                // send error (we only care about HTTP GET)
                    mg_send_header(conn, "Content-Type", "text/plain");
    mg_send_data(conn, "no es POST", strlen("no es POST"));
                // return not null means we handled the request
                return 1;
            }

    // Send reply to the client, showing submitted form values.
    // POST data is in conn->content, data length is in conn->content_len
    mg_send_header(conn, "Content-Type", "text/plain");
    mg_send_data(conn, "POST ok", strlen("POST ok"));
/*
    mg_printf_data(conn,
                   "Submitted data: [%.*s]\n"
                   "Submitted data length: %d bytes\n"
                   "input_1: [%s]\n"
                   "input_2: [%s]\n",
                   conn->content_len, conn->content,
                   conn->content_len, var1, var2);
  */
} else {
    // Show HTML form.
    mg_send_data(conn, "mal la url", strlen("mal la url"));
  }
  return 1;
}

int main(void) {
  struct mg_server *server = mg_create_server(NULL);
  mg_set_option(server, "listening_port", "8080");
  mg_add_uri_handler(server, "/", handler);
  printf("Starting on port %s\n", mg_get_option(server, "listening_port"));
  for (;;) {
    mg_poll_server(server, 1000);
  }
  mg_destroy_server(&server);
  return 0;
}
