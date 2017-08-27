import json
import urllib
import urllib2
from collections import Counter

# TODO: Generate access token at https://developers.pinterest.com/tools/access_token/
ACCESS_TOKEN = 'ATgTJ1h8c1B1JWK9vsnJdNthKeHpFIprzEcfcSBDlTw8zAAs4AAAAAA'

#url to use API of baord
BASE_API = "https://api.pinterest.com/v1/boards/"

NLTK_STOPWORDS = ['all', 'just', 'being', 'over', 'both', 'through', 'yourselves', 'its', 'before', 'herself', 'had', 'should', 'to', 'only', 'under', 'ours', 'has', 'do', 'them', 'his', 'very', 'they', 'not', 'during', 'now', 'him', 'nor', 'did', 'this', 'she', 'each', 'further', 'where', 'few', 'because', 'doing', 'some', 'are', 'our', 'ourselves', 'out', 'what', 'for', 'while', 'does', 'above', 'between', 't', 'be', 'we', 'who', 'were', 'here', 'hers', 'by', 'on', 'about', 'of', 'against', 's', 'or', 'own', 'into', 'yourself', 'down', 'your', 'from', 'her', 'their', 'there', 'been', 'whom', 'too', 'themselves', 'was', 'until', 'more', 'himself', 'that', 'but', 'don', 'with', 'than', 'those', 'he', 'me', 'myself', 'these', 'up', 'will', 'below', 'can', 'theirs', 'my', 'and', 'then', 'is', 'am', 'it', 'an', 'as', 'itself', 'at', 'have', 'in', 'any', 'if', 'again', 'no', 'when', 'same', 'how', 'other', 'which', 'you', 'after', 'most', 'such', 'why', 'a', 'off', 'i', 'yours', 'so', 'the', 'having', 'once']

def get_request(path, params=None):
    """
    Given a path, e.g. '/v1/me/' and params, return the response in json form.
    Take a look at https://developers.pinterest.com/docs/getting-started/introduction/
    to see what endpoints the Pinterest API has available!

    You may request additional parameters by overriding the params method
    """
    if params:
        params.update({'access_token': ACCESS_TOKEN})
    else:
        params = "access_token=" + ACCESS_TOKEN
    #added the field of note to get pin description
    fields = "&fields=note"
    #added for pin url
    pins = "/pins/"
    url = "%s%s%s?%s%s" % (BASE_API, path, pins, params, fields)

    result = urllib2.urlopen(url)
    response_data = result.read()
    return json.loads(response_data)

def top_n_words(board_id, top_N):
    # TODO: Implement this!
    finalResults = ()
    #if the Number of words is not 0
    if top_N != 0:
        #get the results of search in JSON
        results = get_request(str(board_id),None)

        list = []

        #create list of words from the note section
        for pin in results['data']:
            for word in [pin['note']]:
                w = word.split()
                list.append(w)

        newList = []

        #new list, filtering the length and that is not on NLTK_STOPWORDS
        for l in list:
            for w in l:
                if len(w) > 2 and w not in NLTK_STOPWORDS:
                    newList.append(w)

        #new list with all elements in lowercase
        newList2 = [element.lower() for element in newList]

        #list of frequencies of words
        wordfreq = []
        for w in newList2:
            wordfreq.append(newList2.count(w))

        #zip the words with their frequency
        finalResults = (zip(newList2, wordfreq))
        print (finalResults)

        return set(finalResults)

    else:
        return  set(finalResults)
