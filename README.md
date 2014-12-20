spider
======

having another go at autoref

This is supposed to work as a backend for NieA. It should be possible to compile a .niea file into a .ref file using the script in NieA and then compile that into a .cexpr (then into c with cexprs) with spider.

* t1 works
* t2 works
* t3 works
* t4 works!
* ufo0 works
* ufo1 works
* ufo2 works!
* ufo3 works
* ufo5 works
* ufo6 works
* ufo7 works
* ufo9 works
* ufo10 works!
* ufo11 works
* ufo12 works!!
* ufo13 works
* ufo14 works
* ufo15 works

Goal:

* 1: Get all tests working. DONE!
* 2: Get all UFOs working. DONE!
* 3: Add refcounting to reclaim unused memory: DONE!
* 

# Notes: #

## Things to take away from this experiment ##

* You need to handle ref-counting from the start differently for control flow operators like if (since execution paths only take one branch).
* refcounting is done by refcount.scm, that data is passed through to codegen.scm - but before that assignment-form.scm emits some of its own refcount stuff, it would be nicer if it were all done in one place.
* Infrastructure: Developed some good tools that can be re-used like sequences (sequence can be improved a tiny bit), improved the pattern matching, etc.
* Separating the compiler into small parts works well and helps a lot. It is good to save out intermediate stage files (niea => ref => cexpr => c in this case). To make this even better write scripts to do each pass including renaming (saves a very short amount of time, many many times so its worth it)
* The code is quite clear overall (assignment form got a bit complex but that wouldn't be hard to tidy up), this is because of the nice pattern matcher. It was only possible to get this far thanks to clear hackable code.
* It might help more to plan things better in advance. Spec the languages at each stage and think through each pass.
