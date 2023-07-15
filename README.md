An inverted index is an index data structure storing a mapping from content, such as words or numbers, to its locations in a database file, or in a document or a set of documents. The purpose of an inverted index is to allow fast full text searches, at a cost of increased processing when a document is added to the database. The inverted file may be the database file itself, rather than its index. It is the most popular data structure used in document retrieval systems, used on a large scale for example in search engines. The purpose of this project is to implement the inverted search using Hash Algorithms.

An inverted index is an index data structure storing a mapping from content, such as words or numbers, to its locations in a database file, or in a document or a set of documents. The purpose of an inverted index is to allow fast full text searches, at a cost of increased processing when a document is added to the database. The inverted file may be the database file itself, rather than its index. It is the most popular data structure used in document retrieval systems, used on a large scale for example in search engines.

Implementing this search program mainly consist two important functions.
• Indexing
• Querying.
Indexing
By Indexing, we are creating a database file which contains the index of all words. So this can
be termed as Database Creation also. All the files whose index are to be created are selected
and passed to this function. All the files are parsed and words are separated and indexed.
They are arranged in sorted order. For this a sorted Linked List or Hashing is used which will
store the words and the related file details. The index thus created is then stored in the file as
database. This file is later used in Querying. While the files are removed or added this index
file is updated

Searching
Once the Indexing is over we have the Querying or Searching. The text to be searched is
passed which is parsed into words and those words are searched in the index file. To avoid
the overhead of reading the file again, the file is converted back to a linked list or hashing
program, in which the words are searched. The information about the files which contain the
words are collected. The ones with more matches are filtered and produced as the result.

