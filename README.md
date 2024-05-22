# Chatbots

In this assignment your task is to implement and test a number of different
chatbots.

Among other files, [a4.h](a4.h) includes [Chatbot.h](Chatbot.h), which has the
`Chatbot` base class your classes must inherit from. Your inheriting classes
should implement all the virtual methods in a sensible way. We want to see you
use good programming style and make good use of C++'s object-oriented
features.s


## Chatbot 1: The User

Implement a chatbot class (that inherits from `Chatbot`) called `User_bot`
that works as follows:

- It's `give_msg` method does nothing.

- It's `get_msg` method reads a string from `cin` entered by the user, and
  then returns that string.

The main purpose of `User_bot` is to let users talk with other chatbots using
a function like `converse` in [a4.cpp](a4.cpp).

It's called like this:

```cpp
User_bot user{"Stan"};
```


## Chatbot 2: Single Reply

Implement a chatbot class (that inherits from `Chatbot`) called
`Single_reply_bot` that always replies with the same string (provided in the
constructor).

```cpp
Single_reply_bot bot{"tacobot", "I love tacos!"};
```

The first string passed to the constructor is the bots name, and the second
string is the one thing it says.

Sample transcript:

```
tacobot> I love tacos!
user> All kinds?
tacobot> I love tacos!
user> What about ice cream?
tacobot> I love tacos!
```

## Chatbot 3: A Cow

Implement a chatbot class (that inherits from `Single_reply_bot`) called
`Moo_bot` that always replies with "moo". `Moo_bot` is a kind of
`Single_reply_bot`, and we want to see you implement it in a very short and
simple way by inheriting from `Single_reply_bot`.

```cpp
Moo_bot bot{"moobot"};
```

Sample transcript:

```
moobot> moo
user> Are you a cow?
moobot> moo
user> Nice to meet you.
moobot> moo
user> What else do you say?
moobot> moo
```

## Chatbot 4: Says its Name

Implement a chatbot class (that inherits from `Single_reply_bot`) called
`Name_bot` that always replies with "I am **name**", where **name** is the
name of the bot. This is a kind of `Single_reply_bot`, and we want to see you
implement it in a very short and simple way by inheriting from
`Single_reply_bot`.

```cpp
Name_bot bot{"megabot"};
```

Sample transcript:

```
megabot> I am megabot!
user> Who are you?
megabot> I am megabot!
user> I mean really. Who *are* you?
megabot> I am megabot!
user> Seriously?
megabot> I am megabot!
```

## Chatbot 5: Echoed Replies

Implement a chatbot class (that inherits from `Chatbot`) called `Echo_bot`
that always replies with the last input it recevies. If it needs to speak
before being told anything, then its reply is a special "first reply" string
that is given in its constructor as shown.

For example:

```cpp
Echo_bot bot{"repeato", "repeato is ready to go!"};
```

The name of `bot` is `repeato`, and if it is asked to speak first, it will say
the second string passed to the constructor.

Sample transcript:

```
repeato> repeato is ready to go!
user> Nice to meet you?
repeato> Nice to meet you?
user> ok
repeato> ok
user> wubba lubba dub dub!
repeato> wubba lubba dub dub!
```


## Chatbot 6: Random Replies

Implement a chatbot class (that inherits from `Chatbot`) called
`Random_reply_bot` that chooses a reply at random from a list of given
replies. It should have constructors that allow lists of replies to be read in
in at least the two following ways.

### A vector<string> of Replies

`Random_reply_bot` has a constructor that takes a `vector<string>` as its
second parameter (the first parameter is the name of the chatbot). If the
passed-in vector is empty, call `cmpt::error` in the constructor with a
helpful message.

For example:

```cpp
Random_reply_bot cat{"Mittens", {"meow", "purrr", "meeeeow"}};
```

Calling `cat.get_msg()` returns `"meow"`, `"purrr"`, or `"meeeeow"` at
random.

Sample transcript:

```
Mittens> purrr
user> Hi
Mittens> purrr
user> nice kitty
Mittens> meow
user> Do you know calclus?
Mittens> meeeeow
```

### Replies from a Text File

`Random_reply_bot` should have a constructor that has a `string`, for the name
of a file, as its second parameter (the first parameter being the name of the
chatbot). Each non-empty line of the file contains one reply. If the file
can't be opened, or if it is empty, then call `cmpt::error` in the constructor
with a helpful message.

For example, suppose the text file `dog_sounds.txt` contains this:

```
woof
ruff
yap yap yap
bow wow  
```

Then we can construct a random reply bot like this:

```cpp
Random_reply_bot dog{"Fido", "dog_sounds.txt"};
```

Calling `dog.get_msg()` returns `"woof"`, `"ruff"`, `yap yap yap`, or `"bow
wow"` at random.

**Hint**: The `getline` function in `std` may help.

Sample transcript:

```
Fido> bow wow
user> What's your name?
Fido> yap yap yap
user> Are you a good doggy?
Fido> ruff
```

## Chatbot 7: Current Time and Date

Implement a chatbot class (that inherits from `Chatbot`) called `Datetime_bot`
that replies with the current date and time just when the last string given to
it contains either "date" or "time" (or both) as a substring. If neither
"date" nor "time" appears, then the reply is a default message chosen at
random from a `vector<string>` of messages supplied in the constructor.

When checking for "date" or "time", the case should **not matter**, e.g. if
the last string told to the bot was "what's the dAtE???", then that counts as
containing "date". If "date" or "time" is embedded in another string, then it
still counts, e.g. "Give me an update?" would cause the date to be printed.

To be clear, if the last string contains *just* "date" as a substring, then
just the date should be the reply. If the last string contains *just* "time",
then just the time should be the reply. If *both* "date" and "time" appear,
then the reply should include both the date and time (the order in which you
to print the date and time in this case doesn't matter).

The **time string** should be in regular am/pm format, e.g. "8:12pm",
"7:00am", "12:02pm", or "0:05am" (5 minutes after midnight). **Careful**:
*Don't* use 24-hour format, and make sure there's a leading 0 when the minutes
value is less than 10.

The **date string** should be in the format "year-month-day". For example,
"2021-12-25" is December 25th 2021, and "1955-4-3" is April 3rd 1955.

For example:

```cpp
Datetime_bot dt_bot{"deetee", {"Ask me about the date or time!", 
                               "I know the date and time!"}};
```

Here, the first input is the bot's name, and the second is the
`vector<string>` of messages from where random replies will be chosen when
neither "date" nor "time" was in the last string told to the chatbot.

Sample transcript:

```
deetee> 8:31pm, 2021-7-9
user> What time is it?
deetee> 8:32pm
user> Don't tell me the date
deetee> 2021-7-9
user> One time I ate a date
deetee> 8:35pm, 2021-7-9
user> what thyme is it? 
deetee> I know the date and time!
```



Your `Smart_bot` should be constructed like this:

```cpp
Smart_bot smart_bot("Alan");
Smart_bot provides information on which two colors combine to produce a specific color.
```
<img width="332" alt="chatbot_colorBot" src="https://github.com/ghadeerSha/Chatbots/assets/167367841/6a3818be-2a52-46b6-a816-1b12c18f3611">





  valgrind

  - In the `LEAK SUMMARY`, `definitely lost`, `indirectly lost`, and `possibly
    lost` must all be 0.

  - The `ERROR SUMMARY` reports 0 errors.

  - It is usually okay if **still reachable** reports a non- zero number of
    bytes.




