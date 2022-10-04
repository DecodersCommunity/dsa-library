## String Data Structure

Strings are defined as an array of characters. The difference between a character array and a string is the string is terminated with a special character ‘\0’.

Below are some examples of strings:

“geeks”, “for”, “geeks”, “GeeksforGeeks”, “Geeks for Geeks”, “123Geeks”, “@123 Geeks”

How String is represented in Memory?
In C, a string can be referred to either using a character pointer or as a character array. When strings are declared as character arrays, they are stored like other types of arrays in C. For example, if str[] is an auto variable then the string is stored in the stack segment, if it’s a global or static variable then stored in the data segment, etc.

![image](https://user-images.githubusercontent.com/114334549/193635855-9d2dd140-4271-4b9a-a923-59724cbebb87.png)


In computer programming, a string is traditionally a sequence of characters, either as a literal constant or as some kind of variable.
The latter may allow its elements to be mutated and the length changed, or it may be fixed (after creation).
A string is generally considered as a data type and is often implemented as an array data structure of bytes (or words) that stores a sequence of elements, typically characters, using some character encoding. String may also denote more general arrays or other sequence (or list) data types and structures.
Depending on the programming language and precise data type used, a variable declared to be a string may either cause storage in memory to be statically allocated for a predetermined maximum length or employ dynamic allocation to allow it to hold a variable number of elements.
When a string appears literally in source code, it is known as a string literal or an anonymous string.
In formal languages, which are used in mathematical logic and theoretical computer science, a string is a finite sequence of symbols that are chosen from a set called an alphabet.

![image](https://user-images.githubusercontent.com/113816225/193510004-61183926-4ff4-4ec4-82df-adaf4647916f.png)

