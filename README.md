# Computer Engineering Case study - Concordance of a Text
## Step 1: Problem Identification and Statement
The aim is to develop a program that processes a text file and produces a concordance. In which the
punctuation and other non-alphabetic symbols (including numbers) would be ignored. The concordance
that is the list of unique words along with their frequency of occurrence will be then stored in an output
file (for the users to access it later on) and displayed on the output screen.

## Step 2: Gathering of Information and Input/output Description
### Relevant information:
### INTRODUCTION TO CONCORDANCE
A concordance is an alphabetical list of the principal words used in a book or body of work, listing every instance of each word with its immediate context. 
Concordances have been compiled only for works of special importance, such as the Vedas, Bible, Qur'an or the works of Shakespeare, James Joyce or classical Latin and Greek authors, because of the time, difficulty,
and expense involved in creating a concordance in the pre-computer era.
Concordancing has for ages been a powerful tool in the hands of sophisticated practitioners.
Medieval monks occasionally occupied themselves with making longhand concordances of all
words in extant bibles, but more recently the rest of us have had access to computer-based tools
and electronic texts (e-texts) to accomplish the same thing in a fraction of time. But still the level
of sophistication required for concordance-based text analysis has proven daunting to the run-ofthe mill computer user.
The first Bible concordance was compiled for the Vulgate Bible by Hugh of St Cher (d.1262),
who employed 500 friars to assist him. In 1448, Rabbi Mordecai Nathan completed a
concordance to the Hebrew Bible. It took him ten years. A concordance to the Greek New
Testament was published in 1599 by Henry Stephens, and the Septuagint was done a couple of
years later by Conrad Kircher in 1602. The first concordance to the English Bible was published
in 1550 by Mr Marbeck. According to Cruden, it did not employ the verse numbers devised
by Robert Stephens in 1545, but "the pretty large concordance" of Mr Cotton did. Then
followed Cruden's Concordance and Strong's Concordance.

### TYPES OF CONCORDANCE
1. FAST CONCORDANCE 
- which means users specify a concordance of only certain words (wild cards allowed of course)
- The latter might be useful if users know what they are looking for and want to get just that with minimal use of disk space; for example, if they are trying to illustrate usage of a word quickly in a language class, or they

2. FULL CONCORDANCE
- they have the benefit of collocation data and can explore patterns in a text by experimenting with headwords.
- With a full concordance, users can sort lists of headwords so that these words suggest avenues for exploration, or they can view a text and click on words in the text which,
as long as they have done a full want to retrieve a concordance of a word they have previously explored in a corpus. concordance and have the words in the headword list, will trigger a concordance view of that word

3. BILINGUAL CONCORDANCE 
- A bilingual concordance is a concordance based on aligned parallel text.

4. TOPICAL CONCORDANCE
- A topical concordance is a list of subjects that a book covers (usually The Bible), with the immediate context of the coverage of those subjects. Unlike a traditional
concordance, the indexed word does not have to appear in the verse. The best-known topical concordance is Nave's Topical Bible.

## APPLICATIONS OF CONCORDANCE
More casual users will find Concordance to be a flexible, versatile, and easy-to-use program that
can concordance very large text files quickly, allowing them to sort the data in numerous ways
either from pull-down menus or clicks on column headings and then shifting quickly between
wordlist, concordance, and text views. The list of all words in the text can be sorted
alphabetically (descending, ascending), by frequency, length or word endings, or it can be
reduced to a subset of the complete list. Following are some applications of concordance of a
text:
1. Religious studies have always tried to count how many times a certain word is repeated
in the holy book and what can be inferred from that finding.
2. The similar application can be seen in language studies. The analysis to define the
number of use of a word helps the teachers in two ways:
- -  To decide the frequency of that word. How much a word is frequent gives sight to a
teacher in which order that word should be presented while teaching a language.
- - To see and show the learners how that word is used in the given context. This helps
learners to induce the natural order or existence of that word or collocations.
3. Learners can also be encouraged to use a concordancer, or to complete guided discovery
activities using concordances provided by the teacher, in order to encourage them to work
out rules of use for themselves.

PROGRAM BUILDING
Building this program involves many different steps, to take into consideration. First we would
require to tokenize a string into multiple words. Tokenization is the act of breaking up a sequence
of strings into pieces such as words, keywords, phrases, symbols and other elements called tokens.
Tokens can be individual words, phrases or even whole sentences. One way of doing this would
be by iterating over the text and receiving word by word and operating over these words singly
and saving them in an array.

 Second these received words should be corrected, that is the special characters and numbers
should be removed. Also for an easier operation all the uppercase characters could be changed to
lowercase to avoid complication. This can be done by using some inbuilt functions like isalpha(),
tolower() or isupper() defined in the cctype library to perform the work. Another alternating
method is by going over the word character by character and determining whether it is between az or A-Z by using the ASCII codes for this characters. If the characters turn out to be in between
A-Z we can add 32 to change it to lower case. All other characters can be then ignored.

The third step is to sort the corrected array of words. A Sorting Algorithm is used to rearrange a
given array or list elements according to a comparison operator on the elements. The comparison
operator is used to decide the new order of element in the respective data structure. The Final step
is to display the whole corrected sorted array of unique words and its frequencies to the users.

Works Cited:
- https://en.wikipedia.org/wiki/Concordance_(publishing)
- https://www.jstor.org/stable/pdf/24149475.pdf?refreqid=excelsior%3Afa7e0711b7e687d74c02a00a8
- eafd05f
- The Use of Concordancing Programs in ELT, https://core.ac.uk/download/pdf/82712036.pdf
- https://www.geeksforgeeks.org/sorting-algorithms/
- https://www.techopedia.com/definition/13698/tokenization

## Input/output Description:
The inputs are:
- The input file name
- The output file name
The outputs are:
- The request to input the filenames
- The concordance text, that includes the unique keywords and its frequency
- The message that the program has finished processing

The following explains how the program executes:
********************************************************************************
 THIS PROGRAM IS DESIGNED TO PROCESS A TEXTFILE AND PRODUCE ITS CORRESPONDING
 CONCORDANCE TEXT FILE
 ********************************************************************************
Please enter the name of the input file that should be processed
ReadFile.txt
Please enter the name of the output file in which the concordance text will be saved
ResultFile.txt
Unique Words Frequency
a 2
alphabetical 1
an 1
concordance 1
file 2
in 1
is 1
list 1
of 2
text 2
the 2
unique 1
word 1
 ********************************************************************************
 !!The concordance result file has been created!!
 !!THANK YOU!!
 ********************************************************************************

## Step 3: Design of the algorithm and hand-solved problems
#### Test Case 1:
  NYU Abu Dhabi is a research university with a fully integrated liberal arts and science college.
This is a simple test to evaluate whether the frequency of the words that is repeated is correct
and that the capitalized words should be converted to lowercase.
#### Test Case 2:
  The alarm went off at exactly 6:00 AM,as it had every morning for the past five years!
This test is mainly conducted to evaluate whether the numerical values and special characters are
ignored or not, while printing the concordance of the text.
#### Test Case 3:
  Test, Test! Test' Test. testtt&
This test is mainly conducted to evaluate whether all the special characters are ignored or not, while
printing the concordance of the text. This test is also checks the accuracy of the printed frequency of
repeating words.
#### Test Case 4:
Sample text:
  She tried not to judge him. His ratty clothes and unkempt hair made him look
  homeless. Was he really the next Einstein as she had been told? On the off chance
  it was true, she continued to try not to judge him.
  The river slowly meandered through the open space. It had hidden secrets that it
  didn't want to reveal. It had a well-planned strategy to appear calm, inviting, and
  appealing. That's how the river lured her unknowing victims to her water's edge. 
This test is to check whether this program works with actually long texts or not. As the program
is expected to show the correct results for this as well. 
