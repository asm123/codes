import sys
import slate
import pprint
from wordcloud import WordCloud, STOPWORDS
import matplotlib.pyplot as plt
import re

if __name__ == "__main__":
	if len(sys.argv) < 2:
		print "Error: The utility needs at least one argument."
		sys.exit(0)
	doc = None
	with open(sys.argv[1]) as f:
		doc = slate.PDF(f)
	

	# pattern = re.compile("\x...")
	doc = re.sub(r"\\x..", " ", str(doc))
	pprint.pprint(doc)

	wordcloud = WordCloud(stopwords=STOPWORDS,
                          background_color='white',
                          width=1200,
                          height=1000).generate(str(doc).encode('utf8'))
	plt.imshow(wordcloud)
	plt.axis('off')
	plt.show()
