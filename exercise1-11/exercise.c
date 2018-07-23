/*
 * Exercise 1-11
 * How would you test the word count program?
 *
 * A word is defined by a sequence of characters followed by a delimiter:
 * space, tab, or newline.  The word is preceded either by nothing, or a
 * delimiter.
 * Note that punctutation isn't considered, so "holy cow!" should be
 * counted correctly.
 * To test the program all possible combinations should be tested.
 * The way a word can vary is by start, length, and end.
 * 1. start can be nothing (beginning of input) or a space.
 * 2. length can be 1 to many
 * 3. end can be any sequence of blanks.
 *
 * so test data containing combinations of the above 1,2,3 should be used with
 * 1 to many numbers of words.
 */
