import requests
import unittest
import json
import uuid
import ConfigParser

class PostTest(unittest.TestCase):
	def __init__(self, *args, **kwargs):
		super(PostTest, self).__init__(*args, **kwargs)
		self.__api_base_url = "http://localhost:8080/"
		self._url_post = "handle_post_request"

	#Successful signup
	def test_1(self):
		payload = {'username':'yo'}
		r = requests.post(self.__api_base_url + self._url_post, json=payload)
		self.assertEqual(r.status_code, 200)
		#data = json.loads(r.text)
		self.assertEqual(r.text, "POST ok")

