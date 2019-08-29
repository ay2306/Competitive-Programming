import os
import nltk
import nltk.corpus
from nltk.tokenize import word_tokenize
from nltk.probability import FreqDist
from nltk.stem import LancasterStemmer
from nltk.stem import wordnet
from nltk.stem import WordNetLemmatizer
#nltk.download('punkt')
nltk.download('averaged_perceptron_tagger')
#nltk.download('stopwords')
#nltk.download('wordnet')
a = "Ayush is awesome and he rocks. Only losers do not agree. Got it biaaatch"
b = word_tokenize(a)
#print(len(b))
#fdist = FreqDist()
#for word in b:
#   fdist[word.lower()]+=1
#pst = LancasterStemmer()
##pst.stem('having')
#words = ['give', 'given', 'giving','gave']
##for i in words:
##    print(i + " : " + pst.stem(i) + "\n")
#word_lem = WordNetLemmatizer()
#word_lem.lemmatize("given")
from nltk.corpus import stopwords
#stopwords.words('english')
import re
punctuations = re.compile(r'[-.?!,:;|0-9]')
post_punctuations = []
for words in b:
    words = words.lower()
    word = punctuations.sub("",words)
    if len(word) > 0:
        post_punctuations.append(word)
print(post_punctuations)
for token in post_punctuations:
    print(nltk.pos_tag([token]))
from nltk import ne_chunk