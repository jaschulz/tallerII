echo '<html><body>POST example.<form method=\"POST\" action=\"/handle_post_request\"><issue><project_id>project-01</project_id><subject>test1</subject><description>desc1</description><category_id>1</category_id></issue></form></body></html>' | \
curl -X POST -H 'Content-type: text/html' \
-H 'Accept: text/html' -d @- http://localhost:8080/handle_post_request
