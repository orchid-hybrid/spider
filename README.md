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
* 3: Add refcounting to reclaim unused memory: ..attempted
* 

Notes:

I added refcounting in a way that isn't if-aware. Since only one branch of an if is taken this will not work correctly on any code that uses ifs. It looks complex to add that to this code.

Even code without ifs is not reclaiming all memory for some reason.
