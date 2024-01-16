Checkpoint 0 Writeup
====================

My name: Mohamed Ismail

My SUNet ID: mismail1

I collaborated with: 

I would like to credit/thank these classmates for their help: arturbc, yasiny, shafink

This lab took me about [10] hours to do. I did attend the lab session.

My secret code from section 2.1 was: [226116]

I was surprised by or edified to learn that: I should start earlier on lab and go to office hours more often!

Describe ByteStream implementation. [Describe data structures and
approach taken. Describe alternative designs considered or tested.
Describe benefits and weaknesses of your design compared with
alternatives -- perhaps in terms of simplicity/complexity, risk of
bugs, asymptotic performance, empirical performance, required
implementation time and difficulty, and other factors. Include any
measurements if applicable.]

For my implementation of ByteStream I used a character vector. As I pushed and popped from my vector I edited 
variables I instantiated in my .hh file such as bytes_read, bytes_written, and isFinished_. I was not able to 
finish my implementation but I was able to locate the error in my pop funciton. I realized, far too late, that
I was popping form the back of my vector rather than the front. This was a mistake in my understanding that could
have been cleared up fairly easily if I had visited office hours. I also considered using a string instead of a 
vector once I began having my issues with pushing and popping functions. I believe that using a string might
have taken less logic and would've been less complex in both the program's time and general complexity.

- Optional: I had unexpected difficulty with: The push function. I will definitley be asking more clarifying
questions to make sure my understanding is solid in the future before beginning on assignments.

- Optional: I think you could make this lab better by: [describe]

- Optional: I'm not sure about: [describe]

- Optional: I contributed a new test case that catches a plausible bug
  not otherwise caught: [provide Pull Request URL]