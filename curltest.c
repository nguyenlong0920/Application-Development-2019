#include <stdio.h>
#include <curl/curl.h>

int main(int argc, char **argv)
{
	CURL *curl;
 	CURLcode res;
	char id[20], email[40], poststr[100];

 	if(argc<3){
		printf("Usage: %s [ID] [email]\n", argv[0]);
		return 1;	// program stops because the user has not given enough info
  	}

  	sprintf(poststr,"ID=%s&email=%s", argv[1], argv[2]);

  	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);

  	/* get a curl handle */
  	curl = curl_easy_init();
  	if(curl) {
    	/* First set the URL that is about to receive our POST. This URL can
       	just as well be a https:// URL if that is what should receive the
       	data. */
    		curl_easy_setopt(curl, CURLOPT_URL, "http://www.cc.puv.fi/~e1800946/curl.php");
    	/* Now specify the POST data */
    		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, poststr);

    	/* Perform the request, res will get the return code */
    		res = curl_easy_perform(curl);
    	/* Check for errors */
    		if(res != CURLE_OK)
      			printf("Error in curl_easy_perform().\n");
    		else
      			printf("Post data is sent\n");
    	/* always cleanup */
    		curl_easy_cleanup(curl);
  	}
  	curl_global_cleanup();
  	return 0;
}
